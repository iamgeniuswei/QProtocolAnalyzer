#ifndef FRAME_DATA_H
#define FRAME_DATA_H
#include <glib.h>
#include "nstime.h"
#include <memory>

/* Types of character encodings */
typedef enum {
  PACKET_CHAR_ENC_CHAR_ASCII     = 0, /* ASCII */
  PACKET_CHAR_ENC_CHAR_EBCDIC    = 1  /* EBCDIC */
} packet_char_enc;

class wtap_pkthdr;

/*
 * refactor of struct frame_data
 *
 *
 *
 *
 */
class frame_data
{
public:
    frame_data();
    void frame_data_init(quint32 _num, \
                         const std::shared_ptr<wtap_pkthdr> _phdr, \
                         qint64 _offset, \
                         quint32 _cum_bytes);

private:
    std::vector<std::shared_ptr<void>> pfd;
    quint32 num = 0;
    quint32 pkt_len = 0;
    quint32 cap_len = 0;
    quint32 cum_bytes = 0;
    quint32 file_off= 0;
    quint32 subnum = 0;
    quint32 lnk_t = 0;
    quint32 passed_dfilter = 0;
    quint32 dependent_of_displayed = 0;
    quint32 encoding = PACKET_CHAR_ENC_CHAR_ASCII;
    quint32 visited = 0;
    quint32 marked = 0;
    quint32 ref_time = 0;
    quint32 ignored = 0;
    quint32 has_ts = 0;
    quint32 has_phdr_comment = 0;
    quint32 has_user_comment = 0;
    quint16 tsprec = 0;
    std::shared_ptr<void> color_filter;
    nstime_t abs_ts;
    nstime_t shift_offset;
    quint32 frame_ref_num = 0;
    quint32 prev_dis_num = 0;
};



//typedef struct _frame_data {
//  GSList      *pfd;
//  guint32      num;
//  guint32      pkt_len;
//  guint32      cap_len;
//  guint32      cum_bytes;
//  gint64       file_off;
//  guint16      subnum;
//  gint16       lnk_t;
//  struct {
//    unsigned int passed_dfilter : 1;
//    unsigned int dependent_of_displayed : 1;
//    /* Do NOT use packet_char_enc enum here: MSVC compiler does not handle an enum in a bit field properly */
//    unsigned int encoding       : 1;
//    unsigned int visited        : 1;
//    unsigned int marked         : 1;
//    unsigned int ref_time       : 1;
//    unsigned int ignored        : 1;
//    unsigned int has_ts         : 1;
//    unsigned int has_phdr_comment : 1;
//    unsigned int has_user_comment : 1;
//  } flags;
//  gint16       tsprec;

//  const void *color_filter;

//  nstime_t     abs_ts;
//  nstime_t     shift_offset;
//  guint32      frame_ref_num;
//  guint32      prev_dis_num;
//} frame_data;

extern void frame_data_init(frame_data *fdata, guint32 num,
                const struct wtap_pkthdr *phdr, gint64 offset,
                guint32 cum_bytes);



#endif // FRAME_DATA_H
