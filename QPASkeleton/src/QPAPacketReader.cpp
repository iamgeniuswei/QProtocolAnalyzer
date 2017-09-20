/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAPacketReader.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月19日, 上午9:00
 */

#include "QPAPacketReader.h"
#include "QPAFileMediator.h"
#include <iostream>
QPAPacketReader::QPAPacketReader()
{
}

QPAPacketReader::QPAPacketReader(const QPAPacketReader& orig)
{
}

QPAPacketReader::~QPAPacketReader()
{
}

cf_status_t
QPAPacketReader::openPacketFile(const std::string& path)
{
    if (_fileMediator == nullptr) {
        _fileMediator = std::make_shared<QPAFileMediator>();
    }
    if(!_fileMediator->openFile(path))
        return CF_ERROR;
    return CF_OK;
}

cf_read_status_t
QPAPacketReader::readPacket()
{
    if(_fileMediator == nullptr)
        return CF_READ_ERROR;
    
    size_t offset = 0;
    size_t count = 0;
    
    while (_fileMediator->readFile(&offset)) 
    {
        std::cout << ++count << std::endl;
    }

    
}

