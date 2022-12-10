#include <iostream>
#include <string>
#include "Builder.h"

using namespace std;

//��������Ļ����޸���Ϣ����
void Game::setTime(const string& part)
{
    time = part;
}

void Game::setPlace(const string& part)
{
    place = part;
}

void Game::setJury(const string& part)
{
    jury = part;
}

string Game::get()
{
    return ("\nʱ�䣺" + time + "\n���ݣ�" + place + "\n�����飺" + jury);
}


//���������ĳ���ӿ�
//��ȡ����
Game GameBuilder::get()
{
    return game;
}


//�������������ߣ��̳��Գ������������
void AvPGameBuilder::buildTime()
{
    game.setTime("2:00 Beijing");
}
void AvPGameBuilder::buildPlace()
{
    game.setPlace("Qatar World Cup Stadium");
}
void AvPGameBuilder::buildJury()
{
    game.setJury("#100");
}


//��ȭ�����������ߣ��̳��Գ������������
void MvSGameBuilder::buildTime()
{
    game.setTime("4:00 Beijing");
}
void MvSGameBuilder::buildPlace()
{
    game.setPlace("Qatar World Cup Stadium");
}
void MvSGameBuilder::buildJury()
{
    game.setJury("#200");
}

//�����ָ࣬����������Ľ���
Director::~Director()
{
    if (builder)
    {
        delete builder;
    }
}

void Director::set(GameBuilder* b)
{
    //�����µ�builder
    if (builder)
    {
        delete builder;
    }
    builder = b;
}

//���ر���
Game Director::get()
{
    return builder->get();
}

void Director::construct()
{
    builder->buildTime();
    builder->buildPlace();
    builder->buildJury();
}

//���Ժ���
//��������͢vs��������Ħ���vs����������
int testBuilder()
{
    Director director;
    director.set(new AvPGameBuilder);
    director.construct();

std:cout << "����������������ǣ�\n";

    Game game1 = director.get();
    std::cout << "1st Game: " << game1.get() << std::endl << std::endl;

    director.set(new MvSGameBuilder);
    director.construct();

    Game game2 = director.get();
    cout << "2nd Game: " << game2.get() << endl << std::endl;

    cout << endl;

    return 0;
}