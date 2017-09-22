/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAHeaderFieldInfo.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 3:59 PM
 */

#ifndef QPAHEADERFIELDINFO_H
#define QPAHEADERFIELDINFO_H

#include <string>
#include <memory>
#include "QPAFieldTypeDefine.h"
#include "QPATvbuff.h"
using namespace std;

typedef enum {
    HF_REF_TYPE_NONE,       /**< Field is not referenced */
    HF_REF_TYPE_INDIRECT,   /**< Field is indirectly referenced (only applicable for FT_PROTOCOL) via. its child */
    HF_REF_TYPE_DIRECT      /**< Field is directly referenced */
} hf_ref_type;
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


class QPAHeaderFieldInfo
{
    friend class QPAProtocolHelper;
    friend class QPAGlobalHFMetaInfo;
    friend class QPAProtocol;
    friend class QPAProtoNode;
public:
    QPAHeaderFieldInfo(const string& name = "",
                       const string& abbrev = "");
    QPAHeaderFieldInfo(const string& name,
                       const string& abbrev,
                       ftenum type,
                       int display,
                       void * strings,
                       size_t bitmask,
                       const string& blurb);
    QPAHeaderFieldInfo(const QPAHeaderFieldInfo& orig) = delete;
    QPAHeaderFieldInfo(const QPAHeaderFieldInfo&& orig) = delete;
    QPAHeaderFieldInfo& operator=(const QPAHeaderFieldInfo& orig) = delete;
    QPAHeaderFieldInfo& operator=(const QPAHeaderFieldInfo&& orig) = delete;
    virtual ~QPAHeaderFieldInfo();
    int proto_register_field_init(const int parent);

    void get_hfi_length(shared_ptr<QPATvbuff> tvb,
                        const int start,
                        int *length,
                        int *item_length);
protected:
private:
    // set by dissector
    string _name;
    string _abbrev;
    ftenum _type = FT_NONE;
    int _display = 0;
    void *_strings = nullptr;
    size_t _bitmask =  0;
    string _blurb;
    
    // set by proto routines
    int id = 0;
    int parent = 0;
    hf_ref_type _ref_type = HF_REF_TYPE_NONE;
    int same_name_prev_id = 0;
    shared_ptr<QPAHeaderFieldInfo> _same_name_next = nullptr;
    

};

#endif /* QPAHEADERFIELDINFO_H */

