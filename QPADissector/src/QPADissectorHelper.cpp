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
#include "QPAAbstractPacketHeader.h"
#include "QPAFrameData.h"
#include "QPATvbuff.h"
#include "QPADissection.h"
QPADissectorHelper::QPADissectorHelper()
{
    _dissectors = std::make_shared<QPAMapManager<std::string, QPADissector>>();
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

void QPADissectorHelper::dissect_record(shared_ptr<QPADissection> edt, int file_type_sub_type, shared_ptr<QPAAbstractPacketHeader> phdr, shared_ptr<QPATvbuff> tvb, shared_ptr<QPAFrameData> fd)
{
    std::string record_type;
    switch(phdr->rec_type())
    {
        case REC_TYPE_PACKET:
            record_type = "Frame";
            break;
            
        case REC_TYPE_FT_SPECIFIC_EVENT:
            record_type = "Event";
            break;
            
        case REC_TYPE_FT_SPECIFIC_REPORT:
            record_type = "Report";
            break;
        default:
            break;
    }
    
    edt->_pi->_epan = edt->_session;
    edt->_pi->_current_proto = "<Missing Protocol Name>";
    edt->_pi->_fd = fd;
    edt->_pi->_phdr = phdr;
    edt->_tvb = tvb;
    
    shared_ptr<QPADissector> frame_handle = _dissectors->controller("frame");
    call_dissector_with_data(frame_handle, nullptr, nullptr, nullptr,nullptr);
    
    
}

int QPADissectorHelper::call_dissector_with_data(shared_ptr<QPADissector> handle,shared_ptr<QPATvbuff> tvb, shared_ptr<QPAPacketInfo> pinfo, shared_ptr<QPAProtoNode> tree, void* data)
{
    handle->dissector._new(nullptr, nullptr, nullptr, nullptr);
    return 0;
}

QPADissectorHelper* QPADissectorHelper::_instance = nullptr;
QPADissectorHelper* QPADissectorHelper::instance()
{
    if(_instance == nullptr)
        _instance = new QPADissectorHelper;
    return _instance;
}


