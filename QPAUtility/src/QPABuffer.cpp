/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPABuffer.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月19日, 上午9:39
 */

#include <new>

#include "QPABuffer.h"
UINT32 QPABuffer::MAX_SPACE = 1024000;
QPABuffer::QPABuffer()
{
}

QPABuffer::QPABuffer(const QPABuffer& orig)
{
}

QPABuffer::~QPABuffer()
{
}

void
QPABuffer::ws_buffer_init(UINT32 space)
{
    if(space > 0 && space <= MAX_SPACE)
    {
        _data = new (std::nothrow) UINT8 [space];
        if(nullptr == _data)
            return;
        _allocated = space;
        _start = 0;
        _first_free = 0;
    }
}

//TODO: 完成函数体
void
QPABuffer::ws_buffer_assure_space(UINT32 space)
{

}
