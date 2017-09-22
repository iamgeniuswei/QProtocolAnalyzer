/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissectorDefine.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 11:00 AM
 */

#ifndef QPADISSECTORDEFINE_H
#define QPADISSECTORDEFINE_H
class QPATvbuff;
class QPAPacketInfo;
class QPAProtoNode;
#include <memory>

#include "QPATvbuff.h"
#include "QPAPacketInfo.h"
#include "QPAProtoNode.h"
using namespace std;
typedef int (*new_dissector_t)(shared_ptr<QPATvbuff> tvb, shared_ptr<QPAPacketInfo> pi, shared_ptr<QPAProtoNode> pnode, void *);
typedef void (*dissector_t)(void *, void *, void *);

#endif /* QPADISSECTORDEFINE_H */

