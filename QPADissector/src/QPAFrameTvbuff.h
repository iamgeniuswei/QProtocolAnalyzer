/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFrameTvbuff.h
 * Author: lenovo
 *
 * Created on September 22, 2017, 5:07 PM
 */

#ifndef QPAFRAMETVBUFF_H
#define QPAFRAMETVBUFF_H
#include <memory>

#include "QPATvbuff.h"
using namespace std;
class QPAFrameTvbuff : public QPATvbuff
{
    
public:
    QPAFrameTvbuff();
    QPAFrameTvbuff(const QPAFrameTvbuff& orig) = delete;
    QPAFrameTvbuff(const QPAFrameTvbuff&& orig) = delete;
    QPAFrameTvbuff& operator=(const QPAFrameTvbuff& orig) = delete;
    QPAFrameTvbuff& operator=(const QPAFrameTvbuff&& orig) = delete;
    virtual ~QPAFrameTvbuff();
    void frame_tvbuff_new(shared_ptr<QPAFrameData> fd,
                                                    const unsigned char *buf);
protected:

private:
};

#endif /* QPAFRAMETVBUFF_H */

