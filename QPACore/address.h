#ifndef ADDRESS_H
#define ADDRESS_H

typedef enum {
    AT_NONE,               /* no link-layer address */
    AT_ETHER,              /* MAC (Ethernet, 802.x, FDDI) address */
    AT_IPv4,               /* IPv4 */
    AT_IPv6,               /* IPv6 */
    AT_IPX,                /* IPX */
    AT_VINES,              /* Banyan Vines */
    AT_FC,                 /* Fibre Channel */
    AT_FCWWN,              /* Fibre Channel WWN */
    AT_SS7PC,              /* SS7 Point Code */
    AT_STRINGZ,            /* null-terminated string */
    AT_EUI64,              /* IEEE EUI-64 */
    AT_IB,                 /* Infiniband GID/LID */
    AT_USB,                /* USB Device address
                            * (0xffffffff represents the host) */
    AT_AX25,               /* AX.25 */

    AT_END_OF_LIST         /* Must be last in list */
} address_type;


/* Types of circuit IDs Wireshark knows about. */
typedef enum {
    CT_NONE,            /* no circuit type */
    CT_DLCI,            /* Frame Relay DLCI */
    CT_ISDN,            /* ISDN channel number */
    CT_X25,             /* X.25 logical channel number */
    CT_ISUP,            /* ISDN User Part CIC */
    CT_IAX2,            /* IAX2 call id */
    CT_H223,            /* H.223 logical channel number */
    CT_BICC,            /* BICC Circuit identifier */
    CT_DVBCI            /* DVB-CI session number|transport connection id */
    /* Could also have ATM VPI/VCI pairs */
} circuit_type;

/* Types of port numbers Wireshark knows about. */
typedef enum {
    PT_NONE,            /* no port number */
    PT_SCTP,            /* SCTP */
    PT_TCP,             /* TCP */
    PT_UDP,             /* UDP */
    PT_DCCP,            /* DCCP */
    PT_IPX,             /* IPX sockets */
    PT_NCP,             /* NCP connection */
    PT_EXCHG,           /* Fibre Channel exchange */
    PT_DDP,             /* DDP AppleTalk connection */
    PT_SBCCS,           /* FICON */
    PT_IDP,             /* XNS IDP sockets */
    PT_TIPC,            /* TIPC PORT */
    PT_USB,             /* USB endpoint 0xffff means the host */
    PT_I2C,
    PT_IBQP,            /* Infiniband QP number */
    PT_BLUETOOTH,
    PT_TDMOP
} port_type;



typedef struct _address {
    int           type;         /* type of address */
    int           len;          /* length of address, in bytes */
    const void  *data;          /* pointer to address data */
} address;
#endif // ADDRESS_H
