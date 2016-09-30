#ifndef BUFFER_H
#define BUFFER_H
#include "qpautilization_global.h"
#include <glib.h>
struct Buffer {
    guint8	*data;
    gsize	allocated;
    gsize	start;
    gsize	first_free;
};

QPAUTILIZATIONSHARED_EXPORT
void ws_buffer_init(Buffer* buffer, gsize space);
QPAUTILIZATIONSHARED_EXPORT
void ws_buffer_free(Buffer* buffer);
QPAUTILIZATIONSHARED_EXPORT
void ws_buffer_assure_space(Buffer* buffer, gsize space);
QPAUTILIZATIONSHARED_EXPORT
void ws_buffer_append(Buffer* buffer, guint8 *from, gsize bytes);
QPAUTILIZATIONSHARED_EXPORT
void ws_buffer_remove_start(Buffer* buffer, gsize bytes);

#ifdef SOME_FUNCTIONS_ARE_DEFINES
# define ws_buffer_clean(buffer) ws_buffer_remove_start((buffer), ws_buffer_length(buffer))
# define ws_buffer_increase_length(buffer,bytes) (buffer)->first_free += (bytes)
# define ws_buffer_length(buffer) ((buffer)->first_free - (buffer)->start)
# define ws_buffer_start_ptr(buffer) ((buffer)->data + (buffer)->start)
# define ws_buffer_end_ptr(buffer) ((buffer)->data + (buffer)->first_free)
# define ws_buffer_append_buffer(buffer,src_buffer) ws_buffer_append((buffer), ws_buffer_start_ptr(src_buffer), ws_buffer_length(src_buffer))
#else
 void ws_buffer_clean(Buffer* buffer);
 void ws_buffer_increase_length(Buffer* buffer, unsigned int bytes);
 gsize ws_buffer_length(Buffer* buffer);
 guint8* ws_buffer_start_ptr(Buffer* buffer);
 guint8* ws_buffer_end_ptr(Buffer* buffer);
 void ws_buffer_append_buffer(Buffer* buffer, Buffer* src_buffer);
#endif




#endif // BUFFER_H
