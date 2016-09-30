#include "wtap.h"

struct wtap_pkthdr *
wtap_phdr(wtap *wth)
{
    return &wth->phdr;
}

guint8 *
wtap_buf_ptr(wtap *wth)
{
    return ws_buffer_start_ptr(wth->frame_buffer);
}
