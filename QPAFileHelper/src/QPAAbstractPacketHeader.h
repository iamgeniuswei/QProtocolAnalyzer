/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAAbstractPacketHeader.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 4:32 PM
 */

#ifndef QPAABSTRACTPACKETHEADER_H
#define QPAABSTRACTPACKETHEADER_H
#include <string>
#include <memory>
#include "QPATimestamp.h"
class QPABuffer;
class QPAAbstractPacketHeader
{
public:
    QPAAbstractPacketHeader();
    QPAAbstractPacketHeader(const QPAAbstractPacketHeader& orig) = delete;
    QPAAbstractPacketHeader(const QPAAbstractPacketHeader&& orig) = delete;
    QPAAbstractPacketHeader& operator=(const QPAAbstractPacketHeader& orig) = delete;
    QPAAbstractPacketHeader& operator=(const QPAAbstractPacketHeader&& orig) = delete;
    virtual ~QPAAbstractPacketHeader();

protected:

private:
    unsigned int _rec_type;
    unsigned int _presence_flags;
    QPATimestamp _ts;
    unsigned int _caplen;
    unsigned int _len;
    unsigned int _pkt_encap;
    unsigned int _pkt_tsprec;
    unsigned int _interface_id;
    std::string _opt_comment;
    ssize_t _drop_count;
    unsigned int _pack_flag;
    std::shared_ptr<QPABuffer> _ft_specific_data;

};

#endif /* QPAABSTRACTPACKETHEADER_H */

