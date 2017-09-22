/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtocolHelper.cpp
 * Author: lenovo
 * 
 * Created on September 22, 2017, 9:03 AM
 */

#include "QPAProtocolHelper.h"
#include "QPAHeaderFieldInfo.h"
#include "QPAGlobalHFMetaInfo.h"

QPAProtocolHelper* QPAProtocolHelper::_instance = nullptr;

QPAProtocolHelper::QPAProtocolHelper()
{
    _proto_names = make_shared<QPAMapHelper<unsigned int, string>>();
    _proto_short_names = make_shared<QPAMapManager<string, QPAProtocol>>();
    _proto_filter_names = make_shared<QPAMapManager<string, QPAProtocol>>();
    _protocols = make_shared<list<shared_ptr<QPAProtocol>>>();
}

QPAProtocolHelper::~QPAProtocolHelper()
{
}

QPAProtocolHelper* QPAProtocolHelper::instance()
{
    if(_instance == nullptr)
        _instance = new (std::nothrow) QPAProtocolHelper;
    return _instance;
}


int QPAProtocolHelper::proto_register_protocol(const string& name, const string& short_name, const string& filter_name)
{
    /*
     * Make sure there's not already a protocol with any of those
     * names.  Crash if there is, as that's an error in the code
     * or an inappropriate plugin.
     * This situation has to be fixed to not register more than one
     * protocol with the same name.
     *
     * This is done by reducing the number of strcmp (and alike) calls
     * as much as possible, as this significally slows down startup time.
     *
     * Drawback: As a hash value is used to reduce insert time,
     * this might lead to a hash collision.
     * However, although we have somewhat over 1000 protocols, we're using
     * a 32 bit int so this is very, very unlikely.
     */
    int key = wrs_str_hash(name.c_str());
    _proto_names->registerController(key, name);
    
    shared_ptr<QPAProtocol> protocol = make_shared<QPAProtocol>(name, short_name, filter_name);
    _proto_short_names->registerController(short_name, protocol);
    _proto_filter_names->registerController(filter_name, protocol);
    _protocols->push_front(protocol);
    
    shared_ptr<QPAHeaderFieldInfo> hfinfo = make_shared<QPAHeaderFieldInfo>(name, filter_name);
    hfinfo->_type = FT_PROTOCOL;
    hfinfo->_display = BASE_NONE;
    hfinfo->_strings =(void*)(protocol.get());
    hfinfo->_bitmask = 0;
    hfinfo->_ref_type = HF_REF_TYPE_NONE;
    hfinfo->_blurb = "";
    hfinfo->parent = -1;
    int proto_id = QPAGlobalHFMetaInfo::proto_register_field_init(hfinfo, hfinfo->parent);
    protocol->_proto_id = proto_id;
    return proto_id;
}

void QPAProtocolHelper::proto_register_field_array(const int parent, QPAHeaderFieldRegisterInfo hf[], const int num_records)
{
    QPAHeaderFieldRegisterInfo *ptr = hf;
    QPAProtocol* proto = find_protocol_by_id(parent);
    for(int i=0; i < num_records; i++, ptr++)
    {
        if(hf[i].p_id != -1 && hf[i].p_id !=0)
            return;
        
        hf[i].p_id = proto_register_field_common(proto, hf[i].hfinfo, parent);
        
    }
        
}

int QPAProtocolHelper::proto_register_field_common(QPAProtocol* proto, shared_ptr<QPAHeaderFieldInfo> hfi, const int parent)
{
    if(proto)
        proto->_fields.push_back(hfi);
    return QPAGlobalHFMetaInfo::proto_register_field_init(hfi, parent);
}





QPAProtocol* QPAProtocolHelper::find_protocol_by_id(const int proto_id)
{
    if(proto_id < 0)
        return nullptr;
    shared_ptr<QPAHeaderFieldInfo> hfinfo = QPAGlobalHFMetaInfo::hfinfo(proto_id);
    if(hfinfo->_type == FT_PROTOCOL)
        return (QPAProtocol*)(hfinfo->_strings);
    return nullptr;
}





unsigned int QPAProtocolHelper::wrs_str_hash(const char* str)
{
    unsigned int h = *str;
    if (h)
        for (str += 1; *str != '\0'; str++)
            h = (h << 5) - h + *str;
    return h;
}
