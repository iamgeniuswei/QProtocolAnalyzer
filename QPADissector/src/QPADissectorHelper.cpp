/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissectorHelper.cpp
 * Author: lenovo
 * 
 * Created on September 20, 2017, 10:58 AM
 */

#include <memory>

#include "QPADissectorHelper.h"
#include "QPADissector.h"

QPADissectorHelper::QPADissectorHelper()
{
}

QPADissectorHelper::~QPADissectorHelper()
{
}


bool QPADissectorHelper::registerDissector(const std::string name, new_dissector_t dissecotr, const int proto)
{
    std::shared_ptr<QPADissector> tmp = std::make_shared<QPADissector>();
    tmp->_name = name;
    tmp->_isNew = true;
    tmp->dissector._new = dissecotr;
    //TODO:增加协议接口
    _dissectors->registerController(name, tmp);
    return true;    
}


