/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exceptions.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 4:37 PM
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
/**
    Index is out of range.
    An attempt was made to read past the end of a buffer.
    This generally means that the capture was done with a "slice"
    length or "snapshot" length less than the maximum packet size,
    and a link-layer packet was cut short by that, so not all of the
    data in the link-layer packet was available.
**/
#define BoundsError		1

/**
    Index is beyond reported length (not cap_len)
    An attempt was made to read past the logical end of a buffer. This
    differs from a BoundsError in that the parent protocol established a
    limit past which this dissector should not process in the buffer and that
    limit was exceeded.
    This generally means that the packet is invalid, i.e. whatever
    code constructed the packet and put it on the wire didn't put enough
    data into it.  It is therefore currently reported as a "Malformed
    packet".
**/
#define ReportedBoundsError	2

/**
    Index is beyond fragment length but not reported length.
    This means that the packet wasn't reassembled.
**/
#define FragmentBoundsError	3

/**
    During dfilter parsing
**/
#define TypeError		4

/**
    A bug was detected in a dissector.

    DO NOT throw this with THROW(); that means that no details about
    the dissector error will be reported.  (Instead, the message will
    blame you for not providing details.)

    Instead, use the DISSECTOR_ASSERT(), etc. macros in epan/proto.h.
**/
#define DissectorError		5


#endif /* EXCEPTIONS_H */

