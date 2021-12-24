//
//  background.cpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/14.
//

#include "background.hpp"

extern map<string, string> custom_data;
extern map<string, string> admin_data;

string Background::getPersonalRecord(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        return "background:查询用户记录失败";
    }
    /* 查询记录 */
    return "background:返回用户记录";
}

string Background::getPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        return "background:查找用户设置信息失败";
    }
    /* 查找用户设置信息 */
    return "background:返回用户设置信息";
}

bool Background::cleanPersonalRecord(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        cout << "background:删除用户记录失败" << endl;
        return false;
    }
    /* 删除用户记录 */
    return true;
}

bool Background::resetPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        cout << "background:重制用户设置信息失败" << endl;
        return false;
    }
    /* 修改用户设置信息 */
    return true;
}
