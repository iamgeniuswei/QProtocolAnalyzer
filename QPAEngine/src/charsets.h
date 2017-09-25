/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   charsets.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:40 PM
 */

#ifndef CHARSETS_H
#define CHARSETS_H
#include <glib-2.0/glib.h>
#include "wmem.h"
/*
 * Translation tables that map the upper 128 code points in single-byte
 * "extended ASCII" character encodings to Unicode code points in the
 * Basic Multilingual Plane.
 */

/* Table for windows-1250 */
extern const gunichar2 charset_table_cp1250[0x80];

/* Tables for ISO-8859-X */
extern const gunichar2 charset_table_iso_8859_2[0x80];
extern const gunichar2 charset_table_iso_8859_3[0x80];
extern const gunichar2 charset_table_iso_8859_4[0x80];
extern const gunichar2 charset_table_iso_8859_5[0x80];
extern const gunichar2 charset_table_iso_8859_6[0x80];
extern const gunichar2 charset_table_iso_8859_7[0x80];
extern const gunichar2 charset_table_iso_8859_8[0x80];
extern const gunichar2 charset_table_iso_8859_9[0x80];
extern const gunichar2 charset_table_iso_8859_10[0x80];
extern const gunichar2 charset_table_iso_8859_11[0x80];
extern const gunichar2 charset_table_iso_8859_13[0x80];
extern const gunichar2 charset_table_iso_8859_14[0x80];
extern const gunichar2 charset_table_iso_8859_15[0x80];
extern const gunichar2 charset_table_iso_8859_16[0x80];

/* Tables for Mac character sets */
extern const gunichar2 charset_table_mac_roman[0x80];

/* Tables for DOS code pages */
extern const gunichar2 charset_table_cp437[0x80];

/* Tables for EBCDIC code pages */
extern const gunichar2 charset_table_ebcdic[256];
extern const gunichar2 charset_table_ebcdic_cp037[256];

/*
 * Given a wmem scope, a pointer, and a length, treat the string of bytes
 * referred to by the pointer and length as an ASCII string, with all bytes
 * with the high-order bit set being invalid, and return a pointer to a
 * UTF-8 string, allocated using the wmem scope.
 *
 * Octets with the highest bit set will be converted to the Unicode
 * REPLACEMENT CHARACTER.
 */
extern guint8 *
get_ascii_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

extern guint8 *
get_8859_1_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

extern guint8 *
get_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[0x80]);

extern guint8 *
get_ucs_2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

extern guint8 *
get_utf_16_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

extern guint8 *
get_ucs_4_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

extern guint8 *
get_ts_23_038_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
        const gint bit_offset, gint no_of_chars);

extern guint8 *
get_ascii_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
        const gint bit_offset, gint no_of_chars);

extern guint8 *
get_nonascii_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[256]);

extern guint8 *
get_t61_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

#if 0
void ASCII_to_EBCDIC(guint8 *buf, guint bytes);
guint8 ASCII_to_EBCDIC1(guint8 c);
#endif
extern
void EBCDIC_to_ASCII(guint8 *buf, guint bytes);
extern
guint8 EBCDIC_to_ASCII1(guint8 c);

#endif /* CHARSETS_H */

