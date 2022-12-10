#include <iostream>
#include "Bridge.h"


//效力俱乐部的具体实现类
void PSGClub::setattribute()
{
    activeServiceClub = "Paris Saint Germain...";
}

void MUClub::setattribute()
{
    activeServiceClub = "Manchester United...";
}

//参加世界杯是否多于两次的具体实现类
void LessThanTwiceParticipate::setattribute()
{
    participateNumBefore = "少于两次...";
}

void MoreThanTwiceParticipate::setattribute()
{
    participateNumBefore = "多于两次...";
}

//金球奖获得情况的具体实现类
void HaveWon::setattribute()
{
    GBA = "得过金球奖...";
}

void NeverWon::setattribute()
{
    GBA = "没有得过金球奖...";
}

//通过具体实现类设置属性
void Messi::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void Messi::print()
{
    cout << "我是Messi." << endl;
    cout << "我现在效力于" << implementor1->activeServiceClub << "." << endl;
    cout << "我参加世界杯" << implementor3->participateNumBefore << "." << endl;
    cout << "我" << implementor2->GBA << "." << endl;
}

//通过具体实现类设置属性
void CR7::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void CR7::print()
{
    cout << "我是C罗." << endl;
    cout << "我现在效力于" << implementor1->activeServiceClub << "." << endl;
    cout << "我参加世界杯" << implementor3->participateNumBefore << "." << endl;
    cout << "我" << implementor2->GBA << "." << endl;
}

//通过具体实现类设置属性
void Neymar::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void Neymar::print()
{
    cout << "我是Neymar." << endl;
    cout << "我现在效力于" << implementor1->activeServiceClub << "." << endl;
    cout << "我参加世界杯" << implementor3->participateNumBefore << "." << endl;
    cout << "我" << implementor2->GBA << "." << endl;
}


int testBridge()
{
    Implementor* PSG = new PSGClub;
    Implementor* MU = new MUClub;
    Implementor* lessTwice = new LessThanTwiceParticipate;
    Implementor* moreTwice = new MoreThanTwiceParticipate;
    Implementor* haveGBA = new HaveWon;
    Implementor* noGBA = new NeverWon;

    Role* Messi2022 = new Messi(PSG, haveGBA, moreTwice);
    Messi2022->setattribute();
    Messi2022->print();
    cout << endl;


    Role* CR2022 = new CR7(MU, haveGBA, moreTwice);
    CR2022->setattribute();
    CR2022->print();
    cout << endl;


    Role* Neymar2022 = new Neymar(PSG, noGBA, lessTwice);
    Neymar2022->setattribute();
    Neymar2022->print();
    cout << endl;

    delete Messi2022;
    delete CR2022;
    delete Neymar2022;

    delete PSG;
    delete MU;
    delete lessTwice;
    delete moreTwice;
    delete haveGBA;
    delete noGBA;

    cout << endl;

    return 0;
}