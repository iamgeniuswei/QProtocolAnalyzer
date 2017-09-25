/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_user_cb_int.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午10:10
 */

#ifndef WMEM_USER_CB_INT_H
#define WMEM_USER_CB_INT_H
#include "wmem_allocator.h"

extern
void
wmem_call_callbacks(wmem_allocator_t *allocator, wmem_cb_event_t event);
#endif /* WMEM_USER_CB_INT_H */

