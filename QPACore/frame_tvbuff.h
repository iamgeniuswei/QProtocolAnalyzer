#ifndef FRAME_TVBUFF_H
#define FRAME_TVBUFF_H
#include "tvbuff.h"
#include "frame_data.h"
#include "buffer.h"
extern tvbuff_t *frame_tvbuff_new(const std::shared_ptr<frame_data> fd, const guint8 *buf);

extern tvbuff_t *frame_tvbuff_new_buffer(const frame_data *fd, Buffer *buf);

extern tvbuff_t *file_tvbuff_new(const frame_data *fd, const guint8 *buf);

extern tvbuff_t *file_tvbuff_new_buffer(const frame_data *fd, Buffer *buf);
#endif // FRAME_TVBUFF_H
