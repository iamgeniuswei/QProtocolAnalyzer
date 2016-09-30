#ifndef WTAP_PKTHDR_H
#define WTAP_PKTHDR_H
#include "qprfformat_global.h"
#include <glib.h>
#include "buffer.h"
#include "nstime.h"


/*
 * The structure used to describe abstract offline file'packet header.
*/

struct wtap_pkthdr {
    guint     rec_type;         /* what type of record is this? */
    guint32   presence_flags;   /* what stuff do we have? */
    nstime_t  ts;               /* time stamp */
    guint32   caplen;           /* data length in the file */
    guint32   len;              /* data length on the wire */
    int       pkt_encap;        /* WTAP_ENCAP_ value for this packet */
    int       pkt_tsprec;       /* WTAP_TSPREC_ value for this packet */
                                /* pcapng variables */
    guint32   interface_id;     /* identifier of the interface. */
                                /* options */
    gchar     *opt_comment;     /* NULL if not available */
    guint64   drop_count;       /* number of packets lost (by the interface and the
                                   operating system) between this packet and the preceding one. */
    guint32   pack_flags;       /* XXX - 0 for now (any value for "we don't have it"?) */
    Buffer    ft_specific_data; /* file-type specific data */

//    union wtap_pseudo_header  pseudo_header;
};

QPRFFORMATSHARED_EXPORT
void wtap_phdr_init(wtap_pkthdr *phdr);


#endif // WTAP_PKTHDR_H
