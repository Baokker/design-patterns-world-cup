#include <iostream>
#include "ChainofResponsibility.h"
using namespace std;

Handler::Handler() { nextHandler = NULL; }
Handler::~Handler() {}
void Handler::setNextHandler(Handler* next) { nextHandler = next; }
void Handler::handleRequest(int level) {}

InterimCommittee::InterimCommittee() {}
//释放指针空间
InterimCommittee::~InterimCommittee()
{
    delete nextHandler;
}
//处理请求函数
void InterimCommittee::handleRequest(int level)
{
    cout << "请求已被递交到内部委员会，请稍等" << endl;
    if (level <= 1)//判断权级
    {
        cout << "请求已被内部委员会处理" << endl;
    }
    else//不满足则移交给下一处理者
    {
        cout << "内部委员会无权处理，正在递交执行委员会" << endl;
        nextHandler->handleRequest(level);
    }
}

ExecutiveCommittee::ExecutiveCommittee() {}
//释放指针空间
ExecutiveCommittee::~ExecutiveCommittee()
{
     delete nextHandler;
}
//处理请求函数
void ExecutiveCommittee::handleRequest(int level)
{
    cout << "请求已被递交到执行委员会，请稍等" << endl;
    if (level <= 2)//判断权级
    {
        cout << "请求已被执行委员会处理" << endl;
    }
    else//不满足则移交给下一处理者
    {
        cout << "执行委员会无权处理，正在递交全体会议" << endl;
        nextHandler->handleRequest(level);
    }
}

PlenarySession::PlenarySession() {}
//释放指针空间
PlenarySession::~PlenarySession()
{
    delete nextHandler;
}

//处理请求函数
void PlenarySession::handleRequest(int level)
{
    cout << "请求已被递交到全体委员会，请稍等" << endl;
    if (level <= 3)//判断权级
    {
        cout << "请求已被全体委员会处理" << endl;
    }
    else//不满足则移交给下一处理者
    {
        cout << "全体委员无权处理，上诉被搁置" << endl;
    }
}


void testChainOfResponsibility()
{
    Handler* interimcommittee = new InterimCommittee;
    Handler* executivecommittee = new ExecutiveCommittee;
    Handler* plenarysession = new PlenarySession;

    
    interimcommittee->setNextHandler(executivecommittee);
    executivecommittee->setNextHandler(plenarysession);

    for (int i = 1; i < 5; i++)
    {
        cout << "一名球员向组委会提出上诉" << endl;
        interimcommittee->handleRequest(i);
        cout << endl;
    }
}