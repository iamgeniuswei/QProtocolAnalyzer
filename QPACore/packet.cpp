#include "packet.h"

/*
 * List of registered dissectors.
 */
static GHashTable *registered_dissectors = NULL;

static GHashTable *dissector_tables = NULL;

static gint proto_malformed = -1;
static dissector_handle_t frame_handle = NULL;
static dissector_handle_t file_handle = NULL;
static dissector_handle_t data_handle = NULL;


/*
 * A dissector table.
 *
 * "hash_table" is a hash table, indexed by port number, supplying
 * a "struct dtbl_entry"; it records what dissector is assigned to
 * that uint or string value in that table.
 *
 * "dissector_handles" is a list of all dissectors that *could* be
 * used in that table; not all of them are necessarily in the table,
 * as they may be for protocols that don't have a fixed uint value,
 * e.g. for TCP or UDP port number tables and protocols with no fixed
 * port number.
 *
 * "ui_name" is the name the dissector table has in the user interface.
 *
 * "type" is a field type giving the width of the uint value for that
 * dissector table, if it's a uint dissector table.
 *
 * "param" is the base in which to display the uint value for that
 * dissector table, if it's a uint dissector table, or if it's a string
 * table, TRUE/FALSE to indicate case-insensitive or not.
 */
struct dissector_table {
    GHashTable	*hash_table;
    GSList		*dissector_handles;
    const char	*ui_name;
    ftenum_t	type;
    int		param;
    GHashFunc hash_func;
};
/*
 * List of registered dissectors.
 */
//static GHashTable *registered_dissectors = NULL;

void dissect_record(epan_dissect *edt, int file_type_subtype, std::shared_ptr<wtap_pkthdr> phdr, tvbuff_t *tvb, std::shared_ptr<frame_data> fd, column_info *cinfo)
{
    const char *volatile record_type;
    frame_data_t frame_dissector_data;
    record_type = "Frame";
//    switch (phdr->rec_type) {

//    case REC_TYPE_PACKET:
//        record_type = "Frame";
//        break;

//    case REC_TYPE_FT_SPECIFIC_EVENT:
//        record_type = "Event";
//        break;

//    case REC_TYPE_FT_SPECIFIC_REPORT:
//        record_type = "Report";
//        break;

//    default:
//        /*
//         * XXX - if we add record types that shouldn't be
//         * dissected and displayed, but that need to at
//         * least be processed somewhere, we need to somehow
//         * indicate that to our caller.
//         */
//        g_assert_not_reached();
//        break;
//    }

//    edt->pi.epan = edt->session;
    /* edt->pi.pool created in epan_dissect_init() */
//    edt->pi.current_proto = "<Missing Protocol Name>";
//    edt->pi.cinfo = cinfo;
//    edt->pi.fd    = fd;
//    edt->pi.phdr  = phdr;
//    //        edt->pi.pseudo_header = &phdr->pseudo_header;
//    edt->pi.dl_src.type   = AT_NONE;
//    edt->pi.dl_dst.type   = AT_NONE;
//    edt->pi.net_src.type  = AT_NONE;
//    edt->pi.net_dst.type  = AT_NONE;
//    edt->pi.src.type = AT_NONE;
//    edt->pi.dst.type = AT_NONE;
//    edt->pi.ctype = CT_NONE;
//    edt->pi.noreassembly_reason = "";
//    edt->pi.ptype = PT_NONE;
//    edt->pi.p2p_dir = P2P_DIR_UNKNOWN;
//    edt->pi.link_dir = LINK_DIR_UNKNOWN;
//    edt->pi.layers = wmem_list_new(edt->pi.pool);
//    edt->tvb = tvb;
    call_dissector_with_data(frame_handle, tvb, nullptr, nullptr, nullptr);
}

dissector_handle_t new_register_dissector(const char *name, new_dissector_t dissector, const int proto)
{
    dissector_handle *handle;
    g_assert(g_hash_table_lookup(registered_dissectors, name) == NULL);
    handle = new dissector_handle;
    handle->name = name;
    handle->is_new = TRUE;
    handle->dissector.new_d = dissector;
    handle->protocol = find_protocol_by_id(proto);

    g_hash_table_insert(registered_dissectors,\
                        (gpointer)name,\
                        (gpointer)handle);
    return handle;
}


static void
destroy_dissector_table(void *data)
{
    struct dissector_table *table = (struct dissector_table *)data;

    g_hash_table_destroy(table->hash_table);
    g_slist_free(table->dissector_handles);
    g_slice_free(struct dissector_table, data);
}

void packet_init()
{
    dissector_tables = g_hash_table_new_full(g_str_hash, g_str_equal,
            NULL, destroy_dissector_table);

    registered_dissectors = g_hash_table_new_full(g_str_hash, g_str_equal,
            NULL, NULL);
}

void packet_cache_proto_handles()
{
    frame_handle = find_dissector("frame");
    g_assert(frame_handle != NULL);

//    file_handle = find_dissector("file");
//    g_assert(file_handle != NULL);

//    data_handle = find_dissector("data");
//    g_assert(data_handle != NULL);

//    proto_malformed = proto_get_id_by_filter_name("_ws.malformed");
//    g_assert(proto_malformed != -1);
}

dissector_handle_t find_dissector(const char *name)
{
    return (dissector_handle_t)g_hash_table_lookup(registered_dissectors, name);
}

gboolean
proto_is_protocol_enabled(const protocol_t *protocol)
{
    return protocol->is_enabled;
}

const char *
proto_get_protocol_short_name(const protocol_t *protocol)
{
    if (protocol == NULL)
        return "(none)";
    return protocol->short_name;
}

int
proto_get_id(const protocol_t *protocol)
{
    return protocol->proto_id;
}

static int
call_dissector_through_handle(dissector_handle_t handle, tvbuff_t *tvb,
                  packet_info *pinfo, proto_tree *tree, void *data)
{
    const char *saved_proto;
    int         len;

//    saved_proto = pinfo->current_proto;

//    if (handle->protocol != NULL) {
//        pinfo->current_proto =
//            proto_get_protocol_short_name(handle->protocol);
//    }

    if (handle->is_new) {
        len = (*handle->dissector.new_d)(tvb, pinfo, tree, data);
    } else {
        (*handle->dissector.old)(tvb, pinfo, tree);
//        len = tvb_captured_length(tvb);
        len = tvb->length;
        if (len == 0) {
            /*
             * XXX - a tvbuff can have 0 bytes of data in
             * it, so we have to make sure we don't return
             * 0.
             */
            len = 1;
        }
    }

//    pinfo->current_proto = saved_proto;

    return len;
}



static int
call_dissector_work(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo_arg,
            proto_tree *tree, gboolean add_proto_name, void *data)
{
    packet_info *pinfo = pinfo_arg;
    const char  *saved_proto;
    guint16      saved_can_desegment;
    int          len;
    guint        saved_layers_len = 0;

    if (handle->protocol != NULL &&
        !proto_is_protocol_enabled(handle->protocol)) {
        /*
         * The protocol isn't enabled.
         */
        return 0;
    }
    //FIXME:

//    saved_proto = pinfo->current_proto;
//    saved_can_desegment = pinfo->can_desegment;
//    saved_layers_len = wmem_list_count(pinfo->layers);

    /*
     * can_desegment is set to 2 by anyone which offers the
     * desegmentation api/service.
     * Then everytime a subdissector is called it is decremented
     * by one.
     * Thus only the subdissector immediately on top of whoever
     * offers this service can use it.
     * We save the current value of "can_desegment" for the
     * benefit of TCP proxying dissectors such as SOCKS, so they
     * can restore it and allow the dissectors they call to use
     * the desegmentation service.
     */
//    pinfo->saved_can_desegment = saved_can_desegment;
//    pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
    if (handle->protocol != NULL) {
//        pinfo->current_proto =
//            proto_get_protocol_short_name(handle->protocol);

        /*
         * Add the protocol name to the layers
         * if not told not to. Asn2wrs generated dissectors may be added multiple times otherwise.
         */
//        if (add_proto_name) {
//            pinfo->curr_layer_num++;
//            wmem_list_append(pinfo->layers, GINT_TO_POINTER(proto_get_id(handle->protocol)));
//        }
    }

//    if (/*pinfo->flags.in_error_pkt*/) {
////        len = call_dissector_work_error(handle, tvb, pinfo, tree, data);
//    } else {
        /*
         * Just call the subdissector.
         */
        len = call_dissector_through_handle(handle, tvb, pinfo, tree, data);
//    }
//    if (len == 0) {
//        /*
//         * That dissector didn't accept the packet, so
//         * remove its protocol's name from the list
//         * of protocols.
//         */
//        while (wmem_list_count(pinfo->layers) > saved_layers_len) {
//            wmem_list_remove_frame(pinfo->layers, wmem_list_tail(pinfo->layers));
//        }
//    }
//    pinfo->current_proto = saved_proto;
//    pinfo->can_desegment = saved_can_desegment;
    return len;
}




int call_dissector_with_data(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
    int ret;
    ret = call_dissector_only(handle, tvb, pinfo, tree, data);
}

int call_dissector_only(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
    int ret;

    g_assert(handle != NULL);
    ret = call_dissector_work(handle, tvb, pinfo, tree, TRUE, data);
    return ret;
}
