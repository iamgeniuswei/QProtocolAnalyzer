/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtocol.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 11:04 AM
 */

#ifndef QPAPROTOCOL_H
#define QPAPROTOCOL_H

#include <string>
#include <vector>
#include <list>
#include <memory>

#include "QPAHeaderFieldInfo.h"
using namespace std;
class QPAHeaderFieldInfo;
class QPAProtocol
{
    friend class QPADissector;
    friend class QPAProtocolHelper;
    friend class QPAProtoNode;
    
public:
    QPAProtocol(const string& name,
                const string& short_name,
                const string& filter_name);
    QPAProtocol(const QPAProtocol& orig) = delete;
    QPAProtocol(const QPAProtocol&& orig) = delete;
    QPAProtocol& operator=(const QPAProtocol& orig) = delete;
    QPAProtocol& operator=(const QPAProtocol&& orig) = delete;
    virtual ~QPAProtocol();

protected:

private:
    std::string _name;
    std::string _short_name;
    std::string _filter_name;
    std::vector<std::shared_ptr<QPAHeaderFieldInfo>> _fields;
    int _proto_id;
    bool _is_enabled = true;
    bool _can_toggle = true;
//    std::list<void> _heurList;
};

#endif /* QPAPROTOCOL_H */

