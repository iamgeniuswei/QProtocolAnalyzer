/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAMapHelper.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 9:31 AM
 */

#ifndef QPAMAPHELPER_H
#define QPAMAPHELPER_H

#include <map>
#include <memory>
#include <iostream>
/**
 * key-value数据管理器模板类
 */
template <typename U,  typename T>
class QPAMapHelper
{
public:
    explicit QPAMapHelper()
    {

    }
    ~QPAMapHelper()
    {
        _map.clear();
    }

    bool registerController(U key, T value = nullptr)
    {
//        if(value == nullptr)
//        {            
//            return false;
//        }
        auto search = _map.find(key);
        if(search != _map.end())
        {            
            return false;
        }
        _map.insert(std::pair<U, T>(key, value));
    }

    T controller(U key)
    {
        auto search = _map.find(key);
        if(search == _map.end())
        {            
            return nullptr;
        }

        std::shared_ptr<T> temp = search->second;
        return temp;
    }

private:
    std::map<U, T> _map;
};

#endif /* QPAMAPHELPER_H */

