#ifndef ATCCSCONTROLLERMANAGER_H
#define ATCCSCONTROLLERMANAGER_H

#include <map>
#include <memory>
#include <iostream>
/**
 * key-value数据管理器模板类
 */
template <typename U,  typename T>
class QPAMapManager
{
public:
    explicit QPAMapManager()
    {

    }
    ~QPAMapManager()
    {
        _controllers.clear();
    }

    bool registerController(U id, std::shared_ptr<T> controller = nullptr)
    {
        if(controller == nullptr)
        {            
            return false;
        }
        auto search = _controllers.find(id);
        if(search != _controllers.end())
        {            
            return false;
        }
        _controllers.insert(std::pair<U, std::shared_ptr<T>>(id, controller));
    }

    std::shared_ptr<T> controller(U id)
    {
        auto search = _controllers.find(id);
        if(search == _controllers.end())
        {            
            return nullptr;
        }

        std::shared_ptr<T> temp = search->second;
        return temp;
    }

private:
    std::map<U, std::shared_ptr<T>> _controllers;
};

#endif // ATCCSCONTROLLERMANAGER_H
