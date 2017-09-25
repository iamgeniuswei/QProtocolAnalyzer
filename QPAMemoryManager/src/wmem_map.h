/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_map.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:55
 */

#ifndef WMEM_MAP_H
#define WMEM_MAP_H

#include <glib-2.0/glib.h>
#include "wmem_allocator.h"
#include "wmem_list.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-map Hash Map
 *
 *    A hash map implementation on top of wmem. Provides insertion, deletion and
 *    lookup in expected amortized constant time. Uses universal hashing to map
 *    keys into buckets, and provides a generic strong hash function that makes
 *    it secure against algorithmic complexity attacks, and suitable for use
 *    even with untrusted data.
 *
 *    @{
 */
typedef struct _wmem_map_item_t {
    const void *key;
    void *value;
    struct _wmem_map_item_t *next;
} wmem_map_item_t;

typedef struct _wmem_map_t {
    guint count; /* number of items stored */

    /* The base-2 logarithm of the actual size of the table. We store this
     * value for efficiency in hashing, since finding the actual capacity
     * becomes just a left-shift (see the CAPACITY macro) whereas taking
     * logarithms is expensive. */
    size_t capacity;

    wmem_map_item_t **table;

    GHashFunc  hash_func;
    GEqualFunc eql_func;

    guint      master_cb_id;
    guint      slave_cb_id;

    wmem_allocator_t *master;
    wmem_allocator_t *allocator;
}wmem_map_t;

/** Creates a map with the given allocator scope. When the scope is emptied,
 * the map is fully destroyed. Items stored in it will not be freed unless they
 * were allocated from the same scope. For details on the GHashFunc and
 * GEqualFunc parameters, see the glib documentation at:
 * https://developer.gnome.org/glib/unstable/glib-Hash-Tables.html
 *
 * If the keys are coming from untrusted data, do *not* use glib's default hash
 * functions for strings, int64s or doubles. Wmem provides stronger equivalents
 * below. Feel free to use the g_direct_hash, g_int_hash, and any of the
 * g_*_equal functions though, as they should be safe.
 *
 * @param allocator The allocator scope with which to create the map.
 * @param hash_func The hash function used to place inserted keys.
 * @param eql_func  The equality function used to compare inserted keys.
 * @return The newly-allocated map.
 */
extern
wmem_map_t *
wmem_map_new(wmem_allocator_t *allocator,
        GHashFunc hash_func, GEqualFunc eql_func)
G_GNUC_MALLOC;

/** Creates a map with two allocator scopes. The base structure lives in the
 * master scope, however the data lives in the slave scope. Every time free_all
 * occurs in the slave scope the map is transparently emptied without affecting
 * the location of the master structure.
 *
 * WARNING: None of the map (even the part in the master scope) can be used
 * after the slave scope has been *destroyed*.
 *
 * The primary use for this function is to create maps that reset for each new
 * capture file that is loaded. This can be done by specifying wmem_epan_scope()
 * as the master and wmem_file_scope() as the slave.
 */
extern
wmem_map_t *
wmem_map_new_autoreset(wmem_allocator_t *master, wmem_allocator_t *slave,
        GHashFunc hash_func, GEqualFunc eql_func)
G_GNUC_MALLOC;

/** Inserts a value into the map.
 *
 * @param map The map to insert into.
 * @param key The key to insert by.
 * @param value The value to insert.
 * @return The previous value stored at this key if any, or NULL.
 */
extern
void *
wmem_map_insert(wmem_map_t *map, const void *key, void *value);

/** Lookup a value in the map.
 *
 * @param map The map to search in.
 * @param key The key to lookup.
 * @return The value stored at the key if any, or NULL.
 */
extern
void *
wmem_map_lookup(wmem_map_t *map, const void *key);

/** Remove a value from the map. If no value is stored at that key, nothing
 * happens.
 *
 * @param map The map to remove from.
 * @param key The key of the value to remove.
 * @return The (removed) value stored at the key if any, or NULL.
 */
extern
void *
wmem_map_remove(wmem_map_t *map, const void *key);

/** Remove a key and value from the map but does not destroy (free) them. If no
 * value is stored at that key, nothing happens.
 *
 * @param map The map to remove from.
 * @param key The key of the value to remove.
 * @return TRUE if key is found FALSE if not.
 */
extern
gboolean
wmem_map_steal(wmem_map_t *map, const void *key);

/** Retrieves a list of keys inside the map
 *
 * @param list_allocator The allocator scope for the returned list.
 * @param map The map to extract keys from
 * @return list of keys in the map
 */
extern
wmem_list_t*
wmem_map_get_keys(wmem_allocator_t *list_allocator, wmem_map_t *map);

/** Run a function against all key/value pairs in the map. The order
 * of the calls is unpredictable, since it is based on the internal
 * storage of data.
 *
 * @param map The map to use
 * @param foreach_func the function to call for each key/value pair
 * @param user_data user data to pass to the function
 */
extern
void
wmem_map_foreach(wmem_map_t *map, GHFunc foreach_func, gpointer user_data);

/** Return the number of elements of the map.
 *
 * @param map The map to use
 * @return the number of elements
*/
extern
guint
wmem_map_size(wmem_map_t *map);

/** Compute a strong hash value for an arbitrary sequence of bytes. Use of this
 * hash value should be secure against algorithmic complexity attacks, even for
 * short keys. The computation uses a random seed which is generated on wmem
 * initialization, so the same key will hash to different values on different
 * runs of the application.
 *
 * @param buf The buffer of bytes (does not have to be aligned).
 * @param len The length of buf to use for the hash computation.
 * @return The hash value.
 */
extern
guint32
wmem_strong_hash(const guint8 *buf, const size_t len);

/** An implementation of GHashFunc using wmem_strong_hash. Prefer this over
 * g_str_hash when the data comes from an untrusted source.
 */
extern
guint
wmem_str_hash(gconstpointer key);

/** An implementation of GHashFunc using wmem_strong_hash. Prefer this over
 * g_int64_hash when the data comes from an untrusted source.
 */
extern
guint
wmem_int64_hash(gconstpointer key);

/** An implementation of GHashFunc using wmem_strong_hash. Prefer this over
 * g_double_hash when the data comes from an untrusted source.
 */
extern
guint
wmem_double_hash(gconstpointer key);

/**   @}
 *  @} */

#endif /* WMEM_MAP_H */

