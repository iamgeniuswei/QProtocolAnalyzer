/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAAbstractFile.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 4:40 PM
 */

#ifndef QPAABSTRACTFILE_H
#define QPAABSTRACTFILE_H

#include <memory>
#include <bits/c++config.h>

#include "QPAFileReader.h"
#include "QPAOpenRoutine.h"

#include "QPAFileHelperDefine.h"
#include "QPAAbstractPacketHeader.h"
class QPABuffer;
class QPAAbstractFile
{
public:
    QPAAbstractFile();
    QPAAbstractFile(const QPAAbstractFile& orig) = delete;
    QPAAbstractFile(const QPAAbstractFile&& orig) = delete;
    QPAAbstractFile& operator=(const QPAAbstractFile& orig) = delete;
    QPAAbstractFile& operator=(const QPAAbstractFile&& orig) = delete;
    virtual ~QPAAbstractFile();
    bool openOffline(const std::string& path, unsigned int type, bool d_random);
    bool readFile(size_t *offset);

    unsigned int readBytes(void *buf, unsigned int bytes);
    unsigned int readPacketToBuffer(unsigned int bytes);

    size_t position()
    {
        if (_reader)
            return _reader->position();
        return 0;
    }
    int file_type_subtype() const
    {
        return _file_type_subtype;
    }
    std::shared_ptr<QPAAbstractPacketHeader> phdr();
    std::shared_ptr<QPABuffer> frameBuffer();

protected:

private:
    int _file_type_subtype = 0;
    int _file_encap = WTAP_ENCAP_UNKNOWN;
    int _file_tsprec = WTAP_TSPREC_USEC;
    std::shared_ptr<QPAFileReader> _reader;
    std::shared_ptr<QPAOpenRoutine> _openRoutine;
    std::shared_ptr<QPABuffer> _frameBuffer;
    std::shared_ptr<QPAAbstractPacketHeader> _phdr;


};

#endif /* QPAABSTRACTFILE_H */

