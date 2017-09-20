/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPASkeletonDefine.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午9:02
 */

#ifndef QPASKELETONDEFINE_H
#define QPASKELETONDEFINE_H
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


#endif /* QPASKELETONDEFINE_H */

