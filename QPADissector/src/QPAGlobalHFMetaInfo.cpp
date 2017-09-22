/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAGlobalHFMetaInfo.cpp
 * Author: lenovo
 * 
 * Created on September 22, 2017, 9:00 AM
 */

#include "QPAGlobalHFMetaInfo.h"

unsigned int QPAGlobalHFMetaInfo::_len = 0;
unsigned int QPAGlobalHFMetaInfo::_allocated_len = PROTO_PRE_ALLOC_HF_FIELDS_MEM;
vector<shared_ptr<QPAHeaderFieldInfo>> QPAGlobalHFMetaInfo::hfi;
QPAGlobalHFMetaInfo::QPAGlobalHFMetaInfo()
{
}

QPAGlobalHFMetaInfo::~QPAGlobalHFMetaInfo()
{
}

unsigned int QPAGlobalHFMetaInfo::allocated_len()
{
    return _allocated_len;
}

unsigned int QPAGlobalHFMetaInfo::len()
{
    return _len;
}

void QPAGlobalHFMetaInfo::add_len(int value)
{
    _len += value;
}

void QPAGlobalHFMetaInfo::add_hfi(shared_ptr<QPAHeaderFieldInfo> hfinfo)
{
    hfi[_len] = hfinfo;
}

int QPAGlobalHFMetaInfo::proto_register_field_init(shared_ptr<QPAHeaderFieldInfo> hfinfo, int parent)
{
    hfinfo->parent = parent;
    hfinfo->same_name_prev_id = -1;
    hfinfo->_same_name_next = nullptr;
    
    hfi.push_back(hfinfo);
    hfinfo->id = _len;
    _len++;
    
    return hfinfo->id;
        
}

shared_ptr<QPAHeaderFieldInfo> QPAGlobalHFMetaInfo::hfinfo(const int index)
{
    if(index >= _len)
        return nullptr;
    return hfi[index];
}
