/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAValueString.h
 * Author: lenovo
 *
 * Created on September 21, 2017, 10:43 AM
 */

#ifndef QPAVALUESTRING_H
#define QPAVALUESTRING_H
#include <string>
using namespace std;
class QPAValueString
{
public:
    QPAValueString();
    QPAValueString(const QPAValueString& orig) = delete;
    QPAValueString(const QPAValueString&& orig) = delete;
    QPAValueString& operator=(const QPAValueString& orig) = delete;
    QPAValueString& operator=(const QPAValueString&& orig) = delete;
    virtual ~QPAValueString();

protected:

public:
    unsigned int value;
    string str;

};

#endif /* QPAVALUESTRING_H */

