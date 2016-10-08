#ifndef DEFINE_H
#define DEFINE_H
#include "ftypes.h"
/** information describing a header field */
struct header_field_info;
//typedef struct _header_field_info header_field_info;

/* For FT_ABSOLUTE_TIME, the display format is an absolute_time_display_e
 * as per time_fmt.h. */

typedef enum {
    HF_REF_TYPE_NONE,       /**< Field is not referenced */
    HF_REF_TYPE_INDIRECT,   /**< Field is indirectly referenced (only applicable for FT_PROTOCOL) via. its child */
    HF_REF_TYPE_DIRECT      /**< Field is directly referenced */
} hf_ref_type;


/** information describing a header field */
struct header_field_info {
    /* ---------- set by dissector --------- */
    const char		*name;           /**< [FIELDNAME] full name of this field */
    const char		*abbrev;         /**< [FIELDABBREV] abbreviated name of this field */
    enum ftenum		 type;           /**< [FIELDTYPE] field type, one of FT_ (from ftypes.h) */
    int			 display;        /**< [FIELDDISPLAY] one of BASE_, or field bit-width if FT_BOOLEAN and non-zero bitmask */
    const void		*strings;        /**< [FIELDCONVERT] value_string, val64_string, range_string or true_false_string,
                                      typically converted by VALS(), RVALS() or TFS().
                                      If this is an FT_PROTOCOL then it points to the
                                      associated protocol_t structure */
    guint64			 bitmask;        /**< [BITMASK] bitmask of interesting bits */
    const char		*blurb;          /**< [FIELDDESCR] Brief description of field */

    /* ------- set by proto routines (prefilled by HFILL macro, see below) ------ */
    int				     id;                /**< Field ID */
    int					 parent;            /**< parent protocol tree */
    hf_ref_type			 ref_type;          /**< is this field referenced by a filter */
    int                  same_name_prev_id; /**< ID of previous hfinfo with same abbrev */
    header_field_info	*same_name_next;    /**< Link to next hfinfo with same abbrev */
};



/** Used when registering many fields at once, using proto_register_field_array() */
typedef struct hf_register_info {
    int				*p_id;	/**< written to by register() function */
    header_field_info		hfinfo;	/**< the field info to be registered */
} hf_register_info;

/**
 * HFILL initializes all the "set by proto routines" fields in a
 * _header_field_info. If new fields are added or removed, it should
 * be changed as necessary.
 */
#define HFILL -1, 0, HF_REF_TYPE_NONE, -1, NULL

typedef enum {
/* Integral types */
    BASE_NONE    = 0,   /**< none */
    BASE_DEC     = 1,   /**< decimal */
    BASE_HEX     = 2,   /**< hexadecimal */
    BASE_OCT     = 3,   /**< octal */
    BASE_DEC_HEX = 4,   /**< decimal (hexadecimal) */
    BASE_HEX_DEC = 5,   /**< hexadecimal (decimal) */
    BASE_CUSTOM  = 6,   /**< call custom routine (in ->strings) to format */

/* String types */
    STR_ASCII    = BASE_NONE, /**< shows non-printable ASCII characters as C-style escapes */
    /* XXX, support for format_text_wsp() ? */
    STR_UNICODE  = 7,   /**< shows non-printable UNICODE characters as \\uXXXX (XXX for now non-printable characters display depends on UI) */

/* Byte types */
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


/* Expert Info and Display hf data */
typedef struct expert_field
{
    int ei;
    int hf;
} expert_field;


typedef struct expert_field_info {
    /* ---------- set by dissector --------- */
    const char       *name;
    int               group;
    int               severity;
    const gchar      *summary;

    /* ------- set by register routines (prefilled by EXPFILL macro, see below) ------ */
    int               id;
    const gchar      *protocol;
    int               orig_severity; /* Matches severity when registered, used to restore original severity
                      * if UAT severity entry is removed */
    hf_register_info  hf_info;

} expert_field_info;

typedef struct ei_register_info {
    expert_field      *ids;         /**< written to by register() function */
    expert_field_info  eiinfo;      /**< the field info to be registered */
} ei_register_info;

#define EI_INIT_EI -1
#define EI_INIT_HF -1
#define EI_INIT {EI_INIT_EI, EI_INIT_HF}


/* do not modify the PI_SEVERITY_MASK name - it's used by make-init-lua.pl */
/* expert severities */
#define PI_SEVERITY_MASK        0x00F00000	/**< mask usually for internal use only! */
/** Packet comment */
#define PI_COMMENT              0x00100000
/** Usual workflow, e.g. TCP connection establishing */
#define PI_CHAT                 0x00200000
/** Notable messages, e.g. an application returned an "unusual" error code like HTTP 404 */
#define PI_NOTE                 0x00400000
/** Warning, e.g. application returned an "unusual" error code */
#define PI_WARN                 0x00600000
/** Serious problems, e.g. a malformed packet */
#define PI_ERROR                0x00800000

/* do not modify the PI_GROUP_MASK name - it's used by make-init-lua.pl */
/* expert "event groups" */
#define PI_GROUP_MASK           0xFF000000	/**< mask usually for internal use only! */
/** The protocol field has a bad checksum, usually uses PI_WARN severity */
#define PI_CHECKSUM             0x01000000
/** The protocol field indicates a sequence problem (e.g. TCP window is zero) */
#define PI_SEQUENCE             0x02000000
/** The protocol field indicates a bad application response code (e.g. HTTP 404), usually PI_NOTE severity */
#define PI_RESPONSE_CODE        0x03000000
/** The protocol field indicates an application request (e.g. File Handle == xxxx), usually PI_CHAT severity */
#define PI_REQUEST_CODE         0x04000000
/** The data is undecoded, the protocol dissection is incomplete here, usually PI_WARN severity */
#define PI_UNDECODED            0x05000000
/** The protocol field indicates a reassemble (e.g. DCE/RPC defragmentation), usually PI_CHAT severity (or PI_ERROR) */
#define PI_REASSEMBLE           0x06000000
/** The packet data is malformed, the dissector has "given up", usually PI_ERROR severity */
#define PI_MALFORMED            0x07000000
/** A generic debugging message (shouldn't remain in production code!), usually PI_ERROR severity */
#define PI_DEBUG                0x08000000
/** The protocol field violates a protocol specification, usually PI_WARN severity */
#define PI_PROTOCOL             0x09000000
/** The protocol field indicates a security problem (e.g. insecure implementation) */
#define PI_SECURITY             0x0a000000
/** The protocol field indicates a packet comment */
#define PI_COMMENTS_GROUP       0x0b000000
/** The protocol field indicates a decryption problem */
#define PI_DECRYPTION           0x0c000000

#define EXPFILL 0, NULL, 0, \
        {0, {"Expert Info", NULL, FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL}}

#endif // DEFINE_H
