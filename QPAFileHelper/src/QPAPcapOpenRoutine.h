/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAPcapOpenRoutine.h
 * Author: lenovo
 *
 * Created on 2017年9月18日, 下午5:29
 */

#ifndef QPAPCAPOPENROUTINE_H
#define QPAPCAPOPENROUTINE_H

#include "QPAOpenRoutine.h"


class QPAPcapOpenRoutine : public QPAOpenRoutine
{
public:
    QPAPcapOpenRoutine(QPAAbstractFile* mediator = nullptr);
    QPAPcapOpenRoutine(const QPAPcapOpenRoutine& orig);
    virtual ~QPAPcapOpenRoutine();
    wtap_open_return_val openRoutine() override;
    bool readPacket(ssize_t * offset) override;
    

protected:
    bool libpcapReadHead(pcaprec_hdr* hdr);
private:

};

#endif /* QPAPCAPOPENROUTINE_H */

