/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on 2017年9月18日, 下午4:18
 */

#include <cstdlib>
#include <iostream>
#include <memory>
using namespace std;
#include "QPAFileInfo.h"
#include "QPAFileReader.h"
#include "QPAPacketReader.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << "-----------------QProtocolAnalyzer Ver 1.00.00-----------------" << endl;
    cout << sizeof(size_t) << endl;
//    QPAFileInfo info;
//    cout << info.setFile("/media/lenovo/10b683ed-ef62-4ea5-ac0b-8cc75ff5f287/lenovo/Downloads") << endl;
//    cout << info.fileSize() << endl;
//    cout << info.isFile() << endl;
    std::string path = "/home/lenovo/PCAP/test2.pcap";
    shared_ptr<QPAPacketReader> reader = make_shared<QPAPacketReader>();
    cout << reader->openPacketFile(path) << endl;
    reader->readPacket();
    return 0;
}

