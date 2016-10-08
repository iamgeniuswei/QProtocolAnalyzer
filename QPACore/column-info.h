#ifndef COLUMNINFO_H
#define COLUMNINFO_H
#include <glib.h>

/** Column expression */
typedef struct {
  const gchar **col_expr;     /**< Filter expression */
  gchar      **col_expr_val;  /**< Value for filter expression */
} col_expr_t;


typedef struct{
    gint                col_fmt;              /**< Format of column */
    gboolean           *fmt_matx;             /**< Specifies which formats apply to a column */
    gchar              *col_title;            /**< Column titles */
    gchar              *col_custom_field;     /**< Custom column field */
    gint                col_custom_occurrence;/**< Custom column field occurrence */
    GSList             *col_custom_field_ids; /**< Custom column field id */
    struct epan_dfilter *col_custom_dfilter;  /**< Compiled custom column field */
    const gchar        *col_data;             /**< Column data */
    gchar              *col_buf;              /**< Buffer into which to copy data for column */
    int                 col_fence;            /**< Stuff in column buffer before this index is immutable */
}col_item_t;

/** Column info */
typedef struct epan_column_info {
  const struct epan_session *epan;
  gint                num_cols;             /**< Number of columns */
  col_item_t         *columns;              /**< All column data */
  gint               *col_first;            /**< First column number with a given format */
  gint               *col_last;             /**< Last column number with a given format */
  col_expr_t          col_expr;             /**< Column expressions and values */
  gboolean            writable;             /**< writable or not @todo Are we still writing to the columns? */
  GRegex             *prime_regex;          /**< Used to prime custom columns */
}column_info;

#endif // COLUMNINFO_H
