/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAProtocol.h
 * Author: lenovo
 *
 * Created on September 20, 2017, 11:04 AM
 */

#ifndef QPAPROTOCOL_H
#define QPAPROTOCOL_H

#include <string>
#include <vector>
#include <list>


class QPAProtocol
{
    friend class QPADissector;
public:
    QPAProtocol();
    QPAProtocol(const QPAProtocol& orig) = delete;
    QPAProtocol(const QPAProtocol&& orig) = delete;
    QPAProtocol& operator=(const QPAProtocol& orig) = delete;
    QPAProtocol& operator=(const QPAProtocol&& orig) = delete;
    virtual ~QPAProtocol();

protected:

private:
    std::string _name;
    std::string _shortName;
    std::string _filterName;
//    std::vector<void*> _fields;
    int _protoID;
    bool _isEnabled;
    bool _canToggle;
//    std::list<void> _heurList;
};

#endif /* QPAPROTOCOL_H */

