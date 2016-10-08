#ifndef PROTO_H
#define PROTO_H
#include <glib.h>
#include "define.h"
/** Each proto_tree, proto_item is one of these. */
typedef struct proto_node {
//	struct _proto_node *first_child;
//	struct _proto_node *last_child;
//	struct _proto_node *next;
//	struct _proto_node *parent;
//	field_info  *finfo;
//	tree_data_t *tree_data;
} proto_tree;

/** A protocol tree element. */
//typedef proto_node proto_tree;
/** A protocol item element. */
typedef proto_node proto_item;



/* Structure for information about a protocol */
struct _protocol {
    const char *name;         /* long description */
    const char *short_name;   /* short description */
    const char *filter_name;  /* name of this protocol in filters */
    GPtrArray  *fields;       /* fields for this protocol */
    int         proto_id;     /* field ID for this protocol */
    gboolean    is_enabled;   /* TRUE if protocol is enabled */
    gboolean    can_toggle;   /* TRUE if is_enabled can be changed */
    GList      *heur_list;    /* Heuristic dissectors associated with this protocol */
};
/** Structure for information about a protocol */
typedef struct _protocol protocol_t;




extern void proto_init();
extern
protocol_t *
find_protocol_by_id(const int proto_id);





extern
int proto_register_protocol(const char *name,\
                            const char *short_name,\
                            const char *filter_name);

extern void
proto_register_field_array(const int parent, \
                           hf_register_info *hf, \
                           const int num_records);

extern void
proto_register_subtree_array(gint *const *indices, const int num_indices);
#endif // PROTO_H
