/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissectionSession.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 5:33 PM
 */

#ifndef QPADISSECTIONSESSION_H
#define QPADISSECTIONSESSION_H

#include <memory>

#include "QPAFrameData.h"

class QPATimestamp;
class QPADissectionSession
{
public:
    QPADissectionSession();
    QPADissectionSession(const QPADissectionSession& orig) = delete;
    QPADissectionSession(const QPADissectionSession&& orig) = delete;
    QPADissectionSession& operator=(const QPADissectionSession& orig) = delete;
    QPADissectionSession& operator=(const QPADissectionSession&& orig) = delete;
    virtual ~QPADissectionSession();
    virtual std::shared_ptr<QPATimestamp> get_frame_ts(void *data, unsigned int frame_num) = 0;
    virtual std::string get_interface_name(void *data, unsigned int interface_id) = 0;
    virtual std::string get_user_comment(void *data, std::shared_ptr<QPAFrameData> fd) = 0;
protected:

private:
    void *data;

};

#endif /* QPADISSECTIONSESSION_H */

