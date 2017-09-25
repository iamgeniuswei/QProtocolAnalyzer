/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_allocator.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午8:53
 */

#ifndef WMEM_ALLOCATOR_H
#define WMEM_ALLOCATOR_H
#include <stddef.h>
struct _wmem_user_cb_container_t;

/** An enumeration of the different types of available allocators. */
typedef enum _wmem_allocator_type_t {
    WMEM_ALLOCATOR_SIMPLE, /**< A trivial allocator that mallocs requested
                memory and tracks allocations via a hash table. As simple as
                possible, intended more as a demo than for practical usage. Also
                has the benefit of being friendly to tools like valgrind. */
    WMEM_ALLOCATOR_BLOCK, /**< A block allocator that grabs large chunks of
                memory at a time (8 MB currently) and serves allocations out of
                those chunks. Designed for efficiency, especially in the
                free_all operation. */
    WMEM_ALLOCATOR_STRICT, /**< An allocator that does its best to find invalid
                memory usage via things like canaries and scrubbing freed
                memory. Valgrind is the better choice on platforms that support
                it. */
    WMEM_ALLOCATOR_BLOCK_FAST /**< A block allocator like WMEM_ALLOCATOR_BLOCK
                but even faster by tracking absolutely minimal metadata and
                making 'free' a no-op. Useful only for very short-lived scopes
                where there's no reason to free individual allocations because
                the next free_all is always just around the corner. */
} wmem_allocator_type_t;



/* See section "4. Internal Design" of doc/README.wmem for details
 * on this structure */
typedef struct wmem_allocator_t {
    /* Consumer functions */
    void *(*walloc)(void *private_data, const size_t size);
    void  (*wfree)(void *private_data, void *ptr);
    void *(*wrealloc)(void *private_data, void *ptr, const size_t size);

    /* Producer/Manager functions */
    void  (*free_all)(void *private_data);
    void  (*gc)(void *private_data);
    void  (*cleanup)(void *private_data);

    /* Callback List */
    struct _wmem_user_cb_container_t *callbacks;

    /* Implementation details */
    void                        *private_data;
    enum _wmem_allocator_type_t  type;
    bool                     in_scope;
}_wmem_allocator_t;


#endif /* WMEM_ALLOCATOR_H */

