/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   guid-util.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:02 PM
 */

#ifndef GUID_UTIL_H
#define GUID_UTIL_H
#include <glib-2.0/glib.h>

#define GUID_LEN	16

/* Note: this might be larger than GUID_LEN, so don't overlay data in packets
   with this. */
typedef struct _e_guid_t {
    guint32 data1;
    guint16 data2;
    guint16 data3;
    guint8  data4[8];
} e_guid_t;
#endif /* GUID_UTIL_H */

