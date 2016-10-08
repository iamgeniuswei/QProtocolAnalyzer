#include "proto.h"
#include "define.h"
#include <QDebug>
#define PRE_ALLOC_EXPERT_FIELDS_MEM 5000
#define PROTO_PRE_ALLOC_HF_FIELDS_MEM (170000+PRE_ALLOC_EXPERT_FIELDS_MEM)
/* Name hashtables for fast detection of duplicate names */
static GHashTable* proto_names        = NULL;
static GHashTable* proto_short_names  = NULL;
static GHashTable* proto_filter_names = NULL;
/* List of all protocols */
static GList *protocols = NULL;

/* List which stores protocols and fields that have been registered */
typedef struct _gpa_hfinfo_t {
    guint32             len;
    guint32             allocated_len;
    header_field_info **hfi;
} gpa_hfinfo_t;

static gpa_hfinfo_t gpa_hfinfo;
guint
wrs_str_hash(gconstpointer v)
{
    /* 31 bit hash function */
    const signed char *p = (const signed char *)v;
    guint32 h = *p;
    if (h)
        for (p += 1; *p != '\0'; p++)
            h = (h << 5) - h + *p;
    return h;
}


static int
proto_register_field_init(header_field_info *hfinfo, const int parent)
{
    hfinfo->parent = parent;
    hfinfo->same_name_next = NULL;
    hfinfo->same_name_prev_id = -1;


    if(gpa_hfinfo.len >= gpa_hfinfo.allocated_len)
    {
        if(!gpa_hfinfo.hfi)
        {
            gpa_hfinfo.allocated_len = PROTO_PRE_ALLOC_HF_FIELDS_MEM;
                        gpa_hfinfo.hfi = (header_field_info **)g_malloc(sizeof(header_field_info *)*PROTO_PRE_ALLOC_HF_FIELDS_MEM);
        }
        else
        {
            gpa_hfinfo.allocated_len += 1000;
            gpa_hfinfo.hfi = (header_field_info **)g_realloc(gpa_hfinfo.hfi,
                                                             sizeof(header_field_info *)*gpa_hfinfo.allocated_len);
        }
    }
    gpa_hfinfo.hfi[gpa_hfinfo.len] = hfinfo;
    gpa_hfinfo.len++;
    hfinfo->id = gpa_hfinfo.len - 1;
    return hfinfo->id;


}



int proto_register_protocol(const char *name, const char *short_name, const char *filter_name)
{
    protocol_t *protocol;
    const protocol_t *existing_protocol = NULL;
    header_field_info *hfinfo;
    int proto_id;
    const char *existing_name = NULL;
    gint *key;
    guint i;
    gchar c;
    gboolean found_invalid = FALSE;

    key = (gint *) g_malloc(sizeof(int));
    *key = wrs_str_hash(name);
    existing_name = (const char*)g_hash_table_lookup(proto_names, key);
    if(existing_name != NULL)
    {
        qDebug() << "Duplicate protocol name";
        return -1;
    }
    g_hash_table_insert(proto_names, key, (gpointer)name);
    existing_protocol = (const protocol_t*)g_hash_table_lookup(proto_short_names, (gpointer)short_name);
    if(existing_protocol != NULL)
    {
        qDebug() << "Duplicate protocol short_name";
        return -1;
    }
    for (i = 0; filter_name[i]; i++) {
        c = filter_name[i];
        if (!(g_ascii_islower(c) || g_ascii_isdigit(c) || c == '-' || c == '_' || c == '.')) {
            found_invalid = TRUE;
        }
    }
    if(found_invalid)
    {
        qDebug() << "filter name has invalid characters";
        return -1;
    }
    existing_protocol = (const protocol_t*)g_hash_table_lookup(proto_filter_names, (gpointer)filter_name);
    if(existing_protocol != NULL)
    {
        qDebug() << "Duplicate protocol short_name";
        return -1;
    }
    protocol = g_new(protocol_t, 1);
    protocol->name = name;
    protocol->short_name = short_name;
    protocol->filter_name = filter_name;
    protocol->fields = g_ptr_array_new();
    protocol->is_enabled = TRUE;
    protocol->can_toggle = TRUE;
    protocol->heur_list = NULL;
    protocols = g_list_prepend(protocols, protocol);
    g_hash_table_insert(proto_filter_names, (gpointer)filter_name, protocol);
    g_hash_table_insert(proto_short_names, (gpointer)short_name, protocol);

    /* Here we allocate a new header_field_info struct */
    hfinfo = g_slice_new(header_field_info);
    hfinfo->name = name;
    hfinfo->abbrev = filter_name;
    hfinfo->type = FT_PROTOCOL;
    hfinfo->display = BASE_NONE;
    hfinfo->strings = protocol;
    hfinfo->bitmask = 0;
    hfinfo->ref_type = HF_REF_TYPE_NONE;
    hfinfo->blurb = NULL;
    hfinfo->parent = -1; /* this field differentiates protos and fields */
    proto_id = proto_register_field_init(hfinfo, hfinfo->parent);
    protocol->proto_id = proto_id;
    return proto_id;
}


static int
proto_register_field_common(protocol_t *proto, header_field_info *hfi, const int parent)
{
    if (proto != NULL) {
        g_ptr_array_add(proto->fields, hfi);
    }


    return proto_register_field_init(hfi, parent);
}


void proto_register_field_array(const int parent, hf_register_info *hf, const int num_records)
{
    hf_register_info *ptr = hf;
    protocol_t *proto;
    int i;

    proto = find_protocol_by_id(parent);
    for(i = 0; i < num_records; i++, ptr++)
    {
        if(*ptr->p_id != -1 && *ptr->p_id != 0)
            return;
        *ptr->p_id = proto_register_field_common(proto, &ptr->hfinfo, parent);
    }

}

void proto_init()
{
    proto_names        = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, NULL);
    proto_short_names  = g_hash_table_new(wrs_str_hash, g_str_equal);
    proto_filter_names = g_hash_table_new(wrs_str_hash, g_str_equal);
    gpa_hfinfo.len           = 0;
    gpa_hfinfo.allocated_len = 0;
    gpa_hfinfo.hfi           = NULL;
}

protocol_t *find_protocol_by_id(const int proto_id)
{
    header_field_info *hfinfo;

    if (proto_id < 0)
        return NULL;

//	PROTO_REGISTRAR_GET_NTH(proto_id, hfinfo);
//	DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_PROTOCOL);
    hfinfo = gpa_hfinfo.hfi[proto_id];
    return (protocol_t *)hfinfo->strings;
}

void proto_register_subtree_array(gint * const *indices, const int num_indices)
{

}
