//
//  NewsOperations.hpp
//  Timely Communication
//
//  Created by 蔡振 on 2021/12/11.
//

#ifndef NewsOperations_hpp
#define NewsOperations_hpp

#include "Header.h"

class Strategy {
public:
    virtual void doNewsOperations() = 0;
    
};

class NewsOperation_sendNews:public Strategy {
public:
    void doNewsOperations();    /* send news */
};

class NewsOperation_revokeNews:public Strategy {
public:
    void doNewsOperations();    /* revoke news */
};

class NewsOperation_receiveNews: public Strategy {
public:
    void doNewsOperations();    /* receive news */
};

class Context {
    Strategy * strategy;
public:
    Context(Strategy * strategy) {
        this -> strategy = strategy;
    }
    void executeStrategy() {
        strategy -> doNewsOperations();
    }
};

/*
class StrategyPatternDemo {
public:
    void NewsOperations() {
        Context * context1 = new Context(new NewsOperation_sendNews());
        context1 -> executeStrategy();
        Context * context2 = new Context(new NewsOperation_revokeNews());
        context2 -> executeStrategy();
        Context * context3 = new Context(new NewsOperation_receiveNews());
        context3 -> executeStrategy();
    }
};
*/

#endif /* NewsOperations_hpp */
