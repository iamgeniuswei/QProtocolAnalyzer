/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   epan-int.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:44 PM
 */

#ifndef EPAN_INT_H
#define EPAN_INT_H
#include <glib-2.0/glib.h>
#include "nstime.h"
struct epan_session {
	void *data;

	const nstime_t *(*get_frame_ts)(void *data, guint32 frame_num);
	const char *(*get_interface_name)(void *data, guint32 interface_id);
	const char *(*get_interface_description)(void *data, guint32 interface_id);
	const char *(*get_user_comment)(void *data, const frame_data *fd);
};
#endif /* EPAN_INT_H */

