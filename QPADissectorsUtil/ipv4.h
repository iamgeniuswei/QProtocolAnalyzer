#ifndef IPV4_H
#define IPV4_H
#include <glib.h>


typedef struct {
    guint32	addr;	/* stored in host order */
    guint32	nmask;	/* stored in host order */
} ipv4_addr;

/* Allocate a new ipv4_addr struct, initialize it, and return pointer */
ipv4_addr* ipv4_addr_new(void);

/* Frees an ipv4 struct */
void ipv4_addr_free(ipv4_addr *ipv4);

void ipv4_addr_set_host_order_addr(ipv4_addr *ipv4, const guint32 new_addr);
void ipv4_addr_set_net_order_addr(ipv4_addr *ipv4, const guint32 new_addr);
void ipv4_addr_set_netmask_bits(ipv4_addr *ipv4, const guint new_nmask_bits);

extern
guint32 ipv4_get_net_order_addr(ipv4_addr *ipv4);
guint32 ipv4_get_host_order_addr(ipv4_addr *ipv4);

/* Fills in a buffer with a dotted-decimal notation representation of an IPv4
 * address. */
void ipv4_addr_str_buf(const ipv4_addr *ipv4, gchar *buf);

/* Compares two ipv4_addrs, taking into account the less restrictive of the
 * two netmasks, applying that netmask to both addrs.
 */
gboolean ipv4_addr_eq(const ipv4_addr *a, const ipv4_addr *b);
gboolean ipv4_addr_gt(const ipv4_addr *a, const ipv4_addr *b);
gboolean ipv4_addr_ge(const ipv4_addr *a, const ipv4_addr *b);
gboolean ipv4_addr_lt(const ipv4_addr *a, const ipv4_addr *b);
gboolean ipv4_addr_le(const ipv4_addr *a, const ipv4_addr *b);

#define ipv4_addr_ne(a,b) !ipv4_addr_eq((a),(b))

#endif // IPV4_H
