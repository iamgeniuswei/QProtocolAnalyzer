/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAAddress.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 9:40 AM
 */

#ifndef QPAADDRESS_H
#define QPAADDRESS_H

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


/* Types of "global" addresses Wireshark knows about. */
/* Address types can be added here if there are many dissectors that use them or just
 * within a specific dissector.
 * If an address type is added here, it must be "registered" within address_types.c
 * For dissector address types, just use the address_type_dissector_register function
 * from address_types.h
 */
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


class QPAAddress
{
public:
    QPAAddress();
    QPAAddress(const QPAAddress& orig) = delete;
    QPAAddress(const QPAAddress&& orig) = delete;
    QPAAddress& operator=(const QPAAddress& orig) = delete;
    QPAAddress& operator=(const QPAAddress&& orig) = delete;
    virtual ~QPAAddress();

protected:

public:
    int type = AT_NONE;
    int len;
    void *data;

};

#endif /* QPAADDRESS_H */

