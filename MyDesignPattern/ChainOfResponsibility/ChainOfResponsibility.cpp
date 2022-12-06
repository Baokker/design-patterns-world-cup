#include <iostream>
#include "ChainofResponsibility.h"
using namespace std;

Handler::Handler() { NextHandler = NULL; }
Handler::~Handler() {}
void Handler::SetNextHandler(Handler* next) { NextHandler = next; }
void Handler::HandleRequest(int level) {}

InterimCommittee::InterimCommittee() {}
//释放指针空间
InterimCommittee::~InterimCommittee()
{
    delete NextHandler;
}
//处理请求函数
void InterimCommittee::HandleRequest(int level)
{
    cout << "请求已被递交到内部委员会，请稍等" << endl;
    if (level <= 1)//判断权级
    {
        cout << "请求已被内部委员会处理" << endl;
    }
    else//不满足则移交给下一处理者
    {
        cout << "内部委员会无权处理，正在递交执行委员会" << endl;
        NextHandler->HandleRequest(level);
    }
}

ExecutiveCommittee::ExecutiveCommittee() {}
//释放指针空间
ExecutiveCommittee::~ExecutiveCommittee()
{
     delete NextHandler;
}
//处理请求函数
void ExecutiveCommittee::HandleRequest(int level)
{
    cout << "请求已被递交到执行委员会，请稍等" << endl;
    if (level <= 2)//判断权级
    {
        cout << "请求已被执行委员会处理" << endl;
    }
    else//不满足则移交给下一处理者
    {
        cout << "执行委员会无权处理，正在递交全体会议" << endl;
        NextHandler->HandleRequest(level);
    }
}

PlenarySession::PlenarySession() {}
//释放指针空间
PlenarySession::~PlenarySession()
{
    delete NextHandler;
}

//处理请求函数
void PlenarySession::HandleRequest(int level)
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


void TestChainOfResponsibility()
{
    Handler* interimcommittee = new InterimCommittee;
    Handler* executivecommittee = new ExecutiveCommittee;
    Handler* plenarysession = new PlenarySession;

    
    interimcommittee->SetNextHandler(executivecommittee);
    executivecommittee->SetNextHandler(plenarysession);

    for (int i = 1; i < 5; i++)
    {
        cout << "一名球员向组委会提出上诉" << endl;
        interimcommittee->HandleRequest(i);
        cout << endl;
    }
}