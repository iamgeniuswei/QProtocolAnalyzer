/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPATimeFmt.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 11:10 AM
 */

#ifndef QPATIMEFMT_H
#define QPATIMEFMT_H
/*
 * Resolution of a time stamp.
 */
typedef enum {
	TO_STR_TIME_RES_T_SECS,	 /* seconds      */
	TO_STR_TIME_RES_T_DSECS, /* deciseconds  */
	TO_STR_TIME_RES_T_CSECS, /* centiseconds */
	TO_STR_TIME_RES_T_MSECS, /* milliseconds */
	TO_STR_TIME_RES_T_USECS, /* microseconds */
	TO_STR_TIME_RES_T_NSECS	 /* nanoseconds  */
} to_str_time_res_t;

/*
 * Display format of an absolute-time time stamp.
 */
typedef enum {
	/* Start at 1000 to avoid duplicating the values used in field_display_e */
	ABSOLUTE_TIME_LOCAL = 1000,	/* local time in our time zone, with month and day */
	ABSOLUTE_TIME_UTC,	/* UTC, with month and day */
	ABSOLUTE_TIME_DOY_UTC	/* UTC, with 1-origin day-of-year */
} absolute_time_display_e;


#endif /* QPATIMEFMT_H */

