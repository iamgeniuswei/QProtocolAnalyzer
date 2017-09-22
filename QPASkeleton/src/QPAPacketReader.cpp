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
#include "QPAAbstractFile.h"
#include <iostream>
#include "QPADissection.h"
#include "QPABuffer.h"
#include "QPADissectorHelper.h"
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
    if (_abstractFile == nullptr)
    {
        _abstractFile = std::make_shared<QPAAbstractFile>();
    }
    if (!_abstractFile->openOffline(path, 0, 0))
        return CF_ERROR;
    _metaInfo = std::make_shared<QPAMetaInfo>();
    _metaInfo->_wth = _abstractFile;
    _metaInfo->_path = path;
    _metaInfo->_cd_t = _abstractFile->file_type_subtype();

    return CF_OK;
}

cf_read_status_t
QPAPacketReader::readPacket()
{
    if (_abstractFile == nullptr)
        return CF_READ_ERROR;

    std::shared_ptr<QPADissection> _edt = std::make_shared<QPADissection>();
    _edt->init();

    size_t offset = 0;
    size_t count = 0;

    while (_abstractFile->readFile(&offset))
    {
        std::cout << ++count << std::endl;
        readNewPacket(_edt, offset);
    }
}

int QPAPacketReader::readNewPacket(std::shared_ptr<QPADissection> _edt, ssize_t offset)
{
    std::shared_ptr<QPAAbstractPacketHeader> phdr = _metaInfo->_wth->phdr();
    unsigned char *buf = _metaInfo->_wth->frameBuffer()->ws_buffer_start_ptr();
    std::shared_ptr<QPAFrameData> fdlocal = std::make_shared<QPAFrameData>();
    unsigned int framenum = 0;
    std::shared_ptr<QPAFrameData> fdata = std::make_shared<QPAFrameData>();
    bool passed;
    int row = -1;
    framenum = _metaInfo->_count + 1;
    fdlocal->init();
    
    QPADissectorHelper *helper = QPADissectorHelper::instance();
    helper->dissect_record(_edt, _metaInfo->_cd_t, phdr, nullptr, fdlocal);
    
}

