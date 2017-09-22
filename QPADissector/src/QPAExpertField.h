/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAExpertField.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 10:39 AM
 */

#ifndef QPAEXPERTFIELD_H
#define QPAEXPERTFIELD_H

class QPAExpertField
{
public:
    QPAExpertField();
    QPAExpertField(const QPAExpertField& orig) = delete;
    QPAExpertField(const QPAExpertField&& orig) = delete;
    QPAExpertField& operator=(const QPAExpertField& orig) = delete;
    QPAExpertField& operator=(const QPAExpertField&& orig) = delete;
    virtual ~QPAExpertField();

protected:

public:
    int ei = -1;
    int hf = -1;

};

#endif /* QPAEXPERTFIELD_H */

