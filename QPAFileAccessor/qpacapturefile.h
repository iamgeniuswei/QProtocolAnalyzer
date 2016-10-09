#ifndef QPACAPTUREFILE_H
#define QPACAPTUREFILE_H
#include <QObject>
#include "epan-int.h"
#include <memory>
#include "wtap_pkthdr.h"
#include "wtap.h"
#include "frame_data.h"
#include "frame_data_sequence.h"
#include "column-info.h"
#include "epan_dissect.h"


/** Return values from functions that only can succeed or fail. */
typedef enum {
    CF_OK,      /**< operation succeeded */
    CF_ERROR    /**< operation got an error (function may provide err with details) */
} cf_status_t;
/** Return values from functions that read capture files. */
typedef enum {
    CF_READ_OK,      /**< operation succeeded */
    CF_READ_ERROR,   /**< operation got an error (function may provide err with details) */
    CF_READ_ABORTED  /**< operation aborted by user */
} cf_read_status_t;
/** Return values from functions that write out packets. */
typedef enum {
    CF_WRITE_OK,      /**< operation succeeded */
    CF_WRITE_ERROR,   /**< operation got an error (function may provide err with details) */
    CF_WRITE_ABORTED  /**< operation aborted by user */
} cf_write_status_t;
/** Return values from functions that print sets of packets. */
typedef enum {
    CF_PRINT_OK,            /**< print operation succeeded */
    CF_PRINT_OPEN_ERROR,    /**< print operation failed while opening printer */
    CF_PRINT_WRITE_ERROR    /**< print operation failed while writing to the printer */
} cf_print_status_t;

/*callback function flag. */
typedef enum {
    cf_cb_file_opened,
    cf_cb_file_closing,
    cf_cb_file_closed,
    cf_cb_file_read_started,
    cf_cb_file_read_finished,
    cf_cb_file_reload_started,
    cf_cb_file_reload_finished,
    cf_cb_file_rescan_started,
    cf_cb_file_rescan_finished,
    cf_cb_file_retap_started,
    cf_cb_file_retap_finished,
    cf_cb_file_fast_save_finished,
    cf_cb_packet_selected,
    cf_cb_packet_unselected,
    cf_cb_field_unselected,
    cf_cb_file_save_started,
    cf_cb_file_save_finished,
    cf_cb_file_save_failed,
    cf_cb_file_save_stopped,
    cf_cb_file_export_specified_packets_started,
    cf_cb_file_export_specified_packets_finished,
    cf_cb_file_export_specified_packets_failed,
    cf_cb_file_export_specified_packets_stopped
} cf_cbs;
typedef void (*cf_callback_t) (gint event, gpointer data, gpointer user_data);



/* Current state of file. */
typedef enum {
  FILE_CLOSED,                  /* No file open */
  FILE_READ_IN_PROGRESS,        /* Reading a file we've opened */
  FILE_READ_ABORTED,            /* Read aborted by user */
  FILE_READ_DONE                /* Read completed */
} file_state;

/* Character set for text search. */
typedef enum {
  SCS_NARROW_AND_WIDE,
  SCS_NARROW,
  SCS_WIDE
  /* add EBCDIC when it's implemented */
} search_charset_t;

#ifdef WANT_PACKET_EDITOR
/* XXX, where this struct should go? */
typedef struct {
  struct wtap_pkthdr phdr; /**< Modified packet header */
  char *pd;                /**< Modified packet data */
} modified_frame_data;
#endif

typedef enum {
  SD_FORWARD,
  SD_BACKWARD
} search_direction;


struct dfilter_t{

};

struct field_info{

};

struct packet_range_t{

};

struct print_args_t{

};

struct match_data{

};

typedef struct _capture_file
{
    std::shared_ptr<epan_t> epan;
    file_state state;
    std::string filename;
    std::string source;
    bool is_tempfile;
    bool unsaved_changes;
    bool stop_flag;
    qint64 f_datalen;
    qint16 cd_t;
    quint32 open_type;
    bool iscompressed;
    qint32 lnk_t;
    std::vector<std::shared_ptr<void>> linktypes;
    qint32 count;
    quint64 packet_comment_count;
    quint32 displayed_count;
    quint32 marked_count;
    quint32 ignored_count;
    quint32 ref_time_count;
    bool drops_known;
    quint32 drops;
    nstime_t elapsed_time;
    bool has_snap;
    qint32 snap;
    std::shared_ptr<wtap> wth;
    std::shared_ptr<dfilter_t> rfcode;
    std::shared_ptr<dfilter_t> dfcode;
    std::string dfilter;
    bool redissecting;
    //search
    std::string sfilter;
    bool hex;
    bool string;
    bool summary_data;
    bool decode_data;
    bool packet_data;
    quint32 search_pos;
    bool case_type;
    search_charset_t scs_type;
    search_direction dir;
    bool search_in_progress;
    //packet data;
    wtap_pkthdr phdr;
    Buffer buf;
    //frames
    std::shared_ptr<frame_data_sequence> frames;
    quint32 first_displayed;
    quint32 last_displayed;
    column_info cinfo;
    bool columns_changed;
    std::shared_ptr<frame_data> current_frame;
    qint32 current_row;
    std::shared_ptr<epan_dissect_t> edt;
    std::shared_ptr<field_info> finfo_selected;
    //FIXME:
    void* window;
    quint32 computed_elapsed;
    quint32 cum_bytes;
    std::shared_ptr<const frame_data> ref;
    std::shared_ptr<frame_data> prev_dis;
    std::shared_ptr<frame_data> prev_cap;
} capture_file;

extern void ws_init_capture_file();

#endif // QPACAPTUREFILE_H
