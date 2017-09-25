/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nstime.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:33 PM
 */

#ifndef NSTIME_H
#define NSTIME_H
#include <glib-2.0/glib.h>
/** @file
 * Definition of data structure to hold time values with nanosecond resolution
 */

/** data structure to hold time values with nanosecond resolution*/
typedef struct nstime_t {
	time_t	secs;
	int	nsecs;
} nstime_t;

/* functions */

/** set the given nstime_t to zero */
extern void nstime_set_zero(nstime_t *nstime);

/** is the given nstime_t currently zero? */
extern gboolean nstime_is_zero(nstime_t *nstime);

/** set the given nstime_t to (0,maxint) to mark it as "unset"
 * That way we can find the first frame even when a timestamp
 * is zero (fix for bug 1056)
 */
extern void nstime_set_unset(nstime_t *nstime);

/* is the given nstime_t currently (0,maxint)? */
extern gboolean nstime_is_unset(const nstime_t *nstime);

/** duplicate the current time
 *
 * a = b
 */
extern void nstime_copy(nstime_t *a, const nstime_t *b);

/** calculate the delta between two times (can be negative!)
 *
 * delta = b-a
 *
 * Note that it is acceptable for two or more of the arguments to point at the
 * same structure.
 */
extern void nstime_delta(nstime_t *delta, const nstime_t *b, const nstime_t *a );

/** calculate the sum of two times
 *
 * sum = a+b
 *
 * Note that it is acceptable for two or more of the arguments to point at the
 * same structure.
 */
extern void nstime_sum(nstime_t *sum, const nstime_t *b, const nstime_t *a );

/** sum += a */
#define nstime_add(sum, a) nstime_sum(sum, sum, a)

/** sum -= a */
#define nstime_subtract(sum, a) nstime_delta(sum, sum, a)

/** compare two times are return a value similar to memcmp() or strcmp().
 *
 * a > b : > 0
 * a = b : 0
 * a < b : < 0
 */
extern int nstime_cmp (const nstime_t *a, const nstime_t *b );

/** converts nstime to double, time base is milli seconds */
extern double nstime_to_msec(const nstime_t *nstime);

/** converts nstime to double, time base is seconds */
extern double nstime_to_sec(const nstime_t *nstime);

/** converts Windows FILETIME to nstime, returns TRUE on success,
    FALSE on failure */
extern gboolean filetime_to_nstime(nstime_t *nstime, guint64 filetime);

/** converts time like Windows FILETIME, but expressed in nanoseconds
    rather than tenths of microseconds, to nstime, returns TRUE on success,
    FALSE on failure */
extern gboolean nsfiletime_to_nstime(nstime_t *nstime, guint64 nsfiletime);

#endif /* NSTIME_H */

