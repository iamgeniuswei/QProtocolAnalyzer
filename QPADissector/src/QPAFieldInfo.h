/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFieldInfo.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 4:51 PM
 */

#ifndef QPAFIELDINFO_H
#define QPAFIELDINFO_H

#include <memory>

#include "QPAHeaderFieldInfo.h"
#include "QPAProtoNode.h"


class QPAHeaderFieldInfo;
class QPATvbuff;
class QPAProtoNode;
class QPAFieldInfo
{
    friend class QPAProtoNode;
public:
    QPAFieldInfo(QPAProtoNode* tree,
                 shared_ptr<QPAHeaderFieldInfo> hfinfo,
                 shared_ptr<QPATvbuff> tvb,
                 const int start,
                 const int item_length);
    QPAFieldInfo(const QPAFieldInfo& orig) = delete;
    QPAFieldInfo(const QPAFieldInfo&& orig) = delete;
    QPAFieldInfo& operator=(const QPAFieldInfo& orig) = delete;
    QPAFieldInfo& operator=(const QPAFieldInfo&& orig) = delete;
    virtual ~QPAFieldInfo();

protected:

public:
    std::shared_ptr<QPAHeaderFieldInfo> hfinfo; /**< pointer to registered field information */
    int start; /**< current start of data in field_info.ds_tvb */
    int length; /**< current data length of item in field_info.ds_tvb */
    int appendix_start; /**< start of appendix data */
    int appendix_length; /**< length of appendix data */
    int tree_type; /**< one of ETT_ or -1 */
    unsigned int flags; /**< bitfield like FI_GENERATED, ... */
    std::string rep; /**< string for GUI tree */
    std::shared_ptr<QPATvbuff> ds_tvb; /**< data source tvbuff */
//    fvalue_t value;

};

#endif /* QPAFIELDINFO_H */

