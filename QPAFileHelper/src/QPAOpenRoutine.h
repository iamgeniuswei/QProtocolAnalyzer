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


class QPAOpenRoutine {
public:
    QPAOpenRoutine();
    QPAOpenRoutine(const QPAOpenRoutine& orig);
    virtual ~QPAOpenRoutine();
    virtual void openRoutine() = 0;

protected:

private:
//    std::shared_ptr<QPAFileReader>

};

#endif /* QPAOPENROUTINE_H */

