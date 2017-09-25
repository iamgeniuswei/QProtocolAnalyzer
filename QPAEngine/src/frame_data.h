/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   frame_data.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:31 PM
 */

#ifndef FRAME_DATA_H
#define FRAME_DATA_H
#include <glib-2.0/glib.h>
#include "nstime.h"
#define PINFO_FD_VISITED(pinfo)   ((pinfo)->fd->flags.visited)

/** @file
 * Low-level frame data and metadata.
 */

/** @defgroup framedata Frame Data
 *
 * @{
 */

/** @todo XXX - some of this stuff is used only while a packet is being dissected;
   should we keep that stuff in the "packet_info" structure, instead, to
   save memory? */

/* Types of character encodings */
typedef enum {
  PACKET_CHAR_ENC_CHAR_ASCII     = 0, /* ASCII */
  PACKET_CHAR_ENC_CHAR_EBCDIC    = 1  /* EBCDIC */
} packet_char_enc;

/** The frame number is the ordinal number of the frame in the capture, so
   it's 1-origin.  In various contexts, 0 as a frame number means "frame
   number unknown". */
struct _color_filter; /* Forward */
typedef struct _frame_data {
  GSList      *pfd;          /**< Per frame proto data */
  guint32      num;          /**< Frame number */
  guint32      pkt_len;      /**< Packet length */
  guint32      cap_len;      /**< Amount actually captured */
  guint32      cum_bytes;    /**< Cumulative bytes into the capture */
  gint64       file_off;     /**< File offset */
  guint16      subnum;       /**< subframe number, for protocols that require this */
  gint16       tsprec;       /**< Time stamp precision */
  struct {
    unsigned int passed_dfilter : 1; /**< 1 = display, 0 = no display */
    unsigned int dependent_of_displayed : 1; /**< 1 if a displayed frame depends on this frame */
    /* Do NOT use packet_char_enc enum here: MSVC compiler does not handle an enum in a bit field properly */
    unsigned int encoding       : 1; /**< Character encoding (ASCII, EBCDIC...) */
    unsigned int visited        : 1; /**< Has this packet been visited yet? 1=Yes,0=No*/
    unsigned int marked         : 1; /**< 1 = marked by user, 0 = normal */
    unsigned int ref_time       : 1; /**< 1 = marked as a reference time frame, 0 = normal */
    unsigned int ignored        : 1; /**< 1 = ignore this frame, 0 = normal */
    unsigned int has_ts         : 1; /**< 1 = has time stamp, 0 = no time stamp */
    unsigned int has_phdr_comment : 1; /** 1 = there's comment for this packet */
    unsigned int has_user_comment : 1; /** 1 = user set (also deleted) comment for this packet */
    unsigned int need_colorize  : 1; /**< 1 = need to (re-)calculate packet color */
  } flags;

  const struct _color_filter *color_filter;  /**< Per-packet matching color_filter_t object */

  nstime_t     abs_ts;       /**< Absolute timestamp */
  nstime_t     shift_offset; /**< How much the abs_tm of the frame is shifted */
  guint32      frame_ref_num; /**< Previous reference frame (0 if this is one) */
  guint32      prev_dis_num; /**< Previous displayed frame (0 if first one) */
} frame_data;
#endif /* FRAME_DATA_H */

