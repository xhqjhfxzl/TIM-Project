//
//  People.cpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/11.
//

#include "People.hpp"

extern map<string, string> custom_data;
extern map<string, string> admin_data;

bool Custom::createAccount(string name, string passwd) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        custom_data[name] = passwd;
        return 1;
    }
    return 0;
    
}


int Custom::login(string name, string passwd) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "登录失败,没找到用户信息" << endl;
        return 3;
    }
    else if(l_it -> second != passwd) {
        cout << "登录失败,密码错误" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "登录成功" << endl;
        cout << "欢迎进入用户界面" << endl;
        return 1;
    }
    return 0;
}

/* 因为没有去写后台类，所以这里的查找记录默认全都找到 */
bool Custom::searchRecord(string typeOfRecord) {
    string name;
    cout << "请输入要查询的联系人" << endl;
    cin >> name;
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "没有找到联系人" << endl;
        return false;
    }
    /* 后期可以增加后台类，用vector来维护用户信息 */
    if(typeOfRecord == "word") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search word successfully" << endl << endl;
    }
    else if(typeOfRecord == "image") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search image successfully" << endl << endl;
    }
    else if(typeOfRecord == "video") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search video successfully" << endl << endl;
    }
    else if(typeOfRecord == "emoji") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search emoji successfully" << endl << endl;
    }
    return true;
}

void Custom::doNewsOperations(string typeOfOperations) {
    if(typeOfOperations == "send") {
        Context * context1 = new Context(new NewsOperation_sendNews());
        context1 -> executeStrategy();
        delete context1;
    }
    else if(typeOfOperations == "revoke") {
        Context * context2 = new Context(new NewsOperation_revokeNews);
        context2 -> executeStrategy();
        delete context2;
    }
    else if(typeOfOperations == "receive") {
        Context * context3 = new Context(new NewsOperation_receiveNews);
        context3 -> executeStrategy();
        delete context3;
    }
    else {
        //cout << "invalid operations" << endl;
        cout << "不合法的操作" << endl;
    }
}

void Custom::manageRecord() {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(
                                                  name);
    if(isClean == 1) {
        cout << "成功删除了一些久远的用户记录" << endl;
    }
    else {
        cout << "删除失败" << endl;
    }
}

void Custom::getPersonalSettings() {
    Background background;
    string settings = background.getPersonalSettings(name);
    cout << settings << endl;
}


int Admin::login(string name, string passwd) {
    map<string, string>::iterator l_it = admin_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "登录失败,没找到用户信息" << endl;
        return 4;
    }
    else if(l_it -> second != passwd) {
        cout << "登录失败,密码错误" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "登录成功" << endl;
        cout << "欢迎进入管理员界面" << endl;
        return 2;
    }
    return 0;
}

void Admin::manageRecord(string name) {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(name);
    if(isClean == 1) {
        cout << "成功删除了一些久远的用户记录" << endl;
    }
    else {
        cout << "删除失败" << endl;
    }
}

void Admin::getPersonalRecord(string name) {
    Background background;
    string record = background.getPersonalRecord(name);
    cout << record << endl;
}

void Admin::getPersonalSettings(string name) {
    Background background;
    string settings = background.getPersonalSettings(name);
    cout << settings << endl;
}

void Admin::resetPersonalSettings(string name) {
    Background background;
    bool isSettings = background.resetPersonalSettings(name);
    if(isSettings == 0) {
        cout << "重制用户设置信息失败" << endl;
    }
    else {
        cout << "重制用户设置信息成功" << endl;
    }
}

int PeopleFactory::getLogin(string typeOfPeople) {
    if(typeOfPeople == "custom") {
        Custom customForLogin;
        return customForLogin.login(name, passwd);
    }
    else if(typeOfPeople == "admin") {
        Admin adminForLogin;
        return adminForLogin.login(name, passwd);
    }
    return 0;
}



