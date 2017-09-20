/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileMediator.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月19日, 上午8:26
 */

#include "QPAFileMediator.h"
#include "QPAPcapOpenRoutine.h"
#include "QPABuffer.h"
QPAFileMediator::QPAFileMediator()
{
}

QPAFileMediator::QPAFileMediator(const QPAFileMediator& orig)
{
}

QPAFileMediator::~QPAFileMediator()
{
}

bool
QPAFileMediator::openFile(const std::string& path)
{
//    if(nullptr == _reader)
//    {
//        _reader = std::make_shared<QPAFileReader>();
//        if(!_reader->openFile(path))
//            return false;
//    }
//    _openRoutine = std::make_shared<QPAPcapOpenRoutine>(this);
//    if(_openRoutine->openRoutine() != WTAP_OPEN_MINE)
//        return false;
//    _frameBuffer = std::make_shared<QPABuffer>();
//    _frameBuffer->ws_buffer_init(1500);
    return true;
}

bool
QPAFileMediator::readFile(size_t* offset)
{
    *offset = position();
    return _openRoutine->readPacket(nullptr);    
}


unsigned int
QPAFileMediator::readBytes(void* buf, unsigned int bytes)
{
    if(_reader == nullptr)
        return 0;
    return _reader->readToBuffer(buf, bytes);
}

unsigned int
QPAFileMediator::readPacketToBuffer(unsigned int bytes)
{
    _frameBuffer->ws_buffer_assure_space(bytes);
    return readBytes(_frameBuffer->data(), bytes);
}
