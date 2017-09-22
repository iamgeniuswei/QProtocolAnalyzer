/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPATreeData.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 4:30 PM
 */

#ifndef QPATREEDATA_H
#define QPATREEDATA_H
#include "QPAMapHelper.h"
#include "QPAPacketInfo.h"
class QPAPacketInfo;
class QPATreeData
{
public:
    QPATreeData();
    QPATreeData(const QPATreeData& orig) = delete;
    QPATreeData(const QPATreeData&& orig) = delete;
    QPATreeData& operator=(const QPATreeData& orig) = delete;
    QPATreeData& operator=(const QPATreeData&& orig) = delete;
    virtual ~QPATreeData();

protected:

public:
    bool visible = true;
    bool fake_protocols = true;
    int count = 0;   
    QPAPacketInfo *pinfo = nullptr;
};

#endif /* QPATREEDATA_H */

