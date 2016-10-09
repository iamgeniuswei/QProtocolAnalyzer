#include "buffer.h"
#include <string.h>
#include <QDebug>
constexpr quint32 maxSpace(){return 1024000;}
///* Initializes a buffer with a certain amount of allocated space */
//void
//ws_buffer_init(Buffer* buffer, gsize space)
//{
//    buffer->data = (guint8*)g_malloc(space);
//    buffer->allocated = space;
//    buffer->start = 0;
//    buffer->first_free = 0;
//}

///* Frees the memory used by a buffer */
//void
//ws_buffer_free(Buffer* buffer)
//{
//    g_free(buffer->data);
//    buffer->data = NULL;
//}

///* Assures that there are 'space' bytes at the end of the used space
//    so that another routine can copy directly into the buffer space. After
//    doing that, the routine will also want to run
//    ws_buffer_increase_length(). */
//void
//ws_buffer_assure_space(Buffer* buffer, gsize space)
//{
//    gsize available_at_end = buffer->allocated - buffer->first_free;
//    gsize space_used;
//    gboolean space_at_beginning;

//    /* If we've got the space already, good! */
//    if (space <= available_at_end) {
//        return;
//    }

//    /* Maybe we don't have the space available at the end, but we would
//        if we moved the used space back to the beginning of the
//        allocation. The buffer could have become fragmented through lots
//        of calls to ws_buffer_remove_start(). I'm using buffer->start as the
//        same as 'available_at_start' in this comparison. */

//    /* or maybe there's just no more room. */

//    space_at_beginning = buffer->start >= space;
//    if (space_at_beginning || buffer->start > 0) {
//        space_used = buffer->first_free - buffer->start;
//        /* this memory copy better be safe for overlapping memory regions! */
//        memmove(buffer->data, buffer->data + buffer->start, space_used);
//        buffer->start = 0;
//        buffer->first_free = space_used;
//    }
//    /*if (buffer->start >= space) {*/
//    if (space_at_beginning) {
//        return;
//    }

//    /* We'll allocate more space */
//    buffer->allocated += space + 1024;
//    buffer->data = (guint8*)g_realloc(buffer->data, buffer->allocated);
//}

//void
//ws_buffer_append(Buffer* buffer, guint8 *from, gsize bytes)
//{
//    ws_buffer_assure_space(buffer, bytes);
//    memcpy(buffer->data + buffer->first_free, from, bytes);
//    buffer->first_free += bytes;
//}

//void
//ws_buffer_remove_start(Buffer* buffer, gsize bytes)
//{
//    if (buffer->start + bytes > buffer->first_free) {
//        g_error("ws_buffer_remove_start trying to remove %" G_GINT64_MODIFIER "u bytes. s=%" G_GINT64_MODIFIER "u ff=%" G_GINT64_MODIFIER "u!\n",
//            (guint64)bytes, (guint64)buffer->start,
//            (guint64)buffer->first_free);
//        /** g_error() does an abort() and thus never returns **/
//    }
//    buffer->start += bytes;

//    if (buffer->start == buffer->first_free) {
//        buffer->start = 0;
//        buffer->first_free = 0;
//    }
//}


//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//void
//ws_buffer_clean(Buffer* buffer)
//{
//    ws_buffer_remove_start(buffer, ws_buffer_length(buffer));
//}
//#endif

//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//void
//ws_buffer_increase_length(Buffer* buffer, gsize bytes)
//{
//    buffer->first_free += bytes;
//}
//#endif

//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//gsize
//ws_buffer_length(Buffer* buffer)
//{
//    return buffer->first_free - buffer->start;
//}
//#endif

//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//guint8 *
//ws_buffer_start_ptr(Buffer* buffer)
//{
//    return buffer->data + buffer->start;
//}
//#endif

//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//guint8 *
//ws_buffer_end_ptr(Buffer* buffer)
//{
//    return buffer->data + buffer->first_free;
//}
//#endif

//#ifndef SOME_FUNCTIONS_ARE_DEFINES
//void
//ws_buffer_append_buffer(Buffer* buffer, Buffer* src_buffer)
//{
//    ws_buffer_append(buffer, ws_buffer_start_ptr(src_buffer), ws_buffer_length(src_buffer));
//}
//#endif

Buffer::Buffer():
    data(nullptr),
    allocated(0),
    start(0),
    first_free(0)
{}

Buffer::~Buffer()
{
    qDebug() << "delete right...";
    ws_buffer_free();
}

void Buffer::ws_buffer_init(quint32 space)
{
    if(space >0 && space <= maxSpace())
    {
        data = new (std::nothrow) quint8 [space];
        if(nullptr != data)
            allocated = space;
        start = 0;
        first_free = 0;
    }
}

void Buffer::ws_buffer_free()
{
    delete [] data;
    data = nullptr;
}

void Buffer::ws_buffer_assure_space(quint32 space)
{
    if(space < 0 || space > maxSpace())
        return;
    quint32 available_at_end = allocated - first_free;
    if(space < available_at_end)
        return;
    /* Maybe we don't have the space available at the end, but we would
        if we moved the used space back to the beginning of the
        allocation. The buffer could have become fragmented through lots
        of calls to ws_buffer_remove_start(). I'm using buffer->start as the
        same as 'available_at_start' in this comparison. */

    /* or maybe there's just no more room. */
    bool space_at_beginning = start >= space;
    quint32 space_used = 0;
    if(space_at_beginning || start > 0)
    {
        space_used = first_free - start;
        memmove(data, data+start, space_used);
        start = 0;
        first_free = space_used;
    }
    if(space_at_beginning)
        return;
    allocated += space + 1024;
    data = (quint8*)realloc(data, allocated);
}

void Buffer::ws_buffer_append(quint8 *from, quint32 bytes)
{

}

void Buffer::ws_buffer_remove_start(quint32 bytes)
{

}

void Buffer::ws_buffer_clean()
{

}

void Buffer::ws_buffer_increase_length(unsigned int bytes)
{

}

quint32 Buffer::ws_buffer_length()
{

}

quint8 *Buffer::ws_buffer_start_ptr()
{
    return data + start;
}

quint8 *Buffer::ws_buffer_end_ptr()
{

}

void Buffer::ws_buffer_append_buffer(Buffer *src)
{

}

quint8 *Buffer::dataPtr() const
{
    return data;
}

