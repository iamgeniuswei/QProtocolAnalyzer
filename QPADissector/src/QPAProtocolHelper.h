/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtocolHelper.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 9:03 AM
 */

#ifndef QPAPROTOCOLHELPER_H
#define QPAPROTOCOLHELPER_H
#include "QPAMapManager.h"
#include "QPAMapHelper.h"
#include "QPAProtocol.h"
#include "QPAHeaderFieldRegisterInfo.h"
#include <list>
#include <memory>
using namespace std;
class QPAProtocol;
class QPAProtocolHelper
{
public:
    static QPAProtocolHelper *instance();
    QPAProtocolHelper();
    QPAProtocolHelper(const QPAProtocolHelper& orig) = delete;
    QPAProtocolHelper(const QPAProtocolHelper&& orig) = delete;
    QPAProtocolHelper& operator=(const QPAProtocolHelper& orig) = delete;
    QPAProtocolHelper& operator=(const QPAProtocolHelper&& orig) = delete;
    virtual ~QPAProtocolHelper();
public:
    int proto_register_protocol(const string& name,
                                const string& short_name,
                                const string& filter_name);
    void proto_register_field_array(const int parent,
                                    QPAHeaderFieldRegisterInfo hf[],
                                    const int num_records);
    
    int proto_register_field_common(QPAProtocol *proto,
                                    shared_ptr<QPAHeaderFieldInfo> hfi,
                                    const int parent);

protected:
    QPAProtocol* find_protocol_by_id(const int proto_id);
    
public:
    unsigned int wrs_str_hash(const char *str);

private:
    static QPAProtocolHelper *_instance;
//    shared_ptr<QPAMapManager<unsigned int, QPAProtocol>> _protocols;
    shared_ptr<QPAMapHelper<unsigned int, string>> _proto_names;
    shared_ptr<QPAMapManager<string, QPAProtocol>> _proto_short_names;
    shared_ptr<QPAMapManager<string, QPAProtocol>> _proto_filter_names;
    shared_ptr<list<shared_ptr<QPAProtocol>>>  _protocols;

};

#endif /* QPAPROTOCOLHELPER_H */

