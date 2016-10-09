#ifndef EPANINT_H
#define EPANINT_H
#include "nstime.h"
#include "frame_data.h"
struct epan_session {
    void *data;

    const nstime_t *(*get_frame_ts)(void *data, guint32 frame_num);
    const char *(*get_interface_name)(void *data, guint32 interface_id);
    const char *(*get_user_comment)(void *data, const frame_data *fd);
};

typedef struct epan_session epan_t;
#endif // EPANINT_H
