/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissection.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 8:24 AM
 */

#ifndef QPADISSECTION_H
#define QPADISSECTION_H

#include <memory>

#include "QPADissectionSession.h"
#include "QPATvbuff.h"
#include "QPAProtoNode.h"
#include "QPAPacketInfo.h"
using namespace std;

class QPADissectionSession;
class QPATvbuff;
class QPAProtoNode;
class QPAPacketInfo;
class QPAAbstractHeader;
class QPADissection
{
    friend class QPADissectorHelper;
public:
    QPADissection();
    QPADissection(const QPADissection& orig) = delete;
    QPADissection(const QPADissection&& orig) = delete;
    QPADissection& operator=(const QPADissection& orig) = delete;
    QPADissection& operator=(const QPADissection&& orig) = delete;
    virtual ~QPADissection();
    void init(std::shared_ptr<QPADissectionSession> session = nullptr, bool create_proto_tree = true, bool proto_tree_visible = true);
    void dissect_run(int file_type_subtype, shared_ptr<QPAAbstractHeader> phdr,
                    shared_ptr<QPATvbuff> tvb,
                    shared_ptr<QPAFrameData> fd);
protected:

private:
    std::shared_ptr<QPADissectionSession> _session = nullptr;
    std::shared_ptr<QPATvbuff> _tvb = nullptr;
    std::shared_ptr<QPAProtoNode> _tree = nullptr;
    std::shared_ptr<QPAPacketInfo> _pi = nullptr;
        
    
};

#endif /* QPADISSECTION_H */

