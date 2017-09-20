/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileMediator.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午8:26
 */

#ifndef QPAFILEMEDIATOR_H
#define QPAFILEMEDIATOR_H

#include <memory>
#include <bits/c++config.h>

#include "QPAFileReader.h"
#include "QPAOpenRoutine.h"

class QPABuffer;
class QPAFileMediator {
public:
    QPAFileMediator();
    QPAFileMediator(const QPAFileMediator& orig);
    virtual ~QPAFileMediator();
    bool openFile(const std::string& path);
    bool readFile(size_t *offset);
    
    unsigned int readBytes(void *buf, unsigned int bytes);
    unsigned int readPacketToBuffer(unsigned int bytes);
    size_t position()
    {
        if(_reader)
            return _reader->position();
        return 0;
    }

protected:

private:
    std::shared_ptr<QPAFileReader> _reader;
    std::shared_ptr<QPAOpenRoutine> _openRoutine;
    std::shared_ptr<QPABuffer> _frameBuffer;
};

#endif /* QPAFILEMEDIATOR_H */

