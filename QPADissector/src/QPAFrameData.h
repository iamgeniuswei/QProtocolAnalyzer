/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFrameData.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 4:46 PM
 */

#ifndef QPAFRAMEDATA_H
#define QPAFRAMEDATA_H
#include "QPAGlobalDefine.h"
class QPAFrameData
{
public:
    QPAFrameData();
    QPAFrameData(const QPAFrameData& orig) = delete;
    QPAFrameData(const QPAFrameData&& orig) = delete;
    QPAFrameData& operator=(const QPAFrameData& orig) = delete;
    QPAFrameData& operator=(const QPAFrameData&& orig) = delete;
    virtual ~QPAFrameData();
    void init();

protected:

private:
    UINT32 num;
    UINT32 pkt_len;
    UINT32 cap_len;
    UINT32 cum_bytes;
    INT64 file_off;
    UINT16 subnum;

};

#endif /* QPAFRAMEDATA_H */

