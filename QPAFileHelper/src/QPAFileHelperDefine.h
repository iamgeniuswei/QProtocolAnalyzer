/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileHelperDefine.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午8:29
 */

#ifndef QPAFILEHELPERDEFINE_H
#define QPAFILEHELPERDEFINE_H
/*
 * For registering file types that we can open.
 *
 * Each file type has an open routine and an optional list of extensions
 * the file might have.
 *
 * The open routine should return:
 *
 *      WTAP_OPEN_ERROR on an I/O error;
 *
 *      WTAP_OPEN_MINE if the file it's reading is one of the types
 *      it handles;
 *
 *      WTAP_OPEN_NOT_MINE if the file it's reading isn't one of the
 *      types it handles.
 *
 * If the routine handles this type of file, it should set the "file_type"
 * field in the "struct wtap" to the type of the file.
 *
 * Note that the routine does not have to free the private data pointer on
 * error. The caller takes care of that by calling wtap_close on error.
 * (See https://bugs.wireshark.org/bugzilla/show_bug.cgi?id=8518)
 *
 * However, the caller does have to free the private data pointer when
 * returning WTAP_OPEN_NOT_MINE, since the next file type will be called
 * and will likely just overwrite the pointer.
 */
typedef enum {
    WTAP_OPEN_NOT_MINE = 0,
    WTAP_OPEN_MINE = 1,
    WTAP_OPEN_ERROR = -1
} wtap_open_return_val;

typedef enum {
    OPEN_INFO_MAGIC = 0,
    OPEN_INFO_HEURISTIC = 1
} wtap_open_type;


//PCAP文件类型定义 
#define	PCAP_MAGIC			0xa1b2c3d4
#define	PCAP_SWAPPED_MAGIC		0xd4c3b2a1
#define	PCAP_MODIFIED_MAGIC		0xa1b2cd34
#define	PCAP_SWAPPED_MODIFIED_MAGIC	0x34cdb2a1
#define	PCAP_NSEC_MAGIC			0xa1b23c4d
#define	PCAP_SWAPPED_NSEC_MAGIC		0x4d3cb2a1

/* "libpcap" file header (minus magic number). */
struct pcap_hdr {
    unsigned short	version_major;	/* major version number */
    unsigned short	version_minor;	/* minor version number */
    int	thiszone;	/* GMT to local correction */
    unsigned int	sigfigs;	/* accuracy of timestamps */
    unsigned int	snaplen;	/* max length of captured packets, in octets */
    unsigned int	network;	/* data link type */
};

/* "libpcap" record header. */
struct pcaprec_hdr {
    unsigned int	ts_sec;		/* timestamp seconds */
    unsigned int	ts_usec;	/* timestamp microseconds (nsecs for PCAP_NSEC_MAGIC) */
    unsigned int	incl_len;	/* number of octets of packet saved in file */
    unsigned int	orig_len;	/* actual length of packet */
};

/* Encapsulation types. Choose names that truly reflect
 * what is contained in the packet trace file.
 *
 * WTAP_ENCAP_PER_PACKET is a value passed to "wtap_dump_open()" or
 * "wtap_dump_fd_open()" to indicate that there is no single encapsulation
 * type for all packets in the file; this may cause those routines to
 * fail if the capture file format being written can't support that.
 * It's also returned by "wtap_file_encap()" for capture files that
 * don't have a single encapsulation type for all packets in the file.
 *
 * WTAP_ENCAP_UNKNOWN is returned by "wtap_pcap_encap_to_wtap_encap()"
 * if it's handed an unknown encapsulation.
 *
 * WTAP_ENCAP_FDDI_BITSWAPPED is for FDDI captures on systems where the
 * MAC addresses you get from the hardware are bit-swapped.  Ideally,
 * the driver would tell us that, but I know of none that do, so, for
 * now, we base it on the machine on which we're *reading* the
 * capture, rather than on the machine on which the capture was taken
 * (they're probably likely to be the same).  We assume that they're
 * bit-swapped on everything except for systems running Ultrix, Alpha
 * systems, and BSD/OS systems (that's what "tcpdump" does; I guess
 * Digital decided to bit-swap addresses in the hardware or in the
 * driver, and I guess BSDI bit-swapped them in the driver, given that
 * BSD/OS generally runs on Boring Old PC's).  If we create a wiretap
 * save file format, we'd use the WTAP_ENCAP values to flag the
 * encapsulation of a packet, so there we'd at least be able to base
 * it on the machine on which the capture was taken.
 *
 * WTAP_ENCAP_LINUX_ATM_CLIP is the encapsulation you get with the
 * ATM on Linux code from <http://linux-atm.sourceforge.net/>;
 * that code adds a DLT_ATM_CLIP DLT_ code of 19, and that
 * encapsulation isn't the same as the DLT_ATM_RFC1483 encapsulation
 * presumably used on some BSD systems, which we turn into
 * WTAP_ENCAP_ATM_RFC1483.
 *
 * WTAP_ENCAP_NULL corresponds to DLT_NULL from "libpcap".  This
 * corresponds to
 *
 *  1) PPP-over-HDLC encapsulation, at least with some versions
 *     of ISDN4BSD (but not the current ones, it appears, unless
 *     I've missed something);
 *
 *  2) a 4-byte header containing the AF_ address family, in
 *     the byte order of the machine that saved the capture,
 *     for the packet, as used on many BSD systems for the
 *     loopback device and some other devices, or a 4-byte header
 *     containing the AF_ address family in network byte order,
 *     as used on recent OpenBSD systems for the loopback device;
 *
 *  3) a 4-byte header containing 2 octets of 0 and an Ethernet
 *     type in the byte order from an Ethernet header, that being
 *     what older versions of "libpcap" on Linux turn the Ethernet
 *     header for loopback interfaces into (0.6.0 and later versions
 *     leave the Ethernet header alone and make it DLT_EN10MB). */
#define WTAP_ENCAP_PER_PACKET                   -1
#define WTAP_ENCAP_UNKNOWN                        0
#define WTAP_ENCAP_ETHERNET                       1
#define WTAP_ENCAP_TOKEN_RING                     2
#define WTAP_ENCAP_SLIP                           3
#define WTAP_ENCAP_PPP                            4
#define WTAP_ENCAP_FDDI                           5
#define WTAP_ENCAP_FDDI_BITSWAPPED                6
#define WTAP_ENCAP_RAW_IP                         7
#define WTAP_ENCAP_ARCNET                         8
#define WTAP_ENCAP_ARCNET_LINUX                   9
#define WTAP_ENCAP_ATM_RFC1483                   10
#define WTAP_ENCAP_LINUX_ATM_CLIP                11
#define WTAP_ENCAP_LAPB                          12
#define WTAP_ENCAP_ATM_PDUS                      13
#define WTAP_ENCAP_ATM_PDUS_UNTRUNCATED          14
#define WTAP_ENCAP_NULL                          15
#define WTAP_ENCAP_ASCEND                        16
#define WTAP_ENCAP_ISDN                          17
#define WTAP_ENCAP_IP_OVER_FC                    18
#define WTAP_ENCAP_PPP_WITH_PHDR                 19
#define WTAP_ENCAP_IEEE_802_11                   20
#define WTAP_ENCAP_IEEE_802_11_PRISM             21
#define WTAP_ENCAP_IEEE_802_11_WITH_RADIO        22
#define WTAP_ENCAP_IEEE_802_11_RADIOTAP          23
#define WTAP_ENCAP_IEEE_802_11_AVS               24
#define WTAP_ENCAP_SLL                           25
#define WTAP_ENCAP_FRELAY                        26
#define WTAP_ENCAP_FRELAY_WITH_PHDR              27
#define WTAP_ENCAP_CHDLC                         28
#define WTAP_ENCAP_CISCO_IOS                     29
#define WTAP_ENCAP_LOCALTALK                     30
#define WTAP_ENCAP_OLD_PFLOG                     31
#define WTAP_ENCAP_HHDLC                         32
#define WTAP_ENCAP_DOCSIS                        33
#define WTAP_ENCAP_COSINE                        34
#define WTAP_ENCAP_WFLEET_HDLC                   35
#define WTAP_ENCAP_SDLC                          36
#define WTAP_ENCAP_TZSP                          37
#define WTAP_ENCAP_ENC                           38
#define WTAP_ENCAP_PFLOG                         39
#define WTAP_ENCAP_CHDLC_WITH_PHDR               40
#define WTAP_ENCAP_BLUETOOTH_H4                  41
#define WTAP_ENCAP_MTP2                          42
#define WTAP_ENCAP_MTP3                          43
#define WTAP_ENCAP_IRDA                          44
#define WTAP_ENCAP_USER0                         45
#define WTAP_ENCAP_USER1                         46
#define WTAP_ENCAP_USER2                         47
#define WTAP_ENCAP_USER3                         48
#define WTAP_ENCAP_USER4                         49
#define WTAP_ENCAP_USER5                         50
#define WTAP_ENCAP_USER6                         51
#define WTAP_ENCAP_USER7                         52
#define WTAP_ENCAP_USER8                         53
#define WTAP_ENCAP_USER9                         54
#define WTAP_ENCAP_USER10                        55
#define WTAP_ENCAP_USER11                        56
#define WTAP_ENCAP_USER12                        57
#define WTAP_ENCAP_USER13                        58
#define WTAP_ENCAP_USER14                        59
#define WTAP_ENCAP_USER15                        60
#define WTAP_ENCAP_SYMANTEC                      61
#define WTAP_ENCAP_APPLE_IP_OVER_IEEE1394        62
#define WTAP_ENCAP_BACNET_MS_TP                  63
#define WTAP_ENCAP_NETTL_RAW_ICMP                64
#define WTAP_ENCAP_NETTL_RAW_ICMPV6              65
#define WTAP_ENCAP_GPRS_LLC                      66
#define WTAP_ENCAP_JUNIPER_ATM1                  67
#define WTAP_ENCAP_JUNIPER_ATM2                  68
#define WTAP_ENCAP_REDBACK                       69
#define WTAP_ENCAP_NETTL_RAW_IP                  70
#define WTAP_ENCAP_NETTL_ETHERNET                71
#define WTAP_ENCAP_NETTL_TOKEN_RING              72
#define WTAP_ENCAP_NETTL_FDDI                    73
#define WTAP_ENCAP_NETTL_UNKNOWN                 74
#define WTAP_ENCAP_MTP2_WITH_PHDR                75
#define WTAP_ENCAP_JUNIPER_PPPOE                 76
#define WTAP_ENCAP_GCOM_TIE1                     77
#define WTAP_ENCAP_GCOM_SERIAL                   78
#define WTAP_ENCAP_NETTL_X25                     79
#define WTAP_ENCAP_K12                           80
#define WTAP_ENCAP_JUNIPER_MLPPP                 81
#define WTAP_ENCAP_JUNIPER_MLFR                  82
#define WTAP_ENCAP_JUNIPER_ETHER                 83
#define WTAP_ENCAP_JUNIPER_PPP                   84
#define WTAP_ENCAP_JUNIPER_FRELAY                85
#define WTAP_ENCAP_JUNIPER_CHDLC                 86
#define WTAP_ENCAP_JUNIPER_GGSN                  87
#define WTAP_ENCAP_LINUX_LAPD                    88
#define WTAP_ENCAP_CATAPULT_DCT2000              89
#define WTAP_ENCAP_BER                           90
#define WTAP_ENCAP_JUNIPER_VP                    91
#define WTAP_ENCAP_USB                           92
#define WTAP_ENCAP_IEEE802_16_MAC_CPS            93
#define WTAP_ENCAP_NETTL_RAW_TELNET              94
#define WTAP_ENCAP_USB_LINUX                     95
#define WTAP_ENCAP_MPEG                          96
#define WTAP_ENCAP_PPI                           97
#define WTAP_ENCAP_ERF                           98
#define WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR        99
#define WTAP_ENCAP_SITA                         100
#define WTAP_ENCAP_SCCP                         101
#define WTAP_ENCAP_BLUETOOTH_HCI                102 /*raw packets without a transport layer header e.g. H4*/
#define WTAP_ENCAP_IPMB                         103
#define WTAP_ENCAP_IEEE802_15_4                 104
#define WTAP_ENCAP_X2E_XORAYA                   105
#define WTAP_ENCAP_FLEXRAY                      106
#define WTAP_ENCAP_LIN                          107
#define WTAP_ENCAP_MOST                         108
#define WTAP_ENCAP_CAN20B                       109
#define WTAP_ENCAP_LAYER1_EVENT                 110
#define WTAP_ENCAP_X2E_SERIAL                   111
#define WTAP_ENCAP_I2C                          112
#define WTAP_ENCAP_IEEE802_15_4_NONASK_PHY      113
#define WTAP_ENCAP_TNEF                         114
#define WTAP_ENCAP_USB_LINUX_MMAPPED            115
#define WTAP_ENCAP_GSM_UM                       116
#define WTAP_ENCAP_DPNSS                        117
#define WTAP_ENCAP_PACKETLOGGER                 118
#define WTAP_ENCAP_NSTRACE_1_0                  119
#define WTAP_ENCAP_NSTRACE_2_0                  120
#define WTAP_ENCAP_FIBRE_CHANNEL_FC2            121
#define WTAP_ENCAP_FIBRE_CHANNEL_FC2_WITH_FRAME_DELIMS 122
#define WTAP_ENCAP_JPEG_JFIF                    123 /* obsoleted by WTAP_ENCAP_MIME*/
#define WTAP_ENCAP_IPNET                        124
#define WTAP_ENCAP_SOCKETCAN                    125
#define WTAP_ENCAP_IEEE_802_11_NETMON           126
#define WTAP_ENCAP_IEEE802_15_4_NOFCS           127
#define WTAP_ENCAP_RAW_IPFIX                    128
#define WTAP_ENCAP_RAW_IP4                      129
#define WTAP_ENCAP_RAW_IP6                      130
#define WTAP_ENCAP_LAPD                         131
#define WTAP_ENCAP_DVBCI                        132
#define WTAP_ENCAP_MUX27010                     133
#define WTAP_ENCAP_MIME                         134
#define WTAP_ENCAP_NETANALYZER                  135
#define WTAP_ENCAP_NETANALYZER_TRANSPARENT      136
#define WTAP_ENCAP_IP_OVER_IB                   137
#define WTAP_ENCAP_MPEG_2_TS                    138
#define WTAP_ENCAP_PPP_ETHER                    139
#define WTAP_ENCAP_NFC_LLCP                     140
#define WTAP_ENCAP_NFLOG                        141
#define WTAP_ENCAP_V5_EF                        142
#define WTAP_ENCAP_BACNET_MS_TP_WITH_PHDR       143
#define WTAP_ENCAP_IXVERIWAVE                   144
#define WTAP_ENCAP_IEEE_802_11_AIROPEEK         145
#define WTAP_ENCAP_SDH                          146
#define WTAP_ENCAP_DBUS                         147
#define WTAP_ENCAP_AX25_KISS                    148
#define WTAP_ENCAP_AX25                         149
#define WTAP_ENCAP_SCTP                         150
#define WTAP_ENCAP_INFINIBAND                   151
#define WTAP_ENCAP_JUNIPER_SVCS                 152
#define WTAP_ENCAP_USBPCAP                      153
#define WTAP_ENCAP_RTAC_SERIAL                  154
#define WTAP_ENCAP_BLUETOOTH_LE_LL              155
#define WTAP_ENCAP_WIRESHARK_UPPER_PDU          156
#define WTAP_ENCAP_STANAG_4607                  157
#define WTAP_ENCAP_STANAG_5066_D_PDU            158
#define WTAP_ENCAP_NETLINK                      159
#define WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR      160
#define WTAP_ENCAP_BLUETOOTH_BREDR_BB           161
#define WTAP_ENCAP_BLUETOOTH_LE_LL_WITH_PHDR    162
#define WTAP_ENCAP_NSTRACE_3_0                  163
#define WTAP_ENCAP_LOGCAT                       164
#define WTAP_ENCAP_LOGCAT_BRIEF                 165
#define WTAP_ENCAP_LOGCAT_PROCESS               166
#define WTAP_ENCAP_LOGCAT_TAG                   167
#define WTAP_ENCAP_LOGCAT_THREAD                168
#define WTAP_ENCAP_LOGCAT_TIME                  169
#define WTAP_ENCAP_LOGCAT_THREADTIME            170
#define WTAP_ENCAP_LOGCAT_LONG                  171
#define WTAP_ENCAP_PKTAP                        172
#define WTAP_ENCAP_EPON                         173
#define WTAP_ENCAP_IPMI_TRACE                   174
#define WTAP_ENCAP_LOOP                         175
#define WTAP_ENCAP_JSON                         176
#define WTAP_ENCAP_NSTRACE_3_5                  177c

/* File types/subtypes that can be read by wiretap.
   We support writing many of these file types, too, so we
   distinguish between different subtypes of them, as
   different subtypes need to be written in a different
   fashion. */
#define WTAP_FILE_TYPE_SUBTYPE_UNKNOWN                        0
#define WTAP_FILE_TYPE_SUBTYPE_PCAP                           1
#define WTAP_FILE_TYPE_SUBTYPE_PCAPNG                         2
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC                      3
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX                       4
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029                  5
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA                     6
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417                  7
#define WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915                  8
#define WTAP_FILE_TYPE_SUBTYPE_5VIEWS                         9
#define WTAP_FILE_TYPE_SUBTYPE_IPTRACE_1_0                   10
#define WTAP_FILE_TYPE_SUBTYPE_IPTRACE_2_0                   11
#define WTAP_FILE_TYPE_SUBTYPE_BER                           12
#define WTAP_FILE_TYPE_SUBTYPE_HCIDUMP                       13
#define WTAP_FILE_TYPE_SUBTYPE_CATAPULT_DCT2000              14
#define WTAP_FILE_TYPE_SUBTYPE_NETXRAY_OLD                   15
#define WTAP_FILE_TYPE_SUBTYPE_NETXRAY_1_0                   16
#define WTAP_FILE_TYPE_SUBTYPE_COSINE                        17
#define WTAP_FILE_TYPE_SUBTYPE_CSIDS                         18
#define WTAP_FILE_TYPE_SUBTYPE_DBS_ETHERWATCH                19
#define WTAP_FILE_TYPE_SUBTYPE_ERF                           20
#define WTAP_FILE_TYPE_SUBTYPE_EYESDN                        21
#define WTAP_FILE_TYPE_SUBTYPE_NETTL                         22
#define WTAP_FILE_TYPE_SUBTYPE_ISERIES                       23
#define WTAP_FILE_TYPE_SUBTYPE_ISERIES_UNICODE               24
#define WTAP_FILE_TYPE_SUBTYPE_I4BTRACE                      25
#define WTAP_FILE_TYPE_SUBTYPE_ASCEND                        26
#define WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x                    27
#define WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x                    28
#define WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_UNCOMPRESSED        29
#define WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_COMPRESSED          30
#define WTAP_FILE_TYPE_SUBTYPE_NETXRAY_1_1                   31
#define WTAP_FILE_TYPE_SUBTYPE_NETXRAY_2_00x                 32
#define WTAP_FILE_TYPE_SUBTYPE_NETWORK_INSTRUMENTS           33
#define WTAP_FILE_TYPE_SUBTYPE_LANALYZER                     34
#define WTAP_FILE_TYPE_SUBTYPE_PPPDUMP                       35
#define WTAP_FILE_TYPE_SUBTYPE_RADCOM                        36
#define WTAP_FILE_TYPE_SUBTYPE_SNOOP                         37
#define WTAP_FILE_TYPE_SUBTYPE_SHOMITI                       38
#define WTAP_FILE_TYPE_SUBTYPE_VMS                           39
#define WTAP_FILE_TYPE_SUBTYPE_K12                           40
#define WTAP_FILE_TYPE_SUBTYPE_TOSHIBA                       41
#define WTAP_FILE_TYPE_SUBTYPE_VISUAL_NETWORKS               42
#define WTAP_FILE_TYPE_SUBTYPE_PEEKCLASSIC_V56               43
#define WTAP_FILE_TYPE_SUBTYPE_PEEKCLASSIC_V7                44
#define WTAP_FILE_TYPE_SUBTYPE_PEEKTAGGED                    45
#define WTAP_FILE_TYPE_SUBTYPE_MPEG                          46
#define WTAP_FILE_TYPE_SUBTYPE_K12TEXT                       47
#define WTAP_FILE_TYPE_SUBTYPE_NETSCREEN                     48
#define WTAP_FILE_TYPE_SUBTYPE_COMMVIEW                      49
#define WTAP_FILE_TYPE_SUBTYPE_BTSNOOP                       50
#define WTAP_FILE_TYPE_SUBTYPE_TNEF                          51
#define WTAP_FILE_TYPE_SUBTYPE_DCT3TRACE                     52
#define WTAP_FILE_TYPE_SUBTYPE_PACKETLOGGER                  53
#define WTAP_FILE_TYPE_SUBTYPE_DAINTREE_SNA                  54
#define WTAP_FILE_TYPE_SUBTYPE_NETSCALER_1_0                 55
#define WTAP_FILE_TYPE_SUBTYPE_NETSCALER_2_0                 56
#define WTAP_FILE_TYPE_SUBTYPE_JPEG_JFIF                     57 /* obsoleted by WTAP_FILE_TYPE_SUBTYPE_MIME */
#define WTAP_FILE_TYPE_SUBTYPE_IPFIX                         58
#define WTAP_FILE_TYPE_SUBTYPE_MIME                          59
#define WTAP_FILE_TYPE_SUBTYPE_AETHRA                        60
#define WTAP_FILE_TYPE_SUBTYPE_MPEG_2_TS                     61
#define WTAP_FILE_TYPE_SUBTYPE_VWR_80211                     62
#define WTAP_FILE_TYPE_SUBTYPE_VWR_ETH                       63
#define WTAP_FILE_TYPE_SUBTYPE_CAMINS                        64
#define WTAP_FILE_TYPE_SUBTYPE_STANAG_4607                   65
#define WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_0                 66
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT                        67
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_BRIEF                  68
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_PROCESS                69
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_TAG                    70
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_THREAD                 71
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_TIME                   72
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_THREADTIME             73
#define WTAP_FILE_TYPE_SUBTYPE_LOGCAT_LONG                   74
#define WTAP_FILE_TYPE_SUBTYPE_COLASOFT_CAPSA                75
#define WTAP_FILE_TYPE_SUBTYPE_COLASOFT_PACKET_BUILDER       76
#define WTAP_FILE_TYPE_SUBTYPE_JSON                          77
#define WTAP_FILE_TYPE_SUBTYPE_NETSCALER_3_5                 78
#define WTAP_FILE_TYPE_SUBTYPE_NETTRACE_3GPP_32_423          79


/* timestamp precision (currently only these values are supported) */
#define WTAP_TSPREC_UNKNOWN    -2
#define WTAP_TSPREC_PER_PACKET -1  /* as a per-file value, means per-packet */
#define WTAP_TSPREC_SEC         0
#define WTAP_TSPREC_DSEC        1
#define WTAP_TSPREC_CSEC        2
#define WTAP_TSPREC_MSEC        3
#define WTAP_TSPREC_USEC        6
#define WTAP_TSPREC_NSEC        9
/* if you add to the above, update wtap_tsprec_string() */

/*
 * Maximum packet size we'll support.
 * 262144 is the largest snapshot length that libpcap supports, so we
 * use that.
 */
#define WTAP_MAX_PACKET_SIZE    262144

        
        
        
#endif /* QPAFILEHELPERDEFINE_H */

