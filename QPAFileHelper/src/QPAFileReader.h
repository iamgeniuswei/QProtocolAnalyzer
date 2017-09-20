/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileReader.h
 * Author: lenovo
 *
 * Created on 2017年9月18日, 下午4:34
 */

#ifndef QPAFILEREADER_H
#define QPAFILEREADER_H

#include <string>
#include <memory>
#include <fstream>
#include <bits/c++config.h>
using namespace std;

#include "QPAFileInfo.h"

class QPAFileReader 
{
public:
    QPAFileReader();
    QPAFileReader(const QPAFileReader& orig);
    virtual ~QPAFileReader();
    bool openFile(const std::string& path);
    size_t readToBuffer(void *buf, size_t bytes);
    size_t position()
    {
        return _position;
    }
    


protected:
    void closeFile();
private:
    std::shared_ptr<QPAFileInfo> _fileInfo;
    size_t _position;
    fstream _fd;

};

#endif /* QPAFILEREADER_H */

