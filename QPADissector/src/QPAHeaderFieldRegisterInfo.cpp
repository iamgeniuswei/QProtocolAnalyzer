/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAHeaderFieldRegisterInfo.cpp
 * Author: lenovo
 * 
 * Created on September 22, 2017, 11:01 AM
 */

#include "QPAHeaderFieldRegisterInfo.h"

QPAHeaderFieldRegisterInfo::QPAHeaderFieldRegisterInfo(int pid, shared_ptr<QPAHeaderFieldInfo> hfi)
:p_id(pid), hfinfo(hfi)
{

}


QPAHeaderFieldRegisterInfo::~QPAHeaderFieldRegisterInfo()
{
}

