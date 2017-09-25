/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   epan_dissect.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:44 PM
 */

#ifndef EPAN_DISSECT_H
#define EPAN_DISSECT_H
#include "epan-int.h"
#include "tvbuff-int.h"
#include "proto.h"
#include "packet_info.h"
/* Dissection of a single byte array. Holds tvbuff info as
 * well as proto_tree info. As long as the epan_dissect_t for a byte
 * array is in existence, you must not free or move that byte array,
 * as the structures that the epan_dissect_t contains might have pointers
 * to addresses in your byte array.
 */
struct epan_dissect {
	struct epan_session *session;
	tvbuff_t	*tvb;
	proto_tree	*tree;
	packet_info	pi;
};

#endif /* EPAN_DISSECT_H */

