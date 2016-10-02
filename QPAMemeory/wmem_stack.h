#ifndef WMEM_STACK_H
#define WMEM_STACK_H
#include <string.h>
#include <glib.h>

#include "wmem_core.h"
#include "wmem_list.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-stack Stack
 *
 *    A stack implementation on top of wmem.
 *
 *    @{
 */

/* Wmem stack is implemented as a simple wrapper over Wmem list */
typedef wmem_list_t wmem_stack_t;

#define wmem_stack_count(X) wmem_list_count(X)

extern
void *
wmem_stack_peek(const wmem_stack_t *stack);

extern
void *
wmem_stack_pop(wmem_stack_t *stack);

#define wmem_stack_push(STACK, DATA) wmem_list_prepend((STACK), (DATA))

#define wmem_stack_new(ALLOCATOR) wmem_list_new(ALLOCATOR)

#define wmem_destroy_stack(STACK) wmem_destroy_list(STACK)

/**   @}
 *  @} */


#endif // WMEM_STACK_H
