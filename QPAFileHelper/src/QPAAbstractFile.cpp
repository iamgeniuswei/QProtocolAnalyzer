/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAAbstractFile.cpp
 * Author: lenovo
 * 
 * Created on September 20, 2017, 4:40 PM
 */

#include "QPAAbstractFile.h"
#include "QPABuffer.h"
#include "QPAPcapOpenRoutine.h"

QPAAbstractFile::QPAAbstractFile()
{
}

QPAAbstractFile::~QPAAbstractFile()
{
}

bool QPAAbstractFile::openOffline(const std::string& path, unsigned int type, bool d_random)
{
    if (nullptr == _reader)
    {
        _reader = std::make_shared<QPAFileReader>();
        if (!_reader->openFile(path))
            return false;
    }
    _openRoutine = std::make_shared<QPAPcapOpenRoutine>(this);
    if (_openRoutine->openRoutine() != WTAP_OPEN_MINE)
        return false;
    _frameBuffer = std::make_shared<QPABuffer>();
    _frameBuffer->ws_buffer_init(1500);
    return true;
}

bool
QPAAbstractFile::readFile(size_t* offset)
{
    *offset = position();
    return _openRoutine->readPacket(nullptr);
}

unsigned int
QPAAbstractFile::readBytes(void* buf, unsigned int bytes)
{
    if (_reader == nullptr)
        return 0;
    return _reader->readToBuffer(buf, bytes);
}

unsigned int
QPAAbstractFile::readPacketToBuffer(unsigned int bytes)
{
    _frameBuffer->ws_buffer_assure_space(bytes);
    return readBytes(_frameBuffer->data(), bytes);
}
