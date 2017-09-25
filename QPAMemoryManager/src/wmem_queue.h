/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_queue.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:59
 */

#ifndef WMEM_QUEUE_H
#define WMEM_QUEUE_H
#include "wmem_list.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-queue Queue
 *
 *    A queue implementation on top of wmem.
 *
 *    @{
 */

/* Wmem queue is implemented as a dumb wrapper over Wmem list and stack */
typedef wmem_list_t wmem_queue_t;

#define wmem_queue_count(X) wmem_list_count(X)

#define wmem_queue_peek(QUEUE) wmem_stack_peek(QUEUE)

#define wmem_queue_pop(QUEUE) wmem_stack_pop(QUEUE)

#define wmem_queue_push(QUEUE, DATA) wmem_list_append((QUEUE), (DATA))

#define wmem_queue_new(ALLOCATOR) wmem_list_new(ALLOCATOR)

#define wmem_destroy_queue(QUEUE) wmem_destroy_list(QUEUE)

#endif /* WMEM_QUEUE_H */

