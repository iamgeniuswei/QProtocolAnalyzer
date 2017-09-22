/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPATvbuff.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 8:26 AM
 */

#ifndef QPATVBUFF_H
#define QPATVBUFF_H

#include <memory>

#include "QPAFrameData.h"
using namespace std;
/*
 * Tvbuff flags.
 */
#define TVBUFF_FRAGMENT  0x00000001 /* this is a fragment */
/* To pass one of two strings, singular or plural */
#define plurality(d,s,p) ((d) == 1 ? (s) : (p))
class QPAFrameData;

class QPATvbuff
{
    friend class QPAFrameTvbuff;
public:
    QPATvbuff();
    QPATvbuff(const QPATvbuff& orig) = delete;
    QPATvbuff(const QPATvbuff&& orig) = delete;
    QPATvbuff& operator=(const QPATvbuff& orig) = delete;
    QPATvbuff& operator=(const QPATvbuff&& orig) = delete;
    virtual ~QPATvbuff();
    
//    virtual void tvb_free() =0;
//    virtual unsigned int tvb_offset(unsigned int counter) = 0;
//    virtual unsigned char* tvb_get_ptr(unsigned int abs_offset, unsigned int abs_length) = 0;
//    virtual void* tvb_memcpy(void *target, unsigned int offset, unsigned int length) = 0;
//    virtual int tvb_find_uint8(unsigned int abs_offset, unsigned int limit, char needle) = 0;
//    virtual int tvb_ws_mempbrk_pattern_uint8();
    
    
    
    
    void frame_tvbuff_new(shared_ptr<QPAFrameData> fd, unsigned char *buf);
    int raw_offset() const;
    unsigned int reported_length() const;
    unsigned int length() const;
//    const unsigned char* real_data() const;
    std::shared_ptr<QPATvbuff> ds_tvb() const;
    unsigned int flags() const;
    bool initialized() const;
    std::shared_ptr<QPATvbuff> next() const;
    unsigned int tvb_ensure_captured_length_remaining(const int offset);

    int tvb_captured_length_remaining(const int offset);


protected:
    inline int compute_offset_and_remaining(const int offset, unsigned int *offset_ptr, unsigned int *rem_len);
    inline int compute_offset(const int offset, unsigned int *offset_ptr);

protected:
    std::shared_ptr<QPATvbuff> _next;
    bool _initialized;
    unsigned int _flags;
    std::shared_ptr<QPATvbuff> _ds_tvb;
    const unsigned char *_real_data;
    unsigned int _length;
    unsigned int _reported_length;
    int _raw_offset;
};

#endif /* QPATVBUFF_H */

