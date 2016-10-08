#ifndef PACKET_H
#define PACKET_H
#include "column-info.h"
#include "frame_data.h"
#include "tvbuff.h"
#include "epan_dissect.h"
#include "wtap_pkthdr.h"


/* Structure passed to the frame dissector */
typedef struct frame_data_s
{
    int file_type_subtype;
    const gchar  *pkt_comment; /**< NULL if not available */
} frame_data_t;



extern
void dissect_record(epan_dissect *edt,\
                    int file_type_subtype,\
                    wtap_pkthdr *phdr,\
                    tvbuff_t *tvb,\
                    frame_data *fd,\
                    column_info *cinfo);


/*
 * Dissector that returns nothing.
 */
typedef void (*dissector_t)(tvbuff_t *, packet_info *, proto_tree *);
/*
 * Dissector that returns:
 *
 *	The amount of data in the protocol's PDU, if it was able to
 *	dissect all the data;
 *
 *	0, if the tvbuff doesn't contain a PDU for that protocol;
 *
 *	The negative of the amount of additional data needed, if
 *	we need more data (e.g., from subsequent TCP segments) to
 *	dissect the entire PDU.
 */
typedef int (*new_dissector_t)(tvbuff_t *, packet_info *, proto_tree *, void *);
/*
 * A dissector handle.
 */
struct dissector_handle {
    const char	*name;		/* dissector name */
    gboolean	is_new;		/* TRUE if new-style dissector */
    union {
        dissector_t	old;
        new_dissector_t	new_d;
    } dissector;
    protocol_t	*protocol;
};

typedef struct dissector_handle *dissector_handle_t;

/*Register a dissector by name.*/
extern
dissector_handle_t register_dissector(const char *name, dissector_t dissector, const int proto);

/** Register a new dissector. */
extern
dissector_handle_t new_register_dissector(const char *name, new_dissector_t dissector, const int proto);

extern void packet_init(void);
extern void packet_cache_proto_handles(void);
extern void packet_cleanup(void);

/** Find a dissector by name. */
extern dissector_handle_t find_dissector(const char *name);

extern int call_dissector_with_data(dissector_handle_t handle, tvbuff_t *tvb,
    packet_info *pinfo, proto_tree *tree, void *data);

extern int call_dissector_only(dissector_handle_t handle, tvbuff_t *tvb,
    packet_info *pinfo, proto_tree *tree, void *data);

#endif // PACKET_H
