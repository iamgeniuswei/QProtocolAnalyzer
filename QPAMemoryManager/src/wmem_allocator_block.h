/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_allocator_block.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:39
 */

#ifndef WMEM_ALLOCATOR_BLOCK_H
#define WMEM_ALLOCATOR_BLOCK_H
#include "wmem_allocator.h"
extern
void
wmem_block_allocator_init(wmem_allocator_t *allocator);

/* Exposed only for testing purposes */
extern
void
wmem_block_verify(wmem_allocator_t *allocator);


#endif /* WMEM_ALLOCATOR_BLOCK_H */

