#ifndef WMEM_SCOPES_H
#define WMEM_SCOPES_H
#include "wmem_core.h"
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

#endif // WMEM_SCOPES_H
