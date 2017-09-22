/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtoNode.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 8:33 AM
 */

#ifndef QPAPROTONODE_H
#define QPAPROTONODE_H

#include <memory>

#include "QPATvbuff.h"
#include "QPAHeaderFieldInfo.h"
#include "QPAFieldInfo.h"
#include "QPAProtocol.h"
#include "QPATreeData.h"
using namespace std;
class QPATvbuff;
class QPAFieldInfo;
class QPAProtoNode
{
public:
    QPAProtoNode();
    QPAProtoNode(const QPAProtoNode& orig) = delete;
    QPAProtoNode(const QPAProtoNode&& orig) = delete;
    QPAProtoNode& operator=(const QPAProtoNode& orig) = delete;
    QPAProtoNode& operator=(const QPAProtoNode&& orig) = delete;
    virtual ~QPAProtoNode();
    
public:
    bool proto_tree_add_item(int hfindex, 
                             shared_ptr<QPATvbuff> tvb,
                             const int start,
                             int length,
                             const unsigned int encoding);
    
    
    
    QPAProtoNode* proto_tree_add_protocol_format(int hfindex, shared_ptr<QPATvbuff> tvb, int start,
                                        int length, 
                                        const char *format, ...);
    
protected:
    QPAProtoNode* proto_tree_add_pi(shared_ptr<QPAHeaderFieldInfo> hfinfo,
                           shared_ptr<QPATvbuff> tvb,
                           int start,
                           int *length);
    QPAProtoNode* proto_tree_add_node(shared_ptr<QPAFieldInfo> fi);
    
    void proto_tree_set_representation(const char *format, va_list ap);

protected:

public:
    QPAProtoNode* first_child = nullptr;
    QPAProtoNode* last_child = nullptr;
    QPAProtoNode* next = nullptr;
    QPAProtoNode* parent = nullptr;
    shared_ptr<QPAFieldInfo> finfo = nullptr;
    QPATreeData *tree_data = nullptr;

};

#endif /* QPAPROTONODE_H */

