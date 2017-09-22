/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPATvbuff.cpp
 * Author: lenovo
 * 
 * Created on September 21, 2017, 8:26 AM
 */

#include "QPATvbuff.h"
#include "exceptions.h"
QPATvbuff::QPATvbuff()
{
    
}

QPATvbuff::~QPATvbuff()
{
}

void QPATvbuff::frame_tvbuff_new(shared_ptr<QPAFrameData> fd, unsigned char* buf)
{

}

int QPATvbuff::raw_offset() const
{
    return _raw_offset;
}

unsigned int QPATvbuff::reported_length() const
{
    return _reported_length;
}

unsigned int QPATvbuff::length() const
{
    return _length;
}

//unsigned char* QPATvbuff::real_data() const
//{
//    return _real_data;
//}

std::shared_ptr<QPATvbuff> QPATvbuff::ds_tvb() const
{
    return _ds_tvb;
}

unsigned int QPATvbuff::flags() const
{
    return _flags;
}

bool QPATvbuff::initialized() const
{
    return _initialized;
}

std::shared_ptr<QPATvbuff> QPATvbuff::next() const
{
    return _next;
}

unsigned int QPATvbuff::tvb_ensure_captured_length_remaining(const int offset)
{
    unsigned int abs_offset = 0, rem_length = 0;
    if (!_initialized)
        return 0;
    int exception = compute_offset_and_remaining(offset, &abs_offset, &rem_length);
    if(exception !=0)
        return 0;
    return rem_length;
}

int QPATvbuff::tvb_captured_length_remaining(const int offset)
{
    unsigned int abs_offset = 0, rem_length = 0;
    int exception = 0;

    if(!_initialized)
        return 0;

    exception = compute_offset_and_remaining(offset, &abs_offset, &rem_length);
    if (exception)
        return 0;
    return rem_length;
}





int QPATvbuff::compute_offset_and_remaining(const int offset, unsigned int* offset_ptr, unsigned int* rem_len)
{
    int exception = 0;

    exception = compute_offset(offset, offset_ptr);
    if (!exception)
        *rem_len = _length - *offset_ptr;

    return exception;
}

int QPATvbuff::compute_offset(const int offset, unsigned int* offset_ptr)
{
    if (offset >= 0)
    {
        /* Positive offset - relative to the beginning of the packet. */
        if ((unsigned int) offset <= _length)
        {
            *offset_ptr = offset;
        }
        else if ((unsigned int) offset <= _reported_length)
        {
            return BoundsError;
        }
        else if (_flags & TVBUFF_FRAGMENT)
        {
            return FragmentBoundsError;
        }
        else
        {
            return ReportedBoundsError;
        }
    }
    else
    {
        /* Negative offset - relative to the end of the packet. */
        if ((unsigned int ) - offset <= _length)
        {
            *offset_ptr = _length + offset;
        }
        else if ((unsigned int ) - offset <= _reported_length)
        {
            return BoundsError;
        }
        else if (_flags & TVBUFF_FRAGMENT)
        {
            return FragmentBoundsError;
        }
        else
        {
            return ReportedBoundsError;
        }
    }

    return 0;
}
