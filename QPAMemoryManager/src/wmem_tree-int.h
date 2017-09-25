/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_tree-int.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:49
 */

#ifndef WMEM_TREE_INT_H
#define WMEM_TREE_INT_H
#include <glib-2.0/glib.h>
#include "wmem_allocator.h"
typedef enum _wmem_node_color_t {
    WMEM_NODE_COLOR_RED,
    WMEM_NODE_COLOR_BLACK
} wmem_node_color_t;


struct _wmem_tree_node_t {
    struct _wmem_tree_node_t *parent;
    struct _wmem_tree_node_t *left;
    struct _wmem_tree_node_t *right;

    const void *key;
    void *data;

    wmem_node_color_t color;
    gboolean          is_subtree;
    gboolean          is_removed;


};

typedef struct _wmem_tree_node_t wmem_tree_node_t;


typedef struct _wmem_itree_node_t wmem_itree_node_t;

typedef struct _wmem_tree_t {
    wmem_allocator_t *master;
    wmem_allocator_t *allocator;
    wmem_tree_node_t *root;
    guint             master_cb_id;
    guint             slave_cb_id;

    void (*post_rotation_cb)(wmem_tree_node_t *);
}wmem_itree_t, wmem_tree_t;

typedef int (*compare_func)(const void *a, const void *b);

wmem_tree_node_t *
wmem_tree_insert(wmem_tree_t *tree, const void *key, void *data, compare_func cmp);

typedef struct _wmem_range_t wmem_range_t;

gboolean
wmem_itree_range_overlap(const wmem_range_t *r1, const wmem_range_t *r2);


#endif /* WMEM_TREE_INT_H */

