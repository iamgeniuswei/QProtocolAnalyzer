/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_scopes.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午10:00
 */

#ifndef WMEM_SCOPES_H
#define WMEM_SCOPES_H
#include "wmem_allocator.h"
/* Epan Scope */

extern
wmem_allocator_t *
wmem_epan_scope(void);

/* Packet Scope */

extern
wmem_allocator_t *
wmem_packet_scope(void);

extern
void
wmem_enter_packet_scope(void);

extern
void
wmem_leave_packet_scope(void);

/* File Scope */

extern
wmem_allocator_t *
wmem_file_scope(void);

extern
void
wmem_enter_file_scope(void);

extern
void
wmem_leave_file_scope(void);

/* Scope Management */

extern
void
wmem_init_scopes(void);

extern
void
wmem_cleanup_scopes(void);

#endif /* WMEM_SCOPES_H */

