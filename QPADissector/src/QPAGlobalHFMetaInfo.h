/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAGlobalHFMetaInfo.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 9:00 AM
 */

#ifndef QPAGLOBALHFMETAINFO_H
#define QPAGLOBALHFMETAINFO_H

#include <vector>
#include <memory>
using namespace std;

#include "QPAHeaderFieldInfo.h"
#define PRE_ALLOC_EXPERT_FIELDS_MEM 5000
#define PROTO_PRE_ALLOC_HF_FIELDS_MEM (170000+PRE_ALLOC_EXPERT_FIELDS_MEM)
class QPAGlobalHFMetaInfo
{
public:
    QPAGlobalHFMetaInfo();
    QPAGlobalHFMetaInfo(const QPAGlobalHFMetaInfo& orig) = delete;
    QPAGlobalHFMetaInfo(const QPAGlobalHFMetaInfo&& orig) = delete;
    QPAGlobalHFMetaInfo& operator=(const QPAGlobalHFMetaInfo& orig) = delete;
    QPAGlobalHFMetaInfo& operator=(const QPAGlobalHFMetaInfo&& orig) = delete;
    virtual ~QPAGlobalHFMetaInfo();
    
    
    static int proto_register_field_init(shared_ptr<QPAHeaderFieldInfo> hfinfo, int parent);
    
    static unsigned int allocated_len();
    static unsigned int len();
    static void add_len(int value);
    static void add_hfi(shared_ptr<QPAHeaderFieldInfo> hfinfo);
    static shared_ptr<QPAHeaderFieldInfo> hfinfo(const int index);

protected:

private:
    static unsigned int _len;
    static unsigned int _allocated_len;
    static vector<shared_ptr<QPAHeaderFieldInfo>> hfi;
    

};

#endif /* QPAGLOBALHFMETAINFO_H */

