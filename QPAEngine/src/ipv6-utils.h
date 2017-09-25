/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ipv6-utils.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:36 PM
 */

#ifndef IPV6_UTILS_H
#define IPV6_UTILS_H
#include <glib-2.0/glib.h>
struct e_in6_addr {
	guint8   bytes[16];		/**< 128 bit IP6 address */
};

typedef struct {
	struct e_in6_addr addr;
	guint32 prefix;
} ipv6_addr;

#endif /* IPV6_UTILS_H */

