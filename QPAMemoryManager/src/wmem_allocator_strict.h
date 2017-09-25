/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_allocator_strict.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:30
 */

#ifndef WMEM_ALLOCATOR_STRICT_H
#define WMEM_ALLOCATOR_STRICT_H
#include "wmem_allocator.h"
extern
void
wmem_strict_allocator_init(wmem_allocator_t *allocator);

extern
void
wmem_strict_check_canaries(wmem_allocator_t *allocator);

#endif /* WMEM_ALLOCATOR_STRICT_H */

