/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPADissector.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 10:59 AM
 */

#ifndef QPADISSECTOR_H
#define QPADISSECTOR_H

#include <string>
#include "QPADissectorDefine.h"

class QPADissector
{
    friend class QPADissectorHelper;
public:
    QPADissector();
    QPADissector(const QPADissector& orig) = delete;
    QPADissector(const QPADissector&& orig) = delete;
    QPADissector& operator=(const QPADissector& orig) = delete;
    QPADissector& operator=(const QPADissector&& orig) = delete;
    virtual ~QPADissector();

protected:

private:
    std::string _name;
    bool _isNew;
    union
    {
        dissector_t _old;
        new_dissector_t _new;
    }dissector;

};

#endif /* QPADISSECTOR_H */

