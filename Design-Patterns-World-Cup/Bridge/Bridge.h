#pragma once
#include <iostream>

using namespace std;

//��Ϊ�Žӽӿڵ�ʵ����
class Implementor
{
public:
    virtual ~Implementor() {}

    string activeServiceClub; //���۾��ֲ�
    string GBA;               //�������
    string participateNumBefore; //�������籭����

    virtual void setattribute() = 0;
};

//���۾��ֲ��ľ���ʵ����
class PSGClub : public Implementor
{
    //����ʥ�ն���
public:
    ~PSGClub() {}
    void setattribute();
};

class MUClub : public Implementor
{
    //����
public:
    ~MUClub() {}
    void setattribute();
};

//�μ����籭�����ľ���ʵ����
class LessThanTwiceParticipate : public Implementor
{
public:
    ~LessThanTwiceParticipate() {}
    void setattribute();
};

class MoreThanTwiceParticipate : public Implementor
{
public:
    ~MoreThanTwiceParticipate() {}
    void setattribute();
};

//���򽱻������ľ���ʵ����
class HaveWon : public Implementor
{
public:
    ~HaveWon() {}
    void setattribute();
};

class NeverWon : public Implementor
{
public:
    ~NeverWon() {}
    void setattribute();
};


//��Ա������
class Role
{
public:
    Implementor* implementor1;
    Implementor* implementor2;
    Implementor* implementor3;

    Role(Implementor* impl, Implementor* imp2, Implementor* imp3) : implementor1(impl), implementor2(imp2), implementor3(imp3) {}

    virtual ~Role() {}

    virtual void setattribute() = 0;
    virtual void print() = 0;
};

//��չ������Ľӿڣ�ѡ��÷����C�ޣ��������Ϊ��ͬ��ɫ
class Messi : public Role
{
public:
    ~Messi() {}

    Messi(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();

};

class CR7 : public Role
{
public:
    ~CR7() {}

    CR7(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();

};

class Neymar : public Role
{
public:
    ~Neymar() {};
    Neymar(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();
};

int testBridge();