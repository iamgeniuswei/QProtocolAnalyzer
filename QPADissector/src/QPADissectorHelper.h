/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissectorHelper.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 10:58 AM
 */

#ifndef QPADISSECTORHELPER_H
#define QPADISSECTORHELPER_H

#include <string>
#include <memory>

#include "QPADissectorDefine.h"
#include "QPAMapManager.h"
#include "QPADissector.h"
class QPADissectorHelper
{
public:
    QPADissectorHelper();
    QPADissectorHelper(const QPADissectorHelper& orig) = delete;
    QPADissectorHelper(const QPADissectorHelper&& orig) = delete;
    QPADissectorHelper& operator=(const QPADissectorHelper& orig) = delete;
    QPADissectorHelper& operator=(const QPADissectorHelper&& orig) = delete;
    virtual ~QPADissectorHelper();
    bool registerDissector(const std::string name, new_dissector_t dissecotr, const int proto);

protected:

private:
    std::shared_ptr<QPAMapManager<std::string, QPADissector>> _dissectors;

};

#endif /* QPADISSECTORHELPER_H */

