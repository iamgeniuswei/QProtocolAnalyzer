/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileInfo.h
 * Author: lenovo
 *
 * Created on 2017年9月18日, 下午4:37
 */

#ifndef QPAFILEINFO_H
#define QPAFILEINFO_H
#include <sys/stat.h>
#include <sys/types.h>
#include <string>

class QPAFileInfo 
{
public:
    QPAFileInfo();
    QPAFileInfo(const QPAFileInfo& orig);
    virtual ~QPAFileInfo();
    bool setFile(const std::string& path);
    bool isFile();
    bool isReadable();
    size_t fileSize();

protected:

private:
    struct stat _stat;
    std::string _path;

};

#endif /* QPAFILEINFO_H */

