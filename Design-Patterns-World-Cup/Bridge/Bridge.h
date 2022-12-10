#pragma once
#include <iostream>

using namespace std;

//作为桥接接口的实现类
class Implementor
{
public:
    virtual ~Implementor() {}

    string activeServiceClub; //现役俱乐部
    string GBA;               //金球奖情况
    string participateNumBefore; //参与世界杯次数

    virtual void setattribute() = 0;
};

//现役俱乐部的具体实现类
class PSGClub : public Implementor
{
    //巴黎圣日耳曼
public:
    ~PSGClub() {}
    void setattribute();
};

class MUClub : public Implementor
{
    //曼联
public:
    ~MUClub() {}
    void setattribute();
};

//参加世界杯次数的具体实现类
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

//金球奖获得情况的具体实现类
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


//球员抽象类
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

//扩展抽象类的接口，选择梅西，C罗，内马尔作为不同角色
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