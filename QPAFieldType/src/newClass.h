/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newClass.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 9:15 AM
 */

#ifndef NEWCLASS_H
#define NEWCLASS_H

class newClass
{
public:
    newClass();
    newClass(const newClass& orig) = delete;
    newClass(const newClass&& orig) = delete;
    newClass& operator=(const newClass& orig) = delete;
    newClass& operator=(const newClass&& orig) = delete;
    virtual ~newClass();

protected:

private:

};

#endif /* NEWCLASS_H */

