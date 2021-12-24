//
//  background.hpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/14.
//

#ifndef background_hpp
#define background_hpp

#include "Header.h"

class Background {
public:
    string getPersonalRecord(string name);
    string getPersonalSettings(string name);
    bool cleanPersonalRecord(string name);
    bool resetPersonalSettings(string name);
};

#endif /* background_hpp */
