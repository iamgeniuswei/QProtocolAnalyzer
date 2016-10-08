#ifndef TO_STR_H
#define TO_STR_H
#include "wmem.h"
#include "address.h"
#include "tvbuff.h"
#include "nstime.h"
#include "time_fmt.h"
#include "guid-utils.h"

#define GUID_STR_LEN     37
#define MAX_IP_STR_LEN   16
#define MAX_IP6_STR_LEN  40
#define MAX_ADDR_STR_LEN 256
#define VINES_ADDR_LEN   6
#define EUI64_STR_LEN    24
#define AX25_ADDR_LEN    7
#define FCWWN_ADDR_LEN   8
/*
 * These are utility functions which convert various types to strings,
 * but for which no more specific module applies.
 */

struct     e_in6_addr;

extern gchar* address_to_str(wmem_allocator_t *scope, const address *addr);
extern gchar* address_with_resolution_to_str(wmem_allocator_t *scope, const address *addr);
extern gchar* tvb_address_with_resolution_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, int type, const gint offset);

/*
 * address_to_name takes as input an "address", as defined in address.h.
 *
 * If the address is of a type that can be translated into a name, and the
 * user has activated name resolution, and the name can be resolved, it
 * returns a string containing the translated name.
 *
 * Otherwise, it returns NULL.
 */
const gchar *address_to_name(const address *addr);

/*
 * address_to_display takes as input an "address", as defined in address.h .
 *
 * If the address is of a type that can be translated into a name, and the
 * user has activated name resolution, and the name can be resolved, it
 * returns a string containing the translated name.
 *
 * Otherwise, if the address is of type AT_NONE, it returns "NONE".
 *
 * Otherwise, it returns a string containing the result of address_to_str
 * on the argument, which should be a string representation for the address,
 * e.g. "10.10.10.10" for IPv4 address 10.10.10.10.
 */
extern
const gchar *address_to_display(wmem_allocator_t *allocator, const address *addr);

extern void     address_to_str_buf(const address *addr, gchar *buf, int buf_len);

#define tvb_ether_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_ETHER, offset)
#define tvb_ip_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_IPv4, offset)
#define tvb_ip6_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_IPv6, offset)
#define tvb_fcwwn_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_FCWWN, offset)
#define tvb_fc_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_FC, offset)
#define tvb_eui64_to_str(tvb, offset) tvb_address_to_str(wmem_packet_scope(), tvb, AT_EUI64, offset)

void	ip_to_str_buf(const guint8 *ad, gchar *buf, const int buf_len);

void	ip6_to_str_buf(const struct e_in6_addr *, gchar *);
extern gchar*	ipxnet_to_str_punct(wmem_allocator_t *scope, const guint32 ad, const char punct);
extern gchar*	eui64_to_str(wmem_allocator_t *scope, const guint64 ad);

extern gchar*	time_secs_to_str(wmem_allocator_t *scope, const gint32 time_val);
gchar*	time_secs_to_str_unsigned(wmem_allocator_t *scope, const guint32);
extern gchar*	time_msecs_to_str(wmem_allocator_t *scope, gint32 time_val);
extern gchar*	abs_time_to_str(wmem_allocator_t *scope, const nstime_t*, const absolute_time_display_e fmt,
    gboolean show_zone);
extern gchar*	abs_time_secs_to_str(wmem_allocator_t *scope, const time_t, const absolute_time_display_e fmt,
    gboolean show_zone);
extern void	display_signed_time(gchar *, int, const gint32, gint32, const to_str_time_res_t);
extern void	display_epoch_time(gchar *, int, const time_t,  gint32, const to_str_time_res_t);

extern void	guint32_to_str_buf(guint32 u, gchar *buf, int buf_len);
extern void	guint64_to_str_buf(guint64 u, gchar *buf, int buf_len);

extern gchar*	rel_time_to_str(wmem_allocator_t *scope, const nstime_t*);
extern gchar*	rel_time_to_secs_str(wmem_allocator_t *scope, const nstime_t*);
extern gchar*	guid_to_str(wmem_allocator_t *scope, const e_guid_t*);
gchar*	guid_to_str_buf(const e_guid_t*, gchar*, int);

extern char *decode_bits_in_field(const guint bit_offset, const gint no_of_bits, const guint64 value);

extern const gchar* port_type_to_str (port_type type);

/** Turn an address type retrieved from a tvb into a string.
 *
 * @param scope memory allocation scheme used
 * @param tvb tvbuff to retrieve address
 * @param type address type to retrieve
 * @param offset offset into tvb to retrieve address
 * @return A pointer to the formatted string
 *
 */
extern gchar* tvb_address_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, int type, const gint offset);

/** Turn an address type retrieved from a tvb into a string.
 *
 * @param scope memory allocation scheme used
 * @param tvb tvbuff to retrieve address
 * @param type address type to retrieve
 * @param offset offset into tvb to retrieve address
 * @param length The length of the string
 * @return A pointer to the formatted string
 *
 */
extern gchar* tvb_address_var_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, address_type type, const gint offset, int length);

/** Turn an array of bytes into a string showing the bytes in hex.
 *
 * @param scope memory allocation scheme used
 * @param bd A pointer to the byte array
 * @param bd_len The length of the byte array
 * @return A pointer to the formatted string
 */
extern char *bytes_to_str(wmem_allocator_t *scope, const guint8 *bd, int bd_len);

/** Turn an array of bytes into a string showing the bytes in hex,
 *  separated by a punctuation character.
 *
 * @param scope memory allocation scheme used
 * @param ad A pointer to the byte array
 * @param len The length of the byte array
 * @param punct The punctuation character
 * @return A pointer to the formatted string
 *
 * @see bytes_to_str()
 */
extern const gchar *bytestring_to_str(wmem_allocator_t *scope, const guint8 *ad, const guint32 len, const char punct);




#endif // TO_STR_H
