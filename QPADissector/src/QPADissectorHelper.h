/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissectorHelper.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 10:58 AM
 */

#ifndef QPADISSECTORHELPER_H
#define QPADISSECTORHELPER_H

#include <string>
#include <memory>
using namespace std;

#include "QPADissectorDefine.h"
#include "QPAMapManager.h"
#include "QPADissector.h"
#include "QPADissection.h"

class QPADissection;
class QPAAbstractPacketHeader;
class QPATvbuff;
class QPAFrameData;
class QPADissectorHelper
{
public:
    static QPADissectorHelper *instance();
    QPADissectorHelper();
    QPADissectorHelper(const QPADissectorHelper& orig) = delete;
    QPADissectorHelper(const QPADissectorHelper&& orig) = delete;
    QPADissectorHelper& operator=(const QPADissectorHelper& orig) = delete;
    QPADissectorHelper& operator=(const QPADissectorHelper&& orig) = delete;
    virtual ~QPADissectorHelper();
    
//    void ini
    bool registerDissector(const std::string name, new_dissector_t dissecotr, const int proto);
    void dissect_record(shared_ptr<QPADissection> edt,
                        int file_type_sub_type,
                        shared_ptr<QPAAbstractPacketHeader> phdr,
                        shared_ptr<QPATvbuff> tvb,
                        shared_ptr<QPAFrameData> fd);
    
    int call_dissector_with_data(shared_ptr<QPADissector> handle,
                                shared_ptr<QPATvbuff> tvb, 
                                shared_ptr<QPAPacketInfo> pinfo,
                                shared_ptr<QPAProtoNode> tree,
                                void *data);

protected:
    static QPADissectorHelper *_instance;
private:
    std::shared_ptr<QPAMapManager<std::string, QPADissector>> _dissectors;
    shared_ptr<QPADissector> _frame_dissector;

};

#endif /* QPADISSECTORHELPER_H */

