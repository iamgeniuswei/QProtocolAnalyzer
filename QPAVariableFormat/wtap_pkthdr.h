#ifndef WTAP_PKTHDR_H
#define WTAP_PKTHDR_H
#include "qprfformat_global.h"
#include <glib.h>
#include "buffer.h"
#include "nstime.h"
/*
 * Record type values.
 *
 * This list will expand over time, so don't assume everything will
 * forever be one of the types listed below.
 *
 * For file-type-specific records, the "ftsrec" field of the pseudo-header
 * contains a file-type-specific subtype value, such as a block type for
 * a pcap-ng file.
 *
 * An "event" is an indication that something happened during the capture
 * process, such as a status transition of some sort on the network.
 * These should, ideally, have a time stamp and, if they're relevant to
 * a particular interface on a multi-interface capture, should also have
 * an interface ID.  The data for the event is file-type-specific and
 * subtype-specific.  These should be dissected and displayed just as
 * packets are.
 *
 * A "report" supplies information not corresponding to an event;
 * for example, a pcap-ng Interface Statistics Block would be a report,
 * as it doesn't correspond to something happening on the network.
 * They may have a time stamp, and should be dissected and displayed
 * just as packets are.
 *
 * We distingiush between "events" and "reports" so that, for example,
 * the packet display can show the delta between a packet and an event
 * but not show the delta between a packet and a report, as the time
 * stamp of a report may not correspond to anything interesting on
 * the network but the time stamp of an event would.
 *
 * XXX - are there any file-type-specific records that *shouldn't* be
 * dissected and displayed?  If so, they should be parsed and the
 * information in them stored somewhere, and used somewhere, whether
 * it's just used when saving the file in its native format or also
 * used to parse *other* file-type-specific records.
 */
#define REC_TYPE_PACKET               0    /**< packet */
#define REC_TYPE_FT_SPECIFIC_EVENT    1    /**< file-type-specific event */
#define REC_TYPE_FT_SPECIFIC_REPORT   2    /**< file-type-specific report */


/* Also defined in epan/packet_info.h */
#define P2P_DIR_UNKNOWN -1
#define P2P_DIR_SENT     0
#define P2P_DIR_RECV     1

/* Link direction */
#define LINK_DIR_UNKNOWN    -1
#define P2P_DIR_UL  0
#define P2P_DIR_DL  1
/*
 * The structure used to describe abstract offline file'packet header.
*/

class wtap_pkthdr {
    friend class QPAVFMediator;
    friend class frame_data;
    friend class QPFileAccessor;
public:
    wtap_pkthdr();
    ~wtap_pkthdr();
    void wtap_phdr_init();
private:
    quint32     rec_type;         /* what type of record is this? */
    quint32   presence_flags;   /* what stuff do we have? */
    nstime_t  ts;               /* time stamp */
    quint32   caplen;           /* data length in the file */
    quint32   len;              /* data length on the wire */
    qint32       pkt_encap;        /* WTAP_ENCAP_ value for this packet */
    qint32       pkt_tsprec;       /* WTAP_TSPREC_ value for this packet */
                                /* pcapng variables */
    quint32   interface_id;     /* identifier of the interface. */
                                /* options */
    gchar     *opt_comment;     /* NULL if not available */
    quint64   drop_count;       /* number of packets lost (by the interface and the
                                   operating system) between this packet and the preceding one. */
    quint32   pack_flags;       /* XXX - 0 for now (any value for "we don't have it"?) */
    Buffer    ft_specific_data; /* file-type specific data */
//    union wtap_pseudo_header  pseudo_header;
};

extern
void wtap_phdr_init(wtap_pkthdr *phdr);
/*** clean up a wtap_pkthdr structure, freeing what wtap_phdr_init() allocated */
extern
void wtap_phdr_cleanup(struct wtap_pkthdr *phdr);


#endif // WTAP_PKTHDR_H
