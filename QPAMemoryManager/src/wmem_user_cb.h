/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_user_cb.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午10:10
 */

#ifndef WMEM_USER_CB_H
#define WMEM_USER_CB_H
#include <glib-2.0/glib.h>
#include "wmem_allocator.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-user-cb User Callbacks
 *
 *    User callbacks.
 *
 *    @{
 */

/** The events that can trigger a callback. */
typedef enum _wmem_cb_event_t {
    WMEM_CB_FREE_EVENT,    /**< wmem_free_all() */
    WMEM_CB_DESTROY_EVENT  /**< wmem_destroy_allocator() */
} wmem_cb_event_t;

/** Function signature for registered user callbacks.
 *
 * allocator The allocator that triggered this callback.
 * event     The event type that triggered this callback.
 * user_data Whatever user_data was originally passed to the call to
 *                  wmem_register_callback().
 * @return          FALSE to unregister the callback, TRUE otherwise.
 */
typedef gboolean (*wmem_user_cb_t) (wmem_allocator_t*, wmem_cb_event_t, void*);

/** Register a callback function with the given allocator pool.
 *
 * @param allocator The allocator with which to register the callback.
 * @param callback  The function to be called as the callback.
 * @param user_data An arbitrary data pointer that is passed to the callback as
 *                  a way to specify extra parameters or store extra data. Note
 *                  that this pointer is not freed when a callback is finished,
 *                  you have to do that yourself in the callback, or just
 *                  allocate it in the appropriate wmem pool.
 * @return          ID of this callback that can be passed back to
 *                  wmem_unregister_callback().
 */
extern
guint
wmem_register_callback(wmem_allocator_t *allocator, wmem_user_cb_t callback,
        void *user_data);

/** Unregister the callback function with the given ID.
 *
 * @param allocator The allocator from which to unregister the callback.
 * @param id        The callback id as returned from wmem_register_callback().
 */
extern
void
wmem_unregister_callback(wmem_allocator_t *allocator, guint id);

extern
void
wmem_call_callbacks(wmem_allocator_t *allocator, wmem_cb_event_t event);

/**   @}
 *  @} */

#endif /* WMEM_USER_CB_H */

