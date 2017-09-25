/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_core.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午8:51
 */

#ifndef WMEM_CORE_H
#define WMEM_CORE_H
#include <glib-2.0/glib.h>


#include "wmem_allocator.h"
/** Allocate the requested amount of memory in the given pool.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param size The amount of memory to allocate.
 * @return A void pointer to the newly allocated memory.
 */
extern
void *
wmem_alloc(wmem_allocator_t *allocator, const size_t size)
G_GNUC_MALLOC;

/** Allocate memory sufficient to hold one object of the given type.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param type The type that the newly allocated memory will hold.
 * @return A void pointer to the newly allocated memory.
 */
#define wmem_new(allocator, type) \
    ((type*)wmem_alloc((allocator), sizeof(type)))

#define wmem_safe_mult(A, B) \
    ((((A) <= 0) || ((B) <= 0) || ((gsize)(A) > (G_MAXSSIZE / (gsize)(B)))) ? 0 : ((A) * (B)))

/** Allocate memory sufficient to hold n objects of the given type.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param type The type that the newly allocated memory will hold.
 * @param num  The number of objects that the newly allocated memory will hold.
 * @return A void pointer to the newly allocated memory.
 */
#define wmem_alloc_array(allocator, type, num) \
    ((type*)wmem_alloc((allocator), wmem_safe_mult(sizeof(type), num)))

/** Allocate the requested amount of memory in the given pool. Initializes the
 * allocated memory with zeroes.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param size The amount of memory to allocate.
 * @return A void pointer to the newly allocated and zeroed memory.
 */
extern
void *
wmem_alloc0(wmem_allocator_t *allocator, const size_t size)
G_GNUC_MALLOC;

/** Allocate memory sufficient to hold one object of the given type.
 * Initializes the allocated memory with zeroes.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param type The type that the newly allocated memory will hold.
 * @return A void pointer to the newly allocated and zeroed memory.
 */
#define wmem_new0(allocator, type) \
    ((type*)wmem_alloc0((allocator), sizeof(type)))

/** Allocate memory sufficient to hold n objects of the given type.
 * Initializes the allocated memory with zeroes.
 *
 * @param allocator The allocator object to use to allocate the memory.
 * @param type The type that the newly allocated memory will hold.
 * @param num  The number of objects that the newly allocated memory will hold.
 * @return A void pointer to the newly allocated and zeroed memory.
 */
#define wmem_alloc0_array(allocator, type, num) \
    ((type*)wmem_alloc0((allocator), wmem_safe_mult(sizeof(type), (num))))

/** Returns the allocated memory to the allocator. This function should only
 * be called directly by allocators when the allocated block is sufficiently
 * large that the reduced memory usage is worth the cost of the extra function
 * call. It's usually easier to just let it get cleaned up when wmem_free_all()
 * is called.
 *
 * @param allocator The allocator object used to originally allocate the memory.
 * @param ptr The pointer to the memory block to free. After this function
 * returns it no longer points to valid memory.
 */
extern
void
wmem_free(wmem_allocator_t *allocator, void *ptr);

/** Resizes a block of memory, potentially moving it if resizing it in place
 * is not possible.
 *
 * @param allocator The allocator object used to originally allocate the memory.
 * @param ptr The pointer to the memory block to resize.
 * @param size The new size for the memory block.
 * @return The new location of the memory block. If this is different from ptr
 * then ptr no longer points to valid memory.
 */
extern
void *
wmem_realloc(wmem_allocator_t *allocator, void *ptr, const size_t size)
G_GNUC_MALLOC;

/** Frees all the memory allocated in a pool. Depending on the allocator
 * implementation used this can be significantly cheaper than calling
 * wmem_free() on all the individual blocks. It also doesn't require you to have
 * external pointers to those blocks.
 *
 * @param allocator The allocator to free the memory from.
 */
extern
void
wmem_free_all(wmem_allocator_t *allocator);

/** Triggers a garbage-collection in the allocator. This does not free any
 * memory, but it can return unused blocks to the operating system or perform
 * other optimizations.
 *
 * @param allocator The allocator in which to trigger the garbage collection.
 */
extern
void
wmem_gc(wmem_allocator_t *allocator);

/** Destroy the given allocator, freeing all memory allocated in it. Once this
 * function has been called, no memory allocated with the allocator is valid.
 *
 * @param allocator The allocator to destroy.
 */
extern
void
wmem_destroy_allocator(wmem_allocator_t *allocator);

/** Create a new allocator of the given type. The type may be overridden by the
 * WIRESHARK_DEBUG_WMEM_OVERRIDE environment variable.
 *
 * @param type The type of allocator to create.
 * @return The new allocator.
 */
extern
wmem_allocator_t *
wmem_allocator_new(const wmem_allocator_type_t type);

/** Initialize the wmem subsystem. This must be called before any other wmem
 * function, usually at the very beginning of your program.
 */
extern
void
wmem_init(void);

/** Teardown the wmem subsystem. This must be called after all other wmem
 * functions, usually at the very end of your program. This function will not
 * destroy outstanding allocators, you must do that yourself.
 */
extern
void
wmem_cleanup(void);


#endif /* WMEM_CORE_H */

