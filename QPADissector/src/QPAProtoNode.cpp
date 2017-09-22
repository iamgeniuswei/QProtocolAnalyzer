/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtoNode.cpp
 * Author: lenovo
 * 
 * Created on September 21, 2017, 8:33 AM
 */

#include "QPAProtoNode.h"
#include "QPATvbuff.h"
#include "QPAHeaderFieldInfo.h"
#include "QPAFieldInfo.h"
#include "QPAGlobalHFMetaInfo.h"
#include <stdarg.h>


/* Throw an exception if our tree exceeds these. */
/* XXX - These should probably be preferences */
#define MAX_TREE_ITEMS (1 * 1000 * 1000)
#define MAX_TREE_LEVELS (5 * 100)


QPAProtoNode::QPAProtoNode()
{
    
}

QPAProtoNode::~QPAProtoNode()
{
}

bool QPAProtoNode::proto_tree_add_item(int hfindex, shared_ptr<QPATvbuff> tvb, const int start, int length, const unsigned int encoding)
{
    register shared_ptr<QPAHeaderFieldInfo> hfinfo;    
}





QPAProtoNode* QPAProtoNode::proto_tree_add_protocol_format(int hfindex, shared_ptr<QPATvbuff> tvb, int start, int length, const char* format, ...)
{
    
    va_list ap;
    shared_ptr<QPAHeaderFieldInfo> hfinfo = QPAGlobalHFMetaInfo::hfinfo(hfindex);
    if(hfinfo->_type != FT_PROTOCOL)
        return nullptr;
    QPAProtoNode *pi = proto_tree_add_pi(hfinfo, tvb, start, &length);
    va_start(ap, format);
    pi->proto_tree_set_representation(format, ap);
    va_end(ap);
    return pi;
    
    
    
}

void QPAProtoNode::proto_tree_set_representation(const char* format, va_list ap)
{
    shared_ptr<QPAFieldInfo> fi = finfo;
    char buf[1024];
    vsprintf(buf, format, ap);
    fi->rep = buf;
}





QPAProtoNode* QPAProtoNode::proto_tree_add_pi(shared_ptr<QPAHeaderFieldInfo> hfinfo, shared_ptr<QPATvbuff> tvb, int start, int* length)
{
    QPAProtoNode *pi = nullptr;
    int item_length = 0;
    hfinfo->get_hfi_length(tvb, start, length, &item_length);
    shared_ptr<QPAFieldInfo> fi = make_shared<QPAFieldInfo>(this, hfinfo, tvb, start, item_length);
    pi = proto_tree_add_node(fi);
    return pi;
}

QPAProtoNode* QPAProtoNode::proto_tree_add_node(shared_ptr<QPAFieldInfo> fi)
{
    QPAProtoNode *pnode, *tnode, *sibling;
    
    int depth = 1;
    if(first_child == nullptr)
    {
        for(tnode = this; tnode != nullptr; tnode = tnode->parent)
        {
            depth++;
            if(depth > MAX_TREE_LEVELS)
                return nullptr;
        }
    }
    tnode = this;
    shared_ptr<QPAFieldInfo> tfi = tnode->finfo;
    if(tfi != nullptr && (tfi->tree_type <0 || tfi->tree_type >= 32))
        return nullptr;
    pnode = new QPAProtoNode;
    pnode->parent = tnode;
    pnode->finfo = fi;
    if(tnode->last_child != nullptr)
    {
        sibling = tnode->last_child;
        if(sibling->next != nullptr)
            sibling->next = pnode;
    }
    else
        tnode->first_child = pnode;
    tnode->last_child = pnode;
    return pnode;
}
