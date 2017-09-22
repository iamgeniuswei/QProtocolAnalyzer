/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissection.cpp
 * Author: lenovo
 * 
 * Created on September 21, 2017, 8:24 AM
 */

#include "QPADissection.h"
#include "QPAPacketInfo.h"
QPADissection::QPADissection()
{
}

QPADissection::~QPADissection()
{
}

void QPADissection::init(std::shared_ptr<QPADissectionSession> session, bool create_proto_tree, bool proto_tree_visible)
{
    _session = session;
    _pi = std::make_shared<QPAPacketInfo>();
    
    if(create_proto_tree)
    {
        _tree = std::make_shared<QPAProtoNode>();        
    }
}

void QPADissection::dissect_run(int file_type_subtype, shared_ptr<QPAAbstractHeader> phdr, shared_ptr<QPATvbuff> tvb, shared_ptr<QPAFrameData> fd)
{
    
}
