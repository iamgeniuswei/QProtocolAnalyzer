/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAAbstractPacketHeader.cpp
 * Author: lenovo
 * 
 * Created on September 20, 2017, 4:32 PM
 */

#include "QPAAbstractPacketHeader.h"

QPAAbstractPacketHeader::QPAAbstractPacketHeader()
{
}

QPAAbstractPacketHeader::~QPAAbstractPacketHeader()
{
}

unsigned int QPAAbstractPacketHeader::rec_type() const
{
    return _rec_type;
}

