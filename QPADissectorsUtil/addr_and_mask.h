#ifndef ADDR_AND_MASK_H
#define ADDR_AND_MASK_H
#include "tvbuff.h"

/*
 * These routines return PREFIX_LEN_OK on success, PREFIX_LEN_TOO_LONG if
 * the prefix length is too long, and PREFIX_LEN_ZERO if the prefix length
 * is 0.
 */

#define PREFIX_LEN_OK		0
#define PREFIX_LEN_TOO_LONG	1
#define PREFIX_LEN_ZERO		2

extern int ipv4_addr_and_mask(tvbuff_t *tvb, int offset, guint8 *addr,
    guint32 prefix_len);

extern int ipv6_addr_and_mask(tvbuff_t *tvb, int offset,
    struct e_in6_addr *addr, guint32 prefix_len);

guint32 ip_get_subnet_mask(const guint32 mask_length);
#endif // ADDR_AND_MASK_H
