/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAOpenRoutine.h
 * Author: lenovo
 *
 * Created on 2017年9月18日, 下午5:27
 */

#ifndef QPAOPENROUTINE_H
#define QPAOPENROUTINE_H

#include <memory>

#include "QPAFileReader.h"
//#include "QPAFileMediator.h"
#include "QPAFileHelperDefine.h"
class QPAFileMediator;
class QPAOpenRoutine {
public:
    QPAOpenRoutine(QPAFileMediator* mediator = nullptr);
    QPAOpenRoutine(const QPAOpenRoutine& orig);
    virtual ~QPAOpenRoutine();
    virtual wtap_open_return_val openRoutine() = 0;
    virtual bool readPacket(ssize_t * offset) = 0;

protected:

protected:
    QPAFileMediator* _mediator = nullptr;
    

};

#endif /* QPAOPENROUTINE_H */

