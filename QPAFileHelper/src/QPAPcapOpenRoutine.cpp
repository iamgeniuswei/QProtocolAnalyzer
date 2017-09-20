/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAPcapOpenRoutine.cpp
 * Author: lenovo
 * 
 * Created on 2017年9月18日, 下午5:29
 */

#include <cstring>

#include "QPAPcapOpenRoutine.h"
#include "QPAFileMediator.h"

QPAPcapOpenRoutine::QPAPcapOpenRoutine(QPAFileMediator* mediator)
:QPAOpenRoutine(mediator)
{
}

QPAPcapOpenRoutine::QPAPcapOpenRoutine(const QPAPcapOpenRoutine& orig)
{
}

QPAPcapOpenRoutine::~QPAPcapOpenRoutine()
{
}

wtap_open_return_val
QPAPcapOpenRoutine::openRoutine()
{
    if(_mediator == nullptr)
        return WTAP_OPEN_ERROR;
    unsigned int magic = 0;
    _mediator->readBytes(&magic, sizeof(magic));
    switch(magic)
    {
        case PCAP_MAGIC:
        {
//            return WTAP_OPEN_MINE;
            break;
        }
    }
    pcap_hdr hdr;
    if(!_mediator->readBytes(&hdr, sizeof(hdr)))
        return WTAP_OPEN_ERROR;
    return WTAP_OPEN_MINE;
}

bool
QPAPcapOpenRoutine::readPacket(ssize_t * offset)
{
    pcaprec_hdr hdr;
    memset(&hdr, 0, sizeof(pcaprec_hdr));
    if(!libpcapReadHead(&hdr))
        return false;
    unsigned int packet_size = hdr.incl_len;
    unsigned int orig_size = hdr.orig_len;
    
    
    if(!_mediator->readPacketToBuffer(packet_size))
        return false;
    return true;
}

//TODO:最基本头部读取功能,后期扩展
bool
QPAPcapOpenRoutine::libpcapReadHead(pcaprec_hdr* hdr)
{
    int bytes_to_read = sizeof(pcaprec_hdr);
    if(!_mediator->readBytes(hdr, bytes_to_read))
        return false;
    return true;
    
}




