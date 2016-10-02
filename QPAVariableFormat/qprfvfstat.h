#ifndef QPRFVFSTAT_H
#define QPRFVFSTAT_H
/*
 * For registering file types that we can open.
 *
 * Each file type has an open routine and an optional list of extensions
 * the file might have.
 *
 * The open routine should return:
 *
 *      WTAP_OPEN_ERROR on an I/O error;
 *
 *      WTAP_OPEN_MINE if the file it's reading is one of the types
 *      it handles;
 *
 *      WTAP_OPEN_NOT_MINE if the file it's reading isn't one of the
 *      types it handles.
 *
 * If the routine handles this type of file, it should set the "file_type"
 * field in the "struct wtap" to the type of the file.
 *
 * Note that the routine does not have to free the private data pointer on
 * error. The caller takes care of that by calling wtap_close on error.
 * (See https://bugs.wireshark.org/bugzilla/show_bug.cgi?id=8518)
 *
 * However, the caller does have to free the private data pointer when
 * returning WTAP_OPEN_NOT_MINE, since the next file type will be called
 * and will likely just overwrite the pointer.
 */
typedef enum {
    WTAP_OPEN_NOT_MINE = 0,
    WTAP_OPEN_MINE = 1,
    WTAP_OPEN_ERROR = -1
} wtap_open_return_val;

typedef enum {
    OPEN_INFO_MAGIC = 0,
    OPEN_INFO_HEURISTIC = 1
} wtap_open_type;
#endif // QPRFVFSTAT_H
