#ifndef QPFILESTAT_H
#define QPFILESTAT_H
#include <glib.h>
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

#endif // QPFILESTAT_H
