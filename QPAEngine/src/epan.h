/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   epan.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:43 PM
 */

#ifndef EPAN_H
#define EPAN_H
#include <glib-2.0/glib.h>

extern const gchar*
epan_get_version(void);

/*
 * Register all the plugin types that are part of libwireshark.
 *
 * Must be called before init_plugins(), which must be called before
 * any registration routines are called, i.e. before epan_init().
 *
 * Must be called only once in a program.
 */
extern void epan_register_plugin_types(void);


/**
 * Init the whole epan module.
 *
 * Must be called only once in a program.
 *
 * Returns TRUE on success, FALSE on failure.
 */
extern
gboolean epan_init();


#endif /* EPAN_H */

