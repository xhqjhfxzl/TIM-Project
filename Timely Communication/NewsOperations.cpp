//
//  NewsOperations.cpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/11.
//

#include "NewsOperations.hpp"

extern map<string, string> custom_data;

void NewsOperation_sendNews::doNewsOperations() {
    string receiver;
    string message;
    cout << "输入要发送的联系人" << endl;
    cin >> receiver;
    map<string, string>::iterator l_it = custom_data.find(receiver);
    if(l_it == custom_data.end()) {
        cout << "没找到要发送的联系人" << endl;
    }
    else {
        /* 发送消息 */
        cout << "请输入要发送的信息" << endl;
        cin >> message;
        /* 消息审核(为了简化，如果输入123则判断为非法，发送失败) */
        if(message == "123") {
            cout << "发送失败，审核未通过" << endl;
        }
        else {
            cout << "发送消息成功" << endl;
        }
    }
}

void NewsOperation_revokeNews::doNewsOperations() {
    //cout << "revoke news successfully" << endl;
    cout << "撤回消息成功" << endl;
}

void NewsOperation_receiveNews::doNewsOperations() {
    //cout << "receive news successfully" << endl;
    cout << "接收消息成功" << endl;
}
