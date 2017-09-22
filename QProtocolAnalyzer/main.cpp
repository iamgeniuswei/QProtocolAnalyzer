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
#include "dissectors/packet-frame.h"
#include "QPAProtocolHelper.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << "-----------------QProtocolAnalyzer Ver 1.00.00-----------------" << endl;
    cout << sizeof(size_t) << endl;
    proto_register_frame();

    std::string path = "/home/lenovo/PCAP/test2.pcap";
    shared_ptr<QPAPacketReader> reader = make_shared<QPAPacketReader>();
    cout << reader->openPacketFile(path) << endl;
    reader->readPacket();
   
//    QPAProtocolHelper *helper = new QPAProtocolHelper;
//    std::string name = "ftp";
//    cout << helper->wrs_str_hash(name.c_str()) << endl;
//    cout << helper->wrs_str_hash("smtp") << endl;
//    cout << helper->wrs_str_hash("pop3") << endl;
//    cout << helper->wrs_str_hash("ftp") << endl;
//    cout << helper->wrs_str_hash("qq") << endl;
    return 0;
}

