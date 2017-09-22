/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAHeaderFieldRegisterInfo.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 11:01 AM
 */

#ifndef QPAHEADERFIELDREGISTERINFO_H
#define QPAHEADERFIELDREGISTERINFO_H

#include <memory>

#include "QPAHeaderFieldInfo.h"


class QPAHeaderFieldRegisterInfo
{
public:
    QPAHeaderFieldRegisterInfo(int pid,
                               shared_ptr<QPAHeaderFieldInfo> hfi);
    QPAHeaderFieldRegisterInfo(const QPAHeaderFieldRegisterInfo& orig) = delete;
    QPAHeaderFieldRegisterInfo(const QPAHeaderFieldRegisterInfo&& orig) = delete;
    QPAHeaderFieldRegisterInfo& operator=(const QPAHeaderFieldRegisterInfo& orig) = delete;
    QPAHeaderFieldRegisterInfo& operator=(const QPAHeaderFieldRegisterInfo&& orig) = delete;
    virtual ~QPAHeaderFieldRegisterInfo();

protected:

public:
    int p_id;
    std::shared_ptr<QPAHeaderFieldInfo> hfinfo;

};

#endif /* QPAHEADERFIELDREGISTERINFO_H */

