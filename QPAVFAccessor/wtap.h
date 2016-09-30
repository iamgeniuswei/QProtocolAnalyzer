#ifndef WTAP_H
#define WTAP_H
#include <glib.h>
#include "teststruct1.h"
#include "wtap_pkthdr.h"
typedef gboolean (*subtype_read_func)(struct wtap*, int*, char**, gint64*);
typedef gboolean (*subtype_seek_read_func)(struct wtap*, gint64,
                                           struct wtap_pkthdr *, Buffer *buf,
                                           int *, char **);
typedef void (*wtap_new_ipv4_callback_t) (const guint addr, const gchar *name);
//WS_DLL_PUBLIC
//void wtap_set_cb_new_ipv4(wtap *wth, wtap_new_ipv4_callback_t add_new_ipv4);

typedef void (*wtap_new_ipv6_callback_t) (const void *addrp, const gchar *name);
//WS_DLL_PUBLIC
//void wtap_set_cb_new_ipv6(wtap *wth, wtap_new_ipv6_callback_t add_new_ipv6);


/**
 * Struct holding data of the currently read file.
 */

struct wtapng_name_res_t
       {

};
struct wtapng_section_s{

};

struct wtap {
//    FILE_T                      fh;
//    FILE_T                      random_fh;              /**< Secondary FILE_T for random access */
    int                         file_type_subtype;
    guint                       snapshot_length;
    struct Buffer               *frame_buffer;
    struct wtap_pkthdr          phdr;
    wtapng_section_s     shb_hdr;
    GArray                      *interface_data;        /**< An array holding the interface data from pcapng IDB:s or equivalent(?)*/
    wtapng_name_res_t           *nrb_hdr;               /**< holds the Name Res Block's comment/custom_opts, or NULL */

    void                        *priv;          /* this one holds per-file state and is free'd automatically by wtap_close() */
    void                        *wslua_data;    /* this one holds wslua state info and is not free'd */

    subtype_read_func           subtype_read;
    subtype_seek_read_func      subtype_seek_read;
    void                        (*subtype_sequential_close)(struct wtap*);
    void                        (*subtype_close)(struct wtap*);
    int                         file_encap;    /* per-file, for those
                                                * file formats that have
                                                * per-file encapsulation
                                                * types rather than per-packet
                                                * encapsulation types
                                                */
    int                         file_tsprec;   /* per-file timestamp precision
                                                * of the fractional part of
                                                * the time stamp, for those
                                                * file formats that have
                                                * per-file timestamp
                                                * precision rather than
                                                * per-packet timestamp
                                                * precision
                                                * e.g. WTAP_TSPREC_USEC
                                                */
    wtap_new_ipv4_callback_t    add_new_ipv4;
    wtap_new_ipv6_callback_t    add_new_ipv6;
    GPtrArray                   *fast_seek;
};

extern
struct wtap_pkthdr *
wtap_phdr(wtap *wth);

extern
guint8 *
wtap_buf_ptr(wtap *wth);


#endif // WTAP_H
