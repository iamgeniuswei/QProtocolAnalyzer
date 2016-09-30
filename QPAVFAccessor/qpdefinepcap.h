#ifndef QPDEFINEPCAP_H
#define QPDEFINEPCAP_H
#include <glib.h>
/* Magic numbers in "libpcap" files.

   "libpcap" file records are written in the byte order of the host that
   writes them, and the reader is expected to fix this up.

   PCAP_MAGIC is the magic number, in host byte order; PCAP_SWAPPED_MAGIC
   is a byte-swapped version of that.

   PCAP_MODIFIED_MAGIC is for Alexey Kuznetsov's modified "libpcap"
   format, as generated on Linux systems that have a "libpcap" with
   his patches, at

    http://ftp.sunet.se/pub/os/Linux/ip-routing/lbl-tools/

   applied; PCAP_SWAPPED_MODIFIED_MAGIC is the byte-swapped version.

   PCAP_NSEC_MAGIC is for Ulf Lamping's modified "libpcap" format,
   which uses the same common file format as PCAP_MAGIC, but the
   timestamps are saved in nanosecond resolution instead of microseconds.
   PCAP_SWAPPED_NSEC_MAGIC is a byte-swapped version of that. */
#define	PCAP_MAGIC			0xa1b2c3d4
#define	PCAP_SWAPPED_MAGIC		0xd4c3b2a1
#define	PCAP_MODIFIED_MAGIC		0xa1b2cd34
#define	PCAP_SWAPPED_MODIFIED_MAGIC	0x34cdb2a1
#define	PCAP_NSEC_MAGIC			0xa1b23c4d
#define	PCAP_SWAPPED_NSEC_MAGIC		0x4d3cb2a1

/* "libpcap" file header (minus magic number). */
struct pcap_hdr {
    quint16	version_major;	/* major version number */
    quint16	version_minor;	/* minor version number */
    qint32	thiszone;	/* GMT to local correction */
    quint32	sigfigs;	/* accuracy of timestamps */
    quint32	snaplen;	/* max length of captured packets, in octets */
    quint32	network;	/* data link type */
};

/* "libpcap" record header. */
struct pcaprec_hdr {
    quint32	ts_sec;		/* timestamp seconds */
    quint32	ts_usec;	/* timestamp microseconds (nsecs for PCAP_NSEC_MAGIC) */
    quint32	incl_len;	/* number of octets of packet saved in file */
    quint32	orig_len;	/* actual length of packet */
};

/* "libpcap" record header for Alexey's patched version. */
struct pcaprec_modified_hdr {
    struct pcaprec_hdr hdr;	/* the regular header */
    quint32 ifindex;	/* index, in *capturing* machine's list of
                   interfaces, of the interface on which this
                   packet came in. */
    quint16 protocol;	/* Ethernet packet type */
    quint8 pkt_type;	/* broadcast/multicast/etc. indication */
    quint8 pad;		/* pad to a 4-byte boundary */
};

/* "libpcap" record header for Alexey's patched version in its ss990915
   incarnation; this version shows up in SuSE Linux 6.3. */
struct pcaprec_ss990915_hdr {
    struct pcaprec_hdr hdr;	/* the regular header */
    quint32 ifindex;	/* index, in *capturing* machine's list of
                   interfaces, of the interface on which this
                   packet came in. */
    quint16 protocol;	/* Ethernet packet type */
    quint8 pkt_type;	/* broadcast/multicast/etc. indication */
    quint8 cpu1, cpu2;	/* SMP debugging gunk? */
    quint8 pad[3];		/* pad to a 4-byte boundary */
};

/* "libpcap" record header for version used on some Nokia boxes (firewalls?) */
struct pcaprec_nokia_hdr {
    struct pcaprec_hdr hdr;	/* the regular header */
    quint8 stuff[4];	/* mysterious stuff */
};
/* See source to the "libpcap" library for information on the "libpcap"
   file format. */

/*
 * Private per-wtap_t data needed to read a file.
 */
typedef enum {
    NOT_SWAPPED,
    SWAPPED,
    MAYBE_SWAPPED
} swapped_type_t;

typedef struct {
    gboolean byte_swapped;
    swapped_type_t lengths_swapped;
    guint16	version_major;
    guint16	version_minor;
} libpcap_t;



#endif // QPDEFINEPCAP_H
