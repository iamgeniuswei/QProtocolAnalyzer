/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pin.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:21 PM
 */

#ifndef PIN_H
#define PIN_H
#include <glib-2.0/glib.h>
/* Pointer versions of g_ntohs and g_ntohl.  Given a pointer to a member of a
 * byte array, returns the value of the two or four bytes at the pointer.
 * The pletohXX versions return the little-endian representation.
 */

#define pntoh16(p)  ((guint16)                       \
                     ((guint16)*((const guint8 *)(p)+0)<<8|  \
                      (guint16)*((const guint8 *)(p)+1)<<0))

#define pntoh24(p)  ((guint32)*((const guint8 *)(p)+0)<<16|  \
                     (guint32)*((const guint8 *)(p)+1)<<8|   \
                     (guint32)*((const guint8 *)(p)+2)<<0)

#define pntoh32(p)  ((guint32)*((const guint8 *)(p)+0)<<24|  \
                     (guint32)*((const guint8 *)(p)+1)<<16|  \
                     (guint32)*((const guint8 *)(p)+2)<<8|   \
                     (guint32)*((const guint8 *)(p)+3)<<0)

#define pntoh40(p)  ((guint64)*((const guint8 *)(p)+0)<<32|  \
                     (guint64)*((const guint8 *)(p)+1)<<24|  \
                     (guint64)*((const guint8 *)(p)+2)<<16|  \
                     (guint64)*((const guint8 *)(p)+3)<<8|   \
                     (guint64)*((const guint8 *)(p)+4)<<0)

#define pntoh48(p)  ((guint64)*((const guint8 *)(p)+0)<<40|  \
                     (guint64)*((const guint8 *)(p)+1)<<32|  \
                     (guint64)*((const guint8 *)(p)+2)<<24|  \
                     (guint64)*((const guint8 *)(p)+3)<<16|  \
                     (guint64)*((const guint8 *)(p)+4)<<8|   \
                     (guint64)*((const guint8 *)(p)+5)<<0)

#define pntoh56(p)  ((guint64)*((const guint8 *)(p)+0)<<48|  \
                     (guint64)*((const guint8 *)(p)+1)<<40|  \
                     (guint64)*((const guint8 *)(p)+2)<<32|  \
                     (guint64)*((const guint8 *)(p)+3)<<24|  \
                     (guint64)*((const guint8 *)(p)+4)<<16|  \
                     (guint64)*((const guint8 *)(p)+5)<<8|   \
                     (guint64)*((const guint8 *)(p)+6)<<0)

#define pntoh64(p)  ((guint64)*((const guint8 *)(p)+0)<<56|  \
                     (guint64)*((const guint8 *)(p)+1)<<48|  \
                     (guint64)*((const guint8 *)(p)+2)<<40|  \
                     (guint64)*((const guint8 *)(p)+3)<<32|  \
                     (guint64)*((const guint8 *)(p)+4)<<24|  \
                     (guint64)*((const guint8 *)(p)+5)<<16|  \
                     (guint64)*((const guint8 *)(p)+6)<<8|   \
                     (guint64)*((const guint8 *)(p)+7)<<0)


#define pletoh16(p) ((guint16)                       \
                     ((guint16)*((const guint8 *)(p)+1)<<8|  \
                      (guint16)*((const guint8 *)(p)+0)<<0))

#define pletoh24(p) ((guint32)*((const guint8 *)(p)+2)<<16|  \
                     (guint32)*((const guint8 *)(p)+1)<<8|   \
                     (guint32)*((const guint8 *)(p)+0)<<0)

#define pletoh32(p) ((guint32)*((const guint8 *)(p)+3)<<24|  \
                     (guint32)*((const guint8 *)(p)+2)<<16|  \
                     (guint32)*((const guint8 *)(p)+1)<<8|   \
                     (guint32)*((const guint8 *)(p)+0)<<0)

#define pletoh40(p) ((guint64)*((const guint8 *)(p)+4)<<32|  \
                     (guint64)*((const guint8 *)(p)+3)<<24|  \
                     (guint64)*((const guint8 *)(p)+2)<<16|  \
                     (guint64)*((const guint8 *)(p)+1)<<8|   \
                     (guint64)*((const guint8 *)(p)+0)<<0)

#define pletoh48(p) ((guint64)*((const guint8 *)(p)+5)<<40|  \
                     (guint64)*((const guint8 *)(p)+4)<<32|  \
                     (guint64)*((const guint8 *)(p)+3)<<24|  \
                     (guint64)*((const guint8 *)(p)+2)<<16|  \
                     (guint64)*((const guint8 *)(p)+1)<<8|   \
                     (guint64)*((const guint8 *)(p)+0)<<0)

#define pletoh56(p) ((guint64)*((const guint8 *)(p)+6)<<48|  \
                     (guint64)*((const guint8 *)(p)+5)<<40|  \
                     (guint64)*((const guint8 *)(p)+4)<<32|  \
                     (guint64)*((const guint8 *)(p)+3)<<24|  \
                     (guint64)*((const guint8 *)(p)+2)<<16|  \
                     (guint64)*((const guint8 *)(p)+1)<<8|   \
                     (guint64)*((const guint8 *)(p)+0)<<0)

#define pletoh64(p) ((guint64)*((const guint8 *)(p)+7)<<56|  \
                     (guint64)*((const guint8 *)(p)+6)<<48|  \
                     (guint64)*((const guint8 *)(p)+5)<<40|  \
                     (guint64)*((const guint8 *)(p)+4)<<32|  \
                     (guint64)*((const guint8 *)(p)+3)<<24|  \
                     (guint64)*((const guint8 *)(p)+2)<<16|  \
                     (guint64)*((const guint8 *)(p)+1)<<8|   \
                     (guint64)*((const guint8 *)(p)+0)<<0)

/* Pointer routines to put items out in a particular byte order.
 * These will work regardless of the byte alignment of the pointer.
 */

#define phton16(p, v) \
	{ 				\
	((guint8*)(p))[0] = (guint8)((v) >> 8);	\
	((guint8*)(p))[1] = (guint8)((v) >> 0);	\
	}

#define phton32(p, v) \
	{ 				\
	((guint8*)(p))[0] = (guint8)((v) >> 24);	\
	((guint8*)(p))[1] = (guint8)((v) >> 16);	\
	((guint8*)(p))[2] = (guint8)((v) >> 8);	\
	((guint8*)(p))[3] = (guint8)((v) >> 0);	\
	}

#endif /* PIN_H */

