//
//  main.cpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/11.
//

#include "People.hpp"

/* 后期可将custom_data和admin_data写到文件进行保存 */
map<string, string> custom_data;
map<string, string> admin_data;

//初始化用户数据custom_data、管理员数据admin_data
void initPersonData() {
    custom_data["C1"] = "123";
    custom_data["C2"] = "456";
    admin_data["A1"] = "123";
    admin_data["A2"] = "456";
}

void timeForCustom(string, string);
void timeForAdmin(string, string);

int main(int argc, const char * argv[]) {
    string type;
    string name;
    string passwd;
    string typeOfPeople;
    string isToRegister;
    int isLogin = 0;
    
    initPersonData();
    cout << "       welcome come to TIM    " << endl << endl;
    cout << "请输入你的登录类型(custom or admin)、名字、密码" << endl;
    cin >> typeOfPeople >> name >> passwd;

    PeopleFactory peoplefactory(name, passwd);
    isLogin = peoplefactory.getLogin(typeOfPeople);
    if(isLogin == 1) {
        timeForCustom(name, passwd);
    }
    else if(isLogin == 2) {
        timeForAdmin(name, passwd);
    }
    else if(isLogin == 3) {
        cout << "你希望我们为你创建一个用户账号吗(input y or n)" << endl;
        cin >> isToRegister;
        if(isToRegister == "y") {
            Custom customForRegister;
            bool isCreate = customForRegister.createAccount(name, passwd);
            if(isCreate == 1) {
                cout << "成功创建用户账户" << endl;
            }
            else {
                cout << "创建用户账户失败" << endl;
            }
        }
    }
    else if(isLogin == 4) {
        cout << "无法登录管理员账户" << endl;
    }
   
    return 0;
}

void timeForCustom(string name, string passwd) {
    Custom custom(name, passwd);
    int thing;
    /* custom */
    while(1) {
        cout << "请输入你想做的事" << endl;
        cout << "*****" << endl;
        cout << "1.createAccount" << endl;
        cout << "2.send news" << endl;
        cout << "3.revoke news" << endl;
        cout << "4.receive news" << endl;
        cout << "5.search records" << endl;
        cout << "6.manage records" << endl;
        cout << "7.get settings" << endl;
        cout << "8.quit" << endl;
        cout << "*****" << endl;
        cin >> thing;
        if(thing == 1) {
            string newName;
            string newPasswd;
            cout << "请为新账户输入名字和密码" << endl;
            cin >> newName >> newPasswd;
            bool isCreate = custom.createAccount(newName, newPasswd);
            if(isCreate == 1) {
                //cout << "create custom account successfully" << endl;
                cout << "用户账户创建成功" << endl;
            }
            else {
                //cout << "custom account aready exits" << endl;
                cout << "该用户账户已经存在" << endl;
            }
        }
        else if(thing == 2) {
            custom.doNewsOperations("send");
        }
        else if(thing == 3) {
            custom.doNewsOperations("revoke");
        }
        else if(thing == 4) {
            custom.doNewsOperations("receive");
        }
        else if(thing == 5) {
            string typeOfRecord;
            bool isSearch;
            //cout << "input type of records you want to search(word、image、video、emoji)" << endl;
            cout << "请输入你要查询的记录类型(word、image、video、emoji)" << endl;
            cin >> typeOfRecord;
            isSearch = custom.searchRecord(typeOfRecord);
            if(isSearch == 0) {
                //cout << "do not find the record" << endl;
                cout << "没有找到该记录" << endl;
            }
        }
        else if(thing == 6) {
            custom.manageRecord();
        }
        else if(thing == 7) {
            custom.getPersonalSettings();
        }
        else if(thing == 8) {
            //cout << "succeed to quit" << endl;
            cout << "成功退出" << endl;
            break;
        }
    }
}

void timeForAdmin(string name, string passwd) {
    Admin admin(name, passwd);
    int thing;
    string customName;
    /* admin */
    while(1) {
        //cout << "input things you want to do" << endl;
        cout << "请输入你想做的事" << endl;
        cout << "*****" << endl;
        cout << "1.manage record" << endl;
        cout << "2.get custom record" << endl;
        cout << "3.get custom settings" << endl;
        cout << "4.reset custom settings" << endl;
        cout << "5.quit" << endl;
        cout << "*****" << endl;
        cin >> thing;
        if(thing == 1) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.manageRecord(customName);
        }
        else if(thing == 2) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.getPersonalRecord(customName);
        }
        else if(thing == 3) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.getPersonalSettings(customName);
        }
        else if(thing == 4) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.resetPersonalSettings(customName);
        }
        else if(thing == 5) {
            //cout << "succeed to quit" << endl;
            cout << "成功退出" << endl;
            break;
        }
    }
}
