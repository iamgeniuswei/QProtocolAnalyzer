/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   unicode-utils.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 5:42 PM
 */

#ifndef UNICODE_UTILS_H
#define UNICODE_UTILS_H

/*
 * defines for helping with UTF-16 surrogate pairs
 */

#define IS_LEAD_SURROGATE(uchar2) \
	((uchar2) >= 0xd800 && (uchar2) < 0xdc00)
#define IS_TRAIL_SURROGATE(uchar2) \
	((uchar2) >= 0xdc00 && (uchar2) < 0xe000)
#define SURROGATE_VALUE(lead, trail) \
	(((((lead) - 0xd800) << 10) | ((trail) - 0xdc00)) + 0x100000)

#endif /* UNICODE_UTILS_H */

