/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAMetaInfo.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 4:03 PM
 */

#ifndef QPAMETAINFO_H
#define QPAMETAINFO_H

#include <string>
#include <vector>
#include <memory>
#include <stdbool.h>

#include "QPASkeletonDefine.h"
#include "QPATimestamp.h"


class QPAAbstractFile;
class QPAAbstractPacketHeader;
class QPABuffer;
class QPAFrameData;
class QPADissectionSession;

class QPAMetaInfo
{
    friend class QPAPacketReader;
public:
    QPAMetaInfo();
    QPAMetaInfo(const QPAMetaInfo& orig) = delete;
    QPAMetaInfo(const QPAMetaInfo&& orig) = delete;
    QPAMetaInfo& operator=(const QPAMetaInfo& orig) = delete;
    QPAMetaInfo& operator=(const QPAMetaInfo&& orig) = delete;
    virtual ~QPAMetaInfo();
    void init();

protected:

private:
    std::shared_ptr<QPADissectionSession> _epan;
    file_state _state = FILE_READ_IN_PROGRESS;
    std::string _path;
    std::string _source;
    bool _isTempfile;
    bool _unsavedChanges = false;
    bool _stopFlag;
    ssize_t  _size = 0;
    unsigned short _cd_t;
    unsigned int _open_type;
    bool _isCompressed;
    int _link;
    std::vector<std::string> _linkType;
    unsigned int _count;
    ssize_t _packet_comment_count;
    unsigned int _displayed_count;
    unsigned int _marked_count;
    unsigned int _ignored_count;
    unsigned int _ref_time_count;
    bool _drops_known;
    unsigned int _drops;
    QPATimestamp _elapsed_time;
    bool _has_snap;
    int _snap;
    std::shared_ptr<QPAAbstractFile> _wth;
    std::string _dfilter;
    bool _redissecting;
    std::string _sfilter;
    bool _hex;
    bool _string;
    bool _summary_data;
    bool _decode_data;
    bool _packet_data;
    unsigned int _search_pos;
    bool _case_type;
    
    // packet data
    std::shared_ptr<QPAAbstractPacketHeader> _phdr;
    std::shared_ptr<QPABuffer> _buf;
    
    //frames
    unsigned int _first_displayed;
    unsigned int _last_displayed;
    std::shared_ptr<QPAFrameData> _current_frame;
    unsigned int _current_row;
    std::shared_ptr<QPAFrameData> _prev_dis;
    std::shared_ptr<QPAFrameData> _prev_cap; 
};

#endif /* QPAMETAINFO_H */

