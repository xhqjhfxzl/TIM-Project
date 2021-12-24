//
//  People.hpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/11.
//

#ifndef People_hpp
#define People_hpp

#include "Header.h"
#include "NewsOperations.hpp"
#include "background.hpp"

class People {
    string name;
    string passwd;
public:
    int login(string name, string passwd);
};

class Custom: People {
    string name;
    string passwd;
public:
    Custom(string name, string passwd):name(name),passwd(passwd){}
    Custom(){}
    bool createAccount(string name, string passwd);
    void doNewsOperations(string typeOfOperations);
    bool searchRecord(string typeOfRecord);
    int login(string name, string passwd);
    void manageRecord();
    void getPersonalSettings();
    
};

class Admin: People {
    string name;
    string passwd;
    
public:
    Admin(string name, string passwd):name(name),passwd(passwd){}
    Admin(){}
    int login(string name, string passwd);
    void manageRecord(string name);
    void getPersonalRecord(string name);
    void getPersonalSettings(string name);
    void resetPersonalSettings(string name);
};

class PeopleFactory {
    string name;
    string passwd;
public:
    PeopleFactory(string name, string passwd) {
        this -> name = name;
        this -> passwd = passwd;
    }
    int getLogin(string typeOfPeople);
};

#endif /* People_hpp */
