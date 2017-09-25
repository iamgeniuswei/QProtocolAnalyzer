/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sign_ext.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:22 PM
 */

#ifndef SIGN_EXT_H
#define SIGN_EXT_H
#include <glib-2.0/glib.h>
/* sign extension routines */

static inline guint32
ws_sign_ext32(guint32 val, int no_of_bits)
{
	g_assert (no_of_bits >= 0 && no_of_bits <= 32);

	if (no_of_bits == 0)
		return val;

	/*
	 * Don't shift signed values left; that's not valid in C99, at
	 * least, if the value is negative or if the shift count is
	 * the number of bits in the value - 1, and we might get
	 * compile-time or run-time complaints about that.
	 */
	if (val & (1U << (no_of_bits-1)))
		val |= (0xFFFFFFFFU << no_of_bits);

	return val;
}

static inline guint64
ws_sign_ext64(guint64 val, int no_of_bits)
{
	g_assert (no_of_bits >= 0 && no_of_bits <= 64);

	if (no_of_bits == 0)
		return val;

	/*
	 * Don't shift signed values left; that's not valid in C99, at
	 * least, if the value is negative or if the shift count is
	 * the number of bits in the value - 1, and we might get
	 * compile-time or run-time complaints about that.
	 */
	if (val & (G_GUINT64_CONSTANT(1) << (no_of_bits-1)))
		val |= (G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF) << no_of_bits);

	return val;
}

/*
static inline guint64
ws_sign_ext64(guint64 val, int no_of_bits)
{
	gint64 sval = (val << (64 - no_of_bits));

	return (guint64) (sval >> (64 - no_of_bits));
}
*/


#endif /* SIGN_EXT_H */

