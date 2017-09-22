/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAHeaderFieldInfo.cpp
 * Author: lenovo
 * 
 * Created on September 21, 2017, 3:59 PM
 */

#include "QPAHeaderFieldInfo.h"
#include "QPAGlobalHFMetaInfo.h"
#include <iostream>
QPAHeaderFieldInfo::QPAHeaderFieldInfo(const string& name, const string& abbrev)
:_name(name), _abbrev(abbrev)
{

}

QPAHeaderFieldInfo::QPAHeaderFieldInfo(const string& name, const string& abbrev, ftenum type, int display, void* strings, size_t bitmask, const string& blurb)
:_name(name), _abbrev(abbrev), _type(type), _display(display), _strings(strings), _bitmask(bitmask), _blurb(blurb)
{
    std::cout << _name << std::endl;
}



QPAHeaderFieldInfo::~QPAHeaderFieldInfo()
{
}

int QPAHeaderFieldInfo::proto_register_field_init(const int parent)
{
    this->parent = parent;
    same_name_prev_id = -1;
    _same_name_next = nullptr;
    
    if(QPAGlobalHFMetaInfo::len() >= QPAGlobalHFMetaInfo::allocated_len())
    {
        QPAGlobalHFMetaInfo::add_len(1000);        
    }
    
}






void QPAHeaderFieldInfo::get_hfi_length(shared_ptr<QPATvbuff> tvb, const int start, int* length, int* item_length)
{
    int length_remaining = 0;
    if (tvb == nullptr || *length == 0)
        return;

    /*
     * XXX - in some protocols, there are 32-bit unsigned length
     * fields, so lengths in protocol tree and tvbuff routines
     * should really be unsigned.  We should have, for those
     * field types for which "to the end of the tvbuff" makes sense,
     * additional routines that take no length argument and
     * add fields that run to the end of the tvbuff.
     */
    if (*length == -1)
    {
        /*
         * For FT_NONE, FT_PROTOCOL, FT_BYTES, FT_STRING, and
         * FT_STRINGZPAD fields, a length of -1 means "set the
         * length to what remains in the tvbuff".
         *
         * The assumption is either that
         *
         *	1) the length of the item can only be determined
         *	   by dissection (typically true of items with
         *	   subitems, which are probably FT_NONE or
         *	   FT_PROTOCOL)
         *
         * or
         *
         *	2) if the tvbuff is "short" (either due to a short
         *	   snapshot length or due to lack of reassembly of
         *	   fragments/segments/whatever), we want to display
         *	   what's available in the field (probably FT_BYTES
         *	   or FT_STRING) and then throw an exception later
         *
         * or
         *
         *	3) the field is defined to be "what's left in the
         *	   packet"
         *
         * so we set the length to what remains in the tvbuff so
         * that, if we throw an exception while dissecting, it
         * has what is probably the right value.
         *
         * For FT_STRINGZ, it means "the string is null-terminated,
         * not null-padded; set the length to the actual length
         * of the string", and if the tvbuff if short, we just
         * throw an exception.
         *
         * It's not valid for any other type of field.  For those
         * fields, we treat -1 the same way we treat other
         * negative values - we assume the length is a Really
         * Big Positive Number, and throw a ReportedBoundsError
         * exception, under the assumption that the Really Big
         * Length would run past the end of the packet.
         */
        switch (_type)
        {
            case FT_PROTOCOL:
            case FT_NONE:
            case FT_BYTES:
            case FT_STRING:
            case FT_STRINGZPAD:
                /*
                 * We allow FT_PROTOCOLs to be zero-length -
                 * for example, an ONC RPC NULL procedure has
                 * neither arguments nor reply, so the
                 * payload for that protocol is empty.
                 *
                 * We also allow the others to be zero-length -
                 * because that's the way the code has been for a
                 * long, long time.
                 *
                 * However, we want to ensure that the start
                 * offset is not *past* the byte past the end
                 * of the tvbuff: we throw an exception in that
                 * case.
                 */
                *length = tvb->tvb_ensure_captured_length_remaining(start);
                break;
            case FT_STRINGZ:
                /*
                 * Leave the length as -1, so our caller knows
                 * it was -1.
                 */
                break;
            default:
                break;
        }
        *item_length = *length;
    }
    else
    {
        *item_length = *length;
        if (_type == FT_PROTOCOL || _type == FT_NONE)
        {
            /*
             * These types are for interior nodes of the
             * tree, and don't have data associated with
             * them; if the length is negative (XXX - see
             * above) or goes past the end of the tvbuff,
             * cut it short at the end of the tvbuff.
             * That way, if this field is selected in
             * Wireshark, we don't highlight stuff past
             * the end of the data.
             */
            /* XXX - what to do, if we don't have a tvb? */
            if(tvb)
            {
                length_remaining = tvb->tvb_captured_length_remaining(start);
                if(*item_length < 0 ||
                   (*item_length > 0 &&
                    (length_remaining < *item_length)))
                {
                    *item_length = length_remaining;
                }
            }
        }
        
        if(*item_length < 0)
            return;
    }
}
