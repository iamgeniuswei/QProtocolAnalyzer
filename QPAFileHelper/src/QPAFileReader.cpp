/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileReader.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月18日, 下午4:34
 */

#include "QPAFileReader.h"

QPAFileReader::QPAFileReader()
{
}

QPAFileReader::QPAFileReader(const QPAFileReader& orig)
{
}

QPAFileReader::~QPAFileReader()
{
    closeFile();
}

bool
QPAFileReader::openFile(const std::string& path)
{
    _fileInfo = std::make_shared<QPAFileInfo>();
    if(!_fileInfo->setFile(path))
        return false;
    if(!(_fileInfo->isFile() && _fileInfo->isReadable()))
        return false;
    _fd.open(path, fstream::in | fstream::binary);
    if(!_fd.is_open())
        return false;
    return true;    
}

size_t
QPAFileReader::readToBuffer(void* buf, size_t bytes)
{
    if((_position + bytes) > _fileInfo->fileSize())
        return 0;
    if(_fd.is_open())
    {
        _fd.seekg(_position);
        _fd.read(reinterpret_cast<char*>(buf), bytes);
        size_t len = _fd.gcount();
        _position += len;
        return len;
    }
    return 0;
}


void
QPAFileReader::closeFile()
{
    if(_fd.is_open())
        _fd.close();
}
