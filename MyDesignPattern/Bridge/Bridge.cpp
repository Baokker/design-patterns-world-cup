#include <iostream>
#include "Bridge.h"


//Ч�����ֲ��ľ���ʵ����
void PSGClub::setattribute()
{
    activeServiceClub = "Paris Saint Germain...";
}

void MUClub::setattribute()
{
    activeServiceClub = "Manchester United...";
}

//�μ����籭�Ƿ�������εľ���ʵ����
void LessThanTwiceParticipate::setattribute()
{
    participateNumBefore = "��������...";
}

void MoreThanTwiceParticipate::setattribute()
{
    participateNumBefore = "��������...";
}

//���򽱻������ľ���ʵ����
void HaveWon::setattribute()
{
    GBA = "�ù�����...";
}

void NeverWon::setattribute()
{
    GBA = "û�еù�����...";
}

//ͨ������ʵ������������
void Messi::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void Messi::print()
{
    cout << "����Messi." << endl;
    cout << "������Ч����" << implementor1->activeServiceClub << "." << endl;
    cout << "�Ҳμ����籭" << implementor3->participateNumBefore << "." << endl;
    cout << "��" << implementor2->GBA << "." << endl;
}

//ͨ������ʵ������������
void CR7::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void CR7::print()
{
    cout << "����C��." << endl;
    cout << "������Ч����" << implementor1->activeServiceClub << "." << endl;
    cout << "�Ҳμ����籭" << implementor3->participateNumBefore << "." << endl;
    cout << "��" << implementor2->GBA << "." << endl;
}

//ͨ������ʵ������������
void Neymar::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void Neymar::print()
{
    cout << "����Neymar." << endl;
    cout << "������Ч����" << implementor1->activeServiceClub << "." << endl;
    cout << "�Ҳμ����籭" << implementor3->participateNumBefore << "." << endl;
    cout << "��" << implementor2->GBA << "." << endl;
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