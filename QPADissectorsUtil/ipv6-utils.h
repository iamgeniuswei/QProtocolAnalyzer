#ifndef IPV6UTILS_H
#define IPV6UTILS_H
#include <glib.h>
struct e_in6_addr {
    guint8   bytes[16];		/**< 128 bit IP6 address */
};

typedef struct {
    struct e_in6_addr addr;
    guint32 prefix;
} ipv6_addr;
#endif // IPV6UTILS_H
