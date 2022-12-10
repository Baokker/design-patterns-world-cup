#pragma once

#include <iostream>
using namespace std;

class Handler
{
public:
    Handler();
    virtual ~Handler();
    void setNextHandler(Handler* next);
    virtual void handleRequest(int level);
protected:
    Handler* nextHandler;
};

class InterimCommittee :public Handler
{
public:
    InterimCommittee();
    ~InterimCommittee() override;
    void handleRequest(int level);
};

class ExecutiveCommittee :public Handler
{
public:
    ExecutiveCommittee();
    ~ExecutiveCommittee() override;
    void handleRequest(int level);
};

class PlenarySession :public Handler
{
public:
    PlenarySession();
    ~PlenarySession() override;
    void handleRequest(int level);
};

void testChainOfResponsibility();