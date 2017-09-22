/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAPacketInfo.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 8:36 AM
 */

#ifndef QPAPACKETINFO_H
#define QPAPACKETINFO_H

#include <string>
#include <memory>
#include <list>

#include "QPAFrameData.h"
#include "QPAAddress.h"
#include "QPADissectionSession.h"

using namespace std;

/* Also defined in epan/packet_info.h */
#define P2P_DIR_UNKNOWN -1
#define P2P_DIR_SENT     0
#define P2P_DIR_RECV     1
/* Link direction */
#define LINK_DIR_UNKNOWN    -1
#define P2P_DIR_UL  0
#define P2P_DIR_DL  1


class QPAFrameData;
class QPAAbstractPacketHeader;
class QPAPacketInfo
{
public:
    QPAPacketInfo();
    QPAPacketInfo(const QPAPacketInfo& orig) = delete;
    QPAPacketInfo(const QPAPacketInfo&& orig) = delete;
    QPAPacketInfo& operator=(const QPAPacketInfo& orig) = delete;
    QPAPacketInfo& operator=(const QPAPacketInfo&& orig) = delete;
    virtual ~QPAPacketInfo();
    void init();

protected:

public:
    string _current_proto;
    shared_ptr<QPAFrameData> _fd;
    shared_ptr<QPAAbstractPacketHeader> _phdr;
    shared_ptr<QPAAddress> _dl_src;
    shared_ptr<QPAAddress> _dl_dst;
    shared_ptr<QPAAddress> _net_src;
    shared_ptr<QPAAddress> _net_dst;
    shared_ptr<QPAAddress> _src;
    shared_ptr<QPAAddress> _dst;
    circuit_type _ctype = CT_NONE;
    unsigned int _circuit_id;
    string _noreassembly_reason;
    bool _fragmented;
    port_type _ptype = PT_NONE;
    unsigned int _scrport;
    unsigned int _destport;
    unsigned int _match_uint;
    string _match_string;
    unsigned short _can_desegment;
    unsigned short _saved_can_desegment;
    int _desegment_offset;
    unsigned int _desegment_len;
    unsigned short _want_pdu_tracking;
    unsigned int _bytes_until_next_pdu;
    int _p2p_dir = P2P_DIR_UNKNOWN;
    int _link_dir = LINK_DIR_UNKNOWN;
    
    list<void*> _proto_data;
    list<void*> _dependent_frames;
    list<void*> _frame_end_routineds;
    shared_ptr<QPADissectionSession> _epan;
    shared_ptr<QPATimestamp> _rel_ts;
    string _heur_list_name;
    

};

#endif /* QPAPACKETINFO_H */

