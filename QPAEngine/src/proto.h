/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   proto.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:00 PM
 */

#ifndef PROTO_H
#define PROTO_H
#include <glib-2.0/glib.h>

/* Structure for information about a protocol */
typedef struct _protocol {
	const char *name;               /* long description */
	const char *short_name;         /* short description */
	const char *filter_name;        /* name of this protocol in filters */
	GPtrArray  *fields;             /* fields for this protocol */
	int         proto_id;           /* field ID for this protocol */
	gboolean    is_enabled;         /* TRUE if protocol is enabled */
	gboolean    enabled_by_default; /* TRUE if protocol is enabled by default */
	gboolean    can_toggle;         /* TRUE if is_enabled can be changed */
	int         parent_proto_id;    /* Used to identify "pino"s (Protocol In Name Only).
                                       For dissectors that need a protocol name so they
                                       can be added to a dissector table, but use the
                                       parent_proto_id for things like enable/disable */
	GList      *heur_list;          /* Heuristic dissectors associated with this protocol */
}protocol_t;


/** @defgroup prototree The Protocol Tree
 *
 * Dissectors use proto_tree_add_* to add items to the protocol tree. In
 * most cases you'll want to use proto_tree_add_item().
 *
 * @{
 */

/** The header-field index for the special text pseudo-field. Exported by libwireshark.dll */
extern int hf_text_only;

/** the maximum length of a protocol field string representation */
#define ITEM_LABEL_LENGTH	240

#define ITEM_LABEL_UNKNOWN_STR	"Unknown"

struct expert_field;

/** Make a const value_string[] look like a _value_string pointer, used to set header_field_info.strings */
#define VALS(x)	(const struct _value_string*)(x)

/** Make a const val64_string[] look like a _val64_string pointer, used to set header_field_info.strings */
#define VALS64(x)   (const struct _val64_string*)(x)

/** Something to satisfy checkAPIs when you have a pointer to a value_string_ext (e.g., one built with value_string_ext_new()) */
#define VALS_EXT_PTR(x) (x)

/** Make a const true_false_string[] look like a _true_false_string pointer, used to set header_field_info.strings */
#define TFS(x)	(const struct true_false_string*)(x)

typedef void (*custom_fmt_func_t)(gchar *, guint32);

typedef void (*custom_fmt_func_64_t)(gchar *, guint64);

/** Make a custom format function pointer look like a void pointer. Used to set header_field_info.strings.
 *
 * We cast to gsize first, which 1) is guaranteed to be wide enough to
 * hold a pointer and 2) lets us side-step warnings about casting function
 * pointers to 'void *'. This violates ISO C but should be fine on POSIX
 * and Windows.
 */
#define CF_FUNC(x) ((const void *) (gsize) (x))

/** Make a const range_string[] look like a _range_string pointer, used to set
 * header_field_info.strings */
#define RVALS(x) (const struct _range_string*)(x)

/** Cast a ft_framenum_type_t, used to set header_field_info.strings */
#define FRAMENUM_TYPE(x) GINT_TO_POINTER(x)


/** Function used for reporting errors in dissectors; it throws a
 * DissectorError exception, with the string passed as an argument
 * as the message for the exception, so that it can show up in
 * the Info column and the protocol tree.
 *
 * If that string is dynamically allocated, it should be allocated with
 * wmem_alloc() with wmem_packet_scope(); using wmem_strdup_printf() would work.
 *
 * If the WIRESHARK_ABORT_ON_DISSECTOR_BUG environment variable is set,
 * it will call abort(), instead, to make it easier to get a stack trace.
 *
 * @param message string to use as the message
 */
extern void proto_report_dissector_bug(const char *message);

#define REPORT_DISSECTOR_BUG(message)  \
	proto_report_dissector_bug(message)

/** Macro used to provide a hint to static analysis tools.
 * (Currently only Visual C++.)
 */
#if _MSC_VER >= 1400
/* XXX - Is there a way to say "quit checking at this point"? */
#define __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(expression) \
  ; __analysis_assume(expression);
#else
#define __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(expression)
#endif

/** Macro used for assertions in dissectors; it doesn't abort, it just
 * throws a DissectorError exception, with the assertion failure
 * message as a parameter, so that it can show up in the protocol tree.
 *
 * NOTE: this should only be used to detect bugs in the dissector (e.g., logic
 * conditions that shouldn't happen).  It should NOT be used for showing
 * that a packet is malformed.  For that, use expert_infos instead.
 *
 * @param s expression to test in the assertion
 */

#define __DISSECTOR_ASSERT_STRINGIFY(s)	# s

#define __DISSECTOR_ASSERT(expression, file, lineno)  \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: failed assertion \"%s\"", \
        file, lineno, __DISSECTOR_ASSERT_STRINGIFY(expression))))

#define __DISSECTOR_ASSERT_HINT(expression, file, lineno, hint)  \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: failed assertion \"%s\" (%s)", \
        file, lineno, __DISSECTOR_ASSERT_STRINGIFY(expression), hint)))

#define DISSECTOR_ASSERT(expression)  \
  ((void) ((expression) ? (void)0 : \
   __DISSECTOR_ASSERT (expression, __FILE__, __LINE__))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(expression)

/**
 * Same as DISSECTOR_ASSERT(), but takes an extra 'hint' parameter that
 * can be used to provide information as to why the assertion might fail.
 *
 * @param expression expression to test in the assertion
 * @param hint message providing extra information
 */
#define DISSECTOR_ASSERT_HINT(expression, hint)  \
  ((void) ((expression) ? (void)0 : \
   __DISSECTOR_ASSERT_HINT (expression, __FILE__, __LINE__, hint))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(expression)

#if 0
/* win32: using a debug breakpoint (int 3) can be very handy while debugging,
 * as the assert handling of GTK/GLib is currently not very helpful */
#define DISSECTOR_ASSERT(expression)  \
{ if(!(expression)) _asm { int 3}; }
#endif

/** Same as DISSECTOR_ASSERT(), but will throw DissectorError exception
 * unconditionally, much like GLIB's g_assert_not_reached works.
 *
 * NOTE: this should only be used to detect bugs in the dissector (e.g., logic
 * conditions that shouldn't happen).  It should NOT be used for showing
 * that a packet is malformed.  For that, use expert_infos instead.
 *
 */
#define DISSECTOR_ASSERT_NOT_REACHED()  \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: failed assertion \"DISSECTOR_ASSERT_NOT_REACHED\"", \
        __FILE__, __LINE__)))

/** Compare two integers.
 *
 * This is functionally the same as `DISSECTOR_ASSERT(a op b)` except that it
 * will display the values of a and b upon failure.
 *
 *     DISSECTOR_ASSERT_CMPINT(a, ==, b);
 *     DISSECTOR_ASSERT_CMPINT(min, <=, max);
 *
 * This function can currently compare values that fit inside a gint64.
 *
 * WARNING: The number of times the arguments are evaluated is undefined.  Do
 * not use expressions with side effects as arguments.
 *
 * @param a  The first integer.
 * @param op Any binary operator.
 * @param b  The second integer.
 * @param type the type operator
 * @param fmt the fmt operator
 */
#define __DISSECTOR_ASSERT_CMPINT(a, op, b, type, fmt) \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: failed assertion " #a " " #op " " #b " (" fmt " " #op " " fmt ")", \
        __FILE__, __LINE__, (type)a, (type)b)))

#define DISSECTOR_ASSERT_CMPINT(a, op, b)  \
  ((void) ((a op b) ? (void)0 : \
   __DISSECTOR_ASSERT_CMPINT (a, op, b, gint64, "%" G_GINT64_MODIFIER "d"))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(a op b)

/** Like DISSECTOR_ASSERT_CMPINT() except the arguments are treated as
 * unsigned values.
 *
 * This function can currently compare values that fit inside a guint64.
 */
#define DISSECTOR_ASSERT_CMPUINT(a, op, b)  \
  ((void) ((a op b) ? (void)0 : \
   __DISSECTOR_ASSERT_CMPINT (a, op, b, guint64, "%" G_GINT64_MODIFIER "u"))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(a op b)

/** Like DISSECTOR_ASSERT_CMPUINT() except the values are displayed in
 * hexadecimal upon assertion failure.
 */
#define DISSECTOR_ASSERT_CMPUINTHEX(a, op, b)  \
  ((void) ((a op b) ? (void)0 : \
   __DISSECTOR_ASSERT_CMPINT (a, op, b, guint64, "0x%" G_GINT64_MODIFIER "X"))) \
  __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(a op b)

/*
 * This is similar to DISSECTOR_ASSERT(hfinfo->type == type) except that
 * it will report the name of the field with the wrong type as well as
 * the type.
 *
 * @param hfinfo  The hfinfo for the field being tested
 * @param type    The type it's expected to have
 */
#define __DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, t) \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: field %s is not of type "#t, \
        __FILE__, __LINE__, (hfinfo)->abbrev)))

#define DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, t)  \
  ((void) (((hfinfo)->type == t) ? (void)0 : \
   __DISSECTOR_ASSERT_FIELD_TYPE ((hfinfo), t))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT((hfinfo)->type == t)

#define DISSECTOR_ASSERT_FIELD_TYPE_IS_INTEGRAL(hfinfo)  \
  ((void) ((IS_FT_INT((hfinfo)->type) || \
            IS_FT_UINT((hfinfo)->type)) ? (void)0 : \
   REPORT_DISSECTOR_BUG( \
     wmem_strdup_printf(wmem_packet_scope(), \
         "%s:%u: field %s is not of type FT_CHAR or an FT_{U}INTn type", \
         __FILE__, __LINE__, (hfinfo)->abbrev)))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT(IS_FT_INT((hfinfo)->type) || \
                                           IS_FT_UINT((hfinfo)->type))

#define __DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING(hfinfo) \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: field %s is not of type FT_STRING, FT_STRINGZ, or FT_STRINGZPAD", \
        __FILE__, __LINE__, (hfinfo)->abbrev)))

#define DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING(hfinfo)  \
  ((void) (((hfinfo)->type == FT_STRING || (hfinfo)->type == FT_STRINGZ || \
            (hfinfo)->type == FT_STRINGZPAD) ? (void)0 : \
   __DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING ((hfinfo)))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT((hfinfo)->type == FT_STRING || \
                                           (hfinfo)->type == FT_STRINGZ || \
                                           (hfinfo)->type == FT_STRINGZPAD)

#define __DISSECTOR_ASSERT_FIELD_TYPE_IS_TIME(hfinfo) \
  (REPORT_DISSECTOR_BUG( \
    wmem_strdup_printf(wmem_packet_scope(), \
        "%s:%u: field %s is not of type FT_ABSOLUTE_TIME or FT_RELATIVE_TIME", \
        __FILE__, __LINE__, (hfinfo)->abbrev)))

#define DISSECTOR_ASSERT_FIELD_TYPE_IS_TIME(hfinfo)  \
  ((void) (((hfinfo)->type == FT_ABSOLUTE_TIME || \
            (hfinfo)->type == FT_RELATIVE_TIME) ? (void)0 : \
   __DISSECTOR_ASSERT_FIELD_TYPE_IS_TIME ((hfinfo)))) \
   __DISSECTOR_ASSERT_STATIC_ANALYSIS_HINT((hfinfo)->type == FT_ABSOLUTE_TIME || \
                                           (hfinfo)->type == FT_RELATIVE_TIME)

/*
 * The encoding of a field of a particular type may involve more
 * than just whether it's big-endian or little-endian and its size.
 *
 * For integral values, that's it, as 99.9999999999999% of the machines
 * out there are 2's complement binary machines with 8-bit bytes,
 * so the protocols out there expect that and, for example, any Unisys
 * 2200 series machines out there just have to translate between 2's
 * complement and 1's complement (and nobody's put any IBM 709x's on
 * any networks lately :-)).
 *
 * However:
 *
 *	for floating-point numbers, in addition to IEEE decimal
 *	floating-point, there's also IBM System/3x0 and PDP-11/VAX
 *	floating-point - most protocols use IEEE binary, but DCE RPC
 *	can use other formats if that's what the sending host uses;
 *
 *	for character strings, there are various character encodings
 *	(various ISO 646 sets, ISO 8859/x, various other national
 *	standards, various DOS and Windows encodings, various Mac
 *	encodings, UTF-8, UTF-16, other extensions to ASCII, EBCDIC,
 *	etc.);
 *
 *	for absolute times, there's UNIX time_t, UNIX time_t followed
 *	by 32-bit microseconds, UNIX time_t followed by 32-bit
 *	nanoseconds, DOS date/time, Windows FILETIME, NTP time, etc..
 *
 * We might also, in the future, want to allow a field specifier to
 * indicate the encoding of the field, or at least its default
 * encoding, as most fields in most protocols always use the
 * same encoding (although that's not true of all fields, so we
 * still need to be able to specify that at run time).
 *
 * So, for now, we define ENC_BIG_ENDIAN and ENC_LITTLE_ENDIAN as
 * bit flags, to be combined, in the future, with other information
 * to specify the encoding in the last argument to
 * proto_tree_add_item(), and possibly to specify in a field
 * definition (e.g., ORed in with the type value).
 *
 * Currently, proto_tree_add_item() treats its last argument as a
 * Boolean - if it's zero, the field is big-endian, and if it's non-zero,
 * the field is little-endian - and other code in epan/proto.c does
 * the same.  We therefore define ENC_BIG_ENDIAN as 0x00000000 and
 * ENC_LITTLE_ENDIAN as 0x80000000 - we're using the high-order bit
 * so that we could put a field type and/or a value such as a character
 * encoding in the lower bits.
 */
#define ENC_BIG_ENDIAN		0x00000000
#define ENC_LITTLE_ENDIAN	0x80000000

#if G_BYTE_ORDER == G_LITTLE_ENDIAN
    #define ENC_HOST_ENDIAN ENC_LITTLE_ENDIAN
#else
    #define ENC_HOST_ENDIAN ENC_BIG_ENDIAN
#endif

/*
 * Historically FT_TIMEs were only timespecs; the only question was whether
 * they were stored in big- or little-endian format.
 *
 * For backwards compatibility, we interpret an encoding of 1 as meaning
 * "little-endian timespec", so that passing TRUE is interpreted as that.
 *
 * We now support:
 *
 *  ENC_TIME_TIMESPEC - 8 bytes; the first 4 bytes are seconds and the
 *  next 4 bytes are nanoseconds.  If the time is absolute, the seconds
 *  are seconds since the UN*X epoch (1970-01-01 00:00:00 UTC).  (I.e.,
 *  a UN*X struct timespec with a 4-byte time_t.)
 *
 *  ENC_TIME_NTP - 8 bytes; the first 4 bytes are seconds since the NTP
 *  epoch (1901-01-01 00:00:00 GMT) and the next 4 bytes are 1/2^32's of
 *  a second since that second.  (I.e., a 64-bit count of 1/2^32's of a
 *  second since the NTP epoch, with the upper 32 bits first and the
 *  lower 32 bits second, even when little-endian.)
 *
 *  ENC_TIME_TOD - 8 bytes, as a count of microseconds since the System/3x0
 *  and z/Architecture epoch (1900-01-01 00:00:00 GMT).
 *
 *  ENC_TIME_RTPS - 8 bytes; the first 4 bytes are seconds since the UN*X
 *  epoch and the next 4 bytes are are 1/2^32's of a second since that
 *  second.  (I.e., it's the offspring of a mating between UN*X time and
 *  NTP time.)  It's used by the Object Management Group's Real-Time
 *  Publish-Subscribe Wire Protocol for the Data Distribution Service.
 *
 *  ENC_TIME_TIMEVAL - 8 bytes; the first 4 bytes are seconds and the
 *  next 4 bytes are microseconds.  If the time is absolute, the seconds
 *  are seconds since the UN*X epoch.  (I.e., a UN*X struct timeval with
 *  a 4-byte time_t.)
 *
 *  ENC_TIME_SECS - 4 to 8 bytes, representing a value in seconds.
 *  If the time is absolute, it's seconds since the UN*X epoch.
 *
 *  ENC_TIME_MSECS - 6 to 8 bytes, representing a value in milliseconds.
 *  If the time is absolute, it's milliseconds since the UN*X epoch.
 *
 *  ENC_TIME_SECS_NTP - 4 bytes, representing a count of seconds since
 *  the NTP epoch.  (I.e., seconds since the NTP epoch.)
 *
 *  ENC_TIME_RFC_3971 - 8 bytes, representing a count of 1/64ths of a
 *  second since the UN*X epoch; see section 5.3.1 "Timestamp Option"
 *  in RFC 3971.
 *
 *  ENC_TIME_MSEC_NTP - 4-8 bytes, representing a count of milliseconds since
 *  the NTP epoch.  (I.e., milliseconds since the NTP epoch.)
 */
#define ENC_TIME_TIMESPEC      0x00000000
#define ENC_TIME_NTP           0x00000002
#define ENC_TIME_TOD           0x00000004
#define ENC_TIME_RTPS          0x00000008
#define ENC_TIME_NTP_BASE_ZERO ENC_TIME_RTPS /* for backwards source compatibility */
#define ENC_TIME_TIMEVAL       0x00000010
#define ENC_TIME_SECS          0x00000012
#define ENC_TIME_MSECS         0x00000014
#define ENC_TIME_SECS_NTP      0x00000018
#define ENC_TIME_RFC_3971      0x00000020
#define ENC_TIME_MSEC_NTP      0x00000022


/*
 * Historically, the only place the representation mattered for strings
 * was with FT_UINT_STRINGs, where we had FALSE for the string length
 * being big-endian and TRUE for it being little-endian.
 *
 * We now have encoding values for the character encoding.  The encoding
 * values are encoded in all but the top bit (which is the byte-order
 * bit, required for FT_UINT_STRING and for UCS-2 and UTF-16 strings)
 * and the bottom bit (which we ignore for now so that programs that
 * pass TRUE for the encoding just do ASCII).  (The encodings are given
 * directly as even numbers in hex, so that make-init-lua.pl can just
 * turn them into numbers for use in init.lua.)
 *
 * We don't yet process ASCII and UTF-8 differently.  Ultimately, for
 * ASCII, all bytes with the 8th bit set should be mapped to some "this
 * is not a valid character" code point, as ENC_ASCII should mean "this
 * is ASCII, not some extended variant thereof".  We should also map
 * 0x00 to that as well - null-terminated and null-padded strings
 * never have NULs in them, but counted strings might.  (Either that,
 * or the values for strings should be counted, not null-terminated.)
 * For UTF-8, invalid UTF-8 sequences should be mapped to the same
 * code point.
 *
 * For display, perhaps we should also map control characters to the
 * Unicode glyphs showing the name of the control character in small
 * caps, diagonally.  (Unfortunately, those only exist for C0, not C1.)
 */
#define ENC_CHARENCODING_MASK		0x7FFFFFFE	/* mask out byte-order bits */
#define ENC_ASCII			0x00000000
#define ENC_UTF_8			0x00000002
#define ENC_UTF_16			0x00000004
#define ENC_UCS_2			0x00000006
#define ENC_UCS_4			0x00000008
#define ENC_ISO_8859_1			0x0000000A
#define ENC_ISO_8859_2			0x0000000C
#define ENC_ISO_8859_3			0x0000000E
#define ENC_ISO_8859_4			0x00000010
#define ENC_ISO_8859_5			0x00000012
#define ENC_ISO_8859_6			0x00000014
#define ENC_ISO_8859_7			0x00000016
#define ENC_ISO_8859_8			0x00000018
#define ENC_ISO_8859_9			0x0000001A
#define ENC_ISO_8859_10			0x0000001C
#define ENC_ISO_8859_11			0x0000001E
/* #define ENC_ISO_8859_12			0x00000020 ISO 8859-12 was abandoned */
#define ENC_ISO_8859_13			0x00000022
#define ENC_ISO_8859_14			0x00000024
#define ENC_ISO_8859_15			0x00000026
#define ENC_ISO_8859_16			0x00000028
#define ENC_WINDOWS_1250		0x0000002A
#define ENC_3GPP_TS_23_038_7BITS	0x0000002C
#define ENC_EBCDIC			0x0000002E
#define ENC_MAC_ROMAN			0x00000030
#define ENC_CP437			0x00000032
#define ENC_ASCII_7BITS			0x00000034
#define ENC_T61				0x00000036
#define ENC_EBCDIC_CP037		0x00000038

/*
 * TODO:
 *
 * These could probably be used by existing code:
 *
 *	"IBM MS DBCS"
 *	JIS C 6226
 *
 * As those are added, change code such as the code in packet-bacapp.c
 * to use them.
 */

/*
 * For protocols (FT_PROTOCOL), aggregate items with subtrees (FT_NONE),
 * opaque byte-array fields (FT_BYTES), and other fields where there
 * is no choice of encoding (either because it's "just a bucket
 * of bytes" or because the encoding is completely fixed), we
 * have ENC_NA (for "Not Applicable").
 */
#define ENC_NA			0x00000000

/* For cases where either native type or string encodings could both be
 * valid arguments, we need something to distinguish which one is being
 * passed as the argument, because ENC_BIG_ENDIAN and ENC_ASCII are both
 * 0x00000000. So we use ENC_STR_NUM or ENC_STR_HEX bit-or'ed with
 * ENC_ASCII and its ilk.
 */
/* this is for strings as numbers "12345" */
#define ENC_STR_NUM             0x01000000
/* this is for strings as hex "1a2b3c" */
#define ENC_STR_HEX             0x02000000
/* a convenience macro for either of the above */
#define ENC_STRING              0x03000000
/* mask out ENC_STR_* and related bits - should this replace ENC_CHARENCODING_MASK? */
#define ENC_STR_MASK            0x0000FFFE

/* for cases where the number is allowed to have a leading '+'/'-' */
/* this can't collide with ENC_SEP_* because they can be used simultaneously */
#define ENC_NUM_PREF    0x00200000

/* For cases where a string encoding contains hex, bit-or one or more
 * of these for the allowed separator(s), as well as with ENC_STR_HEX.
 * See hex_str_to_bytes_encoding() in epan/strutil.h for details.
 */
#define ENC_SEP_NONE    0x00010000
#define ENC_SEP_COLON   0x00020000
#define ENC_SEP_DASH    0x00040000
#define ENC_SEP_DOT   0x00080000
#define ENC_SEP_SPACE   0x00100000
/* a convenience macro for the above */
#define ENC_SEP_MASK    0x001F0000

/* For cases where a string encoding contains a timestamp, use one
 * of these (but only one). These values can collide with above, because
 * you can't do both at the same time.
 */
#define ENC_ISO_8601_DATE       0x00010000
#define ENC_ISO_8601_TIME       0x00020000
#define ENC_ISO_8601_DATE_TIME  0x00030000
#define ENC_RFC_822             0x00040000
#define ENC_RFC_1123            0x00080000
/* a convenience macro for the above - for internal use only */
#define ENC_STR_TIME_MASK       0x000F0000

/* Values for header_field_info.display */

/* For integral types, the display format is a BASE_* field_display_e value
 * possibly ORed with BASE_*_STRING */

/** FIELD_DISPLAY_E_MASK selects the field_display_e value. */
#define FIELD_DISPLAY_E_MASK 0xFF

/*
 * Note that this enum values are parsed in make-init-lua.pl so make sure
 * any changes here still makes valid entries in init.lua.
 */
typedef enum {
/* Integral types */
	BASE_NONE    = 0,   /**< none */
	BASE_DEC     = 1,   /**< decimal */
	BASE_HEX     = 2,   /**< hexadecimal */
	BASE_OCT     = 3,   /**< octal */
	BASE_DEC_HEX = 4,   /**< decimal (hexadecimal) */
	BASE_HEX_DEC = 5,   /**< hexadecimal (decimal) */
	BASE_CUSTOM  = 6,   /**< call custom routine (in ->strings) to format */

/* Float types */
	BASE_FLOAT   = BASE_NONE, /**< decimal-format float */

/* String types */
	STR_ASCII    = 0,   /**< shows non-printable ASCII characters as C-style escapes */
	/* XXX, support for format_text_wsp() ? */
	STR_UNICODE  = 7,   /**< shows non-printable UNICODE characters as \\uXXXX (XXX for now non-printable characters display depends on UI) */

/* Byte separators */
	SEP_DOT      = 8,   /**< hexadecimal bytes with a period (.) between each byte */
	SEP_DASH     = 9,   /**< hexadecimal bytes with a dash (-) between each byte */
	SEP_COLON    = 10,  /**< hexadecimal bytes with a colon (:) between each byte */
	SEP_SPACE    = 11,  /**< hexadecimal bytes with a space between each byte */

/* Address types */
	BASE_NETMASK = 12,  /**< Used for IPv4 address that shouldn't be resolved (like for netmasks) */

/* Port types */
	BASE_PT_UDP  = 13,  /**< UDP port */
	BASE_PT_TCP  = 14,  /**< TCP port */
	BASE_PT_DCCP = 15,  /**< DCCP port */
	BASE_PT_SCTP = 16   /**< SCTP port */
} field_display_e;

#define FIELD_DISPLAY(d) ((d) & FIELD_DISPLAY_E_MASK)

/* Following constants have to be ORed with a field_display_e when dissector
 * want to use specials value-string MACROs for a header_field_info */
#define BASE_RANGE_STRING       0x0100
#define BASE_EXT_STRING         0x0200
#define BASE_VAL64_STRING       0x0400
#define BASE_ALLOW_ZERO         0x0800  /**< Display <none> instead of <MISSING> for zero sized byte array */
#define BASE_UNIT_STRING        0x1000  /**< Add unit text to the field value */
#define BASE_NO_DISPLAY_VALUE   0x2000  /**< Just display the field name with no value.  Intended for
                                             byte arrays or header fields above a subtree */
#define BASE_PROTOCOL_INFO      0x4000  /**< protocol_t in [FIELDCONVERT].  Internal use only. */
#define BASE_SPECIAL_VALS    0x8000  /**< field will not display "Unknown" if value_string match is not found */

/** BASE_ values that cause the field value to be displayed twice */
#define IS_BASE_DUAL(b) ((b)==BASE_DEC_HEX||(b)==BASE_HEX_DEC)

/** BASE_PT_ values display decimal and transport port service name */
#define IS_BASE_PORT(b) (((b)==BASE_PT_UDP||(b)==BASE_PT_TCP||(b)==BASE_PT_DCCP||(b)==BASE_PT_SCTP))

/* For FT_ABSOLUTE_TIME, the display format is an absolute_time_display_e
 * as per time_fmt.h. */

typedef enum {
    HF_REF_TYPE_NONE,       /**< Field is not referenced */
    HF_REF_TYPE_INDIRECT,   /**< Field is indirectly referenced (only applicable for FT_PROTOCOL) via. its child */
    HF_REF_TYPE_DIRECT      /**< Field is directly referenced */
} hf_ref_type;

#endif /* PROTO_H */

