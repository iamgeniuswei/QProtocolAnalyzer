#ifndef WTAP_H
#define WTAP_H
#include <glib.h>
#include "teststruct1.h"
#include "wtap_pkthdr.h"
class QPAVFMediator;
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

/**
 * Interface description data
 */
typedef struct wtapng_if_descr_s {
    int                    wtap_encap;            /**< link_type translated to wtap_encap */
    guint64                time_units_per_second;
    int                    tsprecision;           /**< WTAP_TSPREC_ value for this interface */

    /* mandatory */
    guint16                link_type;
    guint32                snap_len;

    /* options */
    gchar                 *opt_comment;           /**< NULL if not available */
    gchar                 *if_name;               /**< NULL if not available
                                                   *  opt 2
                                                   *     A UTF-8 string containing the name of the
                                                   *     device used to capture data.
                                                   */
    gchar                 *if_description;        /**< NULL if not available
                                                   *  opt 3
                                                   *     A UTF-8 string containing the description
                                                   *     of the device used to capture data.
                                                   */

    /* XXX: if_IPv4addr opt 4  Interface network address and netmask.                                */
    /* XXX: if_IPv6addr opt 5  Interface network address and prefix length (stored in the last byte).*/
    /* XXX: if_MACaddr  opt 6  Interface Hardware MAC address (48 bits).                             */
    /* XXX: if_EUIaddr  opt 7  Interface Hardware EUI address (64 bits)                              */

    guint64                if_speed;              /**< 0xFFFFFFFF if unknown
                                                   *  opt 8
                                                   *     Interface speed (in bps). 100000000 for 100Mbps
                                                   */
    guint8                 if_tsresol;            /**< default is 6 for microsecond resolution
                                                   *  opt 9
                                                   *     Resolution of timestamps.
                                                   *     If the Most Significant Bit is equal to zero,
                                                   *     the remaining bits indicates the resolution of the
                                                   *     timestamp as as a negative power of 10
                                                   */

    /* XXX: if_tzone      10  Time zone for GMT support (TODO: specify better). */

    gchar                 *if_filter_str;         /**< NULL if not available
                                                   *  opt 11  libpcap string.
                                                   */
    guint16                bpf_filter_len;        /** Opt 11 variant II BPF filter len 0 if not used*/
    gchar                 *if_filter_bpf_bytes;   /** Opt 11 BPF filter or NULL */
    gchar                 *if_os;                 /**< NULL if not available
                                                   *     12  A UTF-8 string containing the name of the
                                                   *     operating system of the machine in which this
                                                   *     interface is installed.
                                                   */
    gint8                  if_fcslen;             /**< -1 if unknown or changes between packets,
                                                   *  opt 13
                                                   *     An integer value that specified the length of
                                                   *     the Frame Check Sequence (in bits) for this interface. */
    /* XXX: guint64    if_tsoffset; opt 14  A 64 bits integer value that specifies an offset (in seconds)...*/
    guint8                 num_stat_entries;
    GArray                *interface_statistics;  /**< An array holding the interface statistics from
                                                   *     pcapng ISB:s or equivalent(?)*/
} wtapng_if_descr_t;

extern
struct wtap_pkthdr *
wtap_phdr(wtap *wth);

extern
guint8 *
wtap_buf_ptr(QPAVFMediator *wth);


#define WTAP_MAX_PACKET_SIZE    262144

#endif // WTAP_H
