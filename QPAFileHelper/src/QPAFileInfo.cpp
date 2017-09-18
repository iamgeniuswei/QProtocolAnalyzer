/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileInfo.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月18日, 下午4:37
 */

#include <cstring>
#include <fcntl.h>

#include "QPAFileInfo.h"

QPAFileInfo::QPAFileInfo()
{
    memset(&_stat, 0, sizeof(struct stat));
}

QPAFileInfo::QPAFileInfo(const QPAFileInfo& orig)
{
}

QPAFileInfo::~QPAFileInfo()
{
}

bool
QPAFileInfo::setFile(const std::string& path)
{
    _path = path;
    int result = stat(_path.c_str(), &_stat);
    if(result != 0)
        return false;
    return true;
}

bool
QPAFileInfo::isFile()
{
    return _stat.st_mode & S_IFREG;
}

bool
QPAFileInfo::isReadable()
{
    return _stat.st_mode & S_IRGRP;
}


size_t
QPAFileInfo::fileSize()
{
    return _stat.st_size;
}


