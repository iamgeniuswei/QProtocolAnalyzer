/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFrameTvbuff.cpp
 * Author: lenovo
 * 
 * Created on September 22, 2017, 5:07 PM
 */

#include "QPAFrameTvbuff.h"

QPAFrameTvbuff::QPAFrameTvbuff()
{
}

QPAFrameTvbuff::~QPAFrameTvbuff()
{
}

void QPAFrameTvbuff::frame_tvbuff_new(shared_ptr<QPAFrameData> fd, const unsigned char* buf)
{
    _real_data = buf;
    
}
