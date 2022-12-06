#include <iostream>
#include "ChainofResponsibility.h"
using namespace std;

Handler::Handler() { NextHandler = NULL; }
Handler::~Handler() {}
void Handler::SetNextHandler(Handler* next) { NextHandler = next; }
void Handler::HandleRequest(int level) {}

InterimCommittee::InterimCommittee() {}
//�ͷ�ָ��ռ�
InterimCommittee::~InterimCommittee()
{
    delete NextHandler;
}
//����������
void InterimCommittee::HandleRequest(int level)
{
    cout << "�����ѱ��ݽ����ڲ�ίԱ�ᣬ���Ե�" << endl;
    if (level <= 1)//�ж�Ȩ��
    {
        cout << "�����ѱ��ڲ�ίԱ�ᴦ��" << endl;
    }
    else//���������ƽ�����һ������
    {
        cout << "�ڲ�ίԱ����Ȩ�������ڵݽ�ִ��ίԱ��" << endl;
        NextHandler->HandleRequest(level);
    }
}

ExecutiveCommittee::ExecutiveCommittee() {}
//�ͷ�ָ��ռ�
ExecutiveCommittee::~ExecutiveCommittee()
{
     delete NextHandler;
}
//����������
void ExecutiveCommittee::HandleRequest(int level)
{
    cout << "�����ѱ��ݽ���ִ��ίԱ�ᣬ���Ե�" << endl;
    if (level <= 2)//�ж�Ȩ��
    {
        cout << "�����ѱ�ִ��ίԱ�ᴦ��" << endl;
    }
    else//���������ƽ�����һ������
    {
        cout << "ִ��ίԱ����Ȩ�������ڵݽ�ȫ�����" << endl;
        NextHandler->HandleRequest(level);
    }
}

PlenarySession::PlenarySession() {}
//�ͷ�ָ��ռ�
PlenarySession::~PlenarySession()
{
    delete NextHandler;
}

//����������
void PlenarySession::HandleRequest(int level)
{
    cout << "�����ѱ��ݽ���ȫ��ίԱ�ᣬ���Ե�" << endl;
    if (level <= 3)//�ж�Ȩ��
    {
        cout << "�����ѱ�ȫ��ίԱ�ᴦ��" << endl;
    }
    else//���������ƽ�����һ������
    {
        cout << "ȫ��ίԱ��Ȩ�������߱�����" << endl;
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
        cout << "һ����Ա����ί���������" << endl;
        interimcommittee->HandleRequest(i);
        cout << endl;
    }
}