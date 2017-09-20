/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAPacketReader.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午9:00
 */

#ifndef QPAPACKETREADER_H
#define QPAPACKETREADER_H

#include <string>
#include <memory>

#include "QPASkeletonDefine.h"
#include "QPAMetaInfo.h"

class QPAAbstractFile;
class QPAPacketReader {
public:
    QPAPacketReader();
    QPAPacketReader(const QPAPacketReader& orig);
    virtual ~QPAPacketReader();
    cf_status_t openPacketFile(const std::string& path);
    cf_read_status_t readPacket();

protected:

private:
    std::shared_ptr<QPAAbstractFile> _abstractFile = nullptr;
    std::shared_ptr<QPAMetaInfo> _metaInfo = nullptr;

};

#endif /* QPAPACKETREADER_H */

