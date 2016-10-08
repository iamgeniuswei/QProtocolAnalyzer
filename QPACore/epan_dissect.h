#ifndef EPAN_DISSECT_H
#define EPAN_DISSECT_H
#include "tvbuff.h"
#include "proto.h"
#include "packet_info.h"
/* Dissection of a single byte array. Holds tvbuff info as
 * well as proto_tree info. As long as the epan_dissect_t for a byte
 * array is in existence, you must not free or move that byte array,
 * as the structures that the epan_dissect_t contains might have pointers
 * to addresses in your byte array.
 */
struct epan_dissect {
    struct epan_session *session;
    tvbuff_t	*tvb;
    proto_tree	*tree;
    packet_info	pi;
};

typedef struct epan_dissect epan_dissect_t;


#endif // EPAN_DISSECT_H
