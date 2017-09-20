/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPATimestamp.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 4:34 PM
 */

#ifndef QPATIMESTAMP_H
#define QPATIMESTAMP_H

#include <ctime>


class QPATimestamp
{
public:
    QPATimestamp();
    QPATimestamp(const QPATimestamp& orig) = delete;
    QPATimestamp(const QPATimestamp&& orig) = delete;
    QPATimestamp& operator=(const QPATimestamp& orig) = delete;
    QPATimestamp& operator=(const QPATimestamp&& orig) = delete;
    virtual ~QPATimestamp();

protected:

private:
    time_t secs;
    int nsecs;

};

#endif /* QPATIMESTAMP_H */

