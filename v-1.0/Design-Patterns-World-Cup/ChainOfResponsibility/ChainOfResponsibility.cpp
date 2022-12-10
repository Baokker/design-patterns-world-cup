#include <iostream>
#include "ChainofResponsibility.h"
using namespace std;

Handler::Handler() { nextHandler = NULL; }
Handler::~Handler() {}
void Handler::setNextHandler(Handler* next) { nextHandler = next; }
void Handler::handleRequest(int level) {}

InterimCommittee::InterimCommittee() {}
//�ͷ�ָ��ռ�
InterimCommittee::~InterimCommittee()
{
    delete nextHandler;
}
//����������
void InterimCommittee::handleRequest(int level)
{
    cout << "�����ѱ��ݽ����ڲ�ίԱ�ᣬ���Ե�" << endl;
    if (level <= 1)//�ж�Ȩ��
    {
        cout << "�����ѱ��ڲ�ίԱ�ᴦ��" << endl;
    }
    else//���������ƽ�����һ������
    {
        cout << "�ڲ�ίԱ����Ȩ�������ڵݽ�ִ��ίԱ��" << endl;
        nextHandler->handleRequest(level);
    }
}

ExecutiveCommittee::ExecutiveCommittee() {}
//�ͷ�ָ��ռ�
ExecutiveCommittee::~ExecutiveCommittee()
{
     delete nextHandler;
}
//����������
void ExecutiveCommittee::handleRequest(int level)
{
    cout << "�����ѱ��ݽ���ִ��ίԱ�ᣬ���Ե�" << endl;
    if (level <= 2)//�ж�Ȩ��
    {
        cout << "�����ѱ�ִ��ίԱ�ᴦ��" << endl;
    }
    else//���������ƽ�����һ������
    {
        cout << "ִ��ίԱ����Ȩ�������ڵݽ�ȫ�����" << endl;
        nextHandler->handleRequest(level);
    }
}

PlenarySession::PlenarySession() {}
//�ͷ�ָ��ռ�
PlenarySession::~PlenarySession()
{
    delete nextHandler;
}

//����������
void PlenarySession::handleRequest(int level)
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


void testChainOfResponsibility()
{
    Handler* interimcommittee = new InterimCommittee;
    Handler* executivecommittee = new ExecutiveCommittee;
    Handler* plenarysession = new PlenarySession;

    
    interimcommittee->setNextHandler(executivecommittee);
    executivecommittee->setNextHandler(plenarysession);

    for (int i = 1; i < 5; i++)
    {
        cout << "һ����Ա����ί���������" << endl;
        interimcommittee->handleRequest(i);
        cout << endl;
    }
}