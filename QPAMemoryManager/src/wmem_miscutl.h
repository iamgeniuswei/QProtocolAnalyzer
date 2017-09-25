/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_miscutl.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:58
 */

#ifndef WMEM_MISCUTL_H
#define WMEM_MISCUTL_H
#include "wmem_allocator.h"
#include <glib-2.0/glib.h>
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-strutl String Utilities
 *
 *    A collection of misc. utility functions for wmem.
 *
 *    @{
 */

/** Copies a block of memory.
 *
 * @param allocator The allocator object to use to allocate memory to copy into.
 * @param source The pointer to the memory block to copy.
 * @param size The amount of memory to copy.
 * @return The location of the memory copy.
 */
extern
void *
wmem_memdup(wmem_allocator_t *allocator, const void *source, const size_t size)
G_GNUC_MALLOC;

/**   @}
 *  @} */


#endif /* WMEM_MISCUTL_H */

