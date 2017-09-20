/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPABuffer.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午9:39
 */

#ifndef QPABUFFER_H
#define QPABUFFER_H
#include "QPAUtilityDefine.h"
class QPABuffer 
{
public:
    QPABuffer();
    QPABuffer(const QPABuffer& orig);
    virtual ~QPABuffer();
    void ws_buffer_init(UINT32 space = 1500);
    void ws_buffer_free();
    void ws_buffer_assure_space(UINT32 space);
    void ws_buffer_append(UINT32 *from, UINT32 bytes);
    void ws_buffer_remove_start(UINT32 bytes);
    void ws_buffer_clean();
    void ws_buffer_increase_length(unsigned int bytes);
    inline UINT8 *data()
    {
        return _data;
    }

protected:

private:
    UINT8 *_data = nullptr;
    UINT32 _allocated = 0;
    UINT32 _start = 0;
    UINT32 _first_free = 0;
    static UINT32 MAX_SPACE;
};

#endif /* QPABUFFER_H */

