#include <iostream>
#include <string>
#include "Builder.h"

using namespace std;

//比赛对象的基本修改信息函数
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
    return ("\n时间：" + time + "\n场馆：" + place + "\n裁判组：" + jury);
}


//创建比赛的抽象接口
//获取比赛
Game GameBuilder::get()
{
    return game;
}


//击剑比赛创建者，继承自抽象比赛建造者
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


//跆拳道比赛创建者，继承自抽象比赛建造者
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

//导演类，指导具体比赛的建造
Director::~Director()
{
    if (builder)
    {
        delete builder;
    }
}

void Director::set(GameBuilder* b)
{
    //生成新的builder
    if (builder)
    {
        delete builder;
    }
    builder = b;
}

//返回比赛
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

//测试函数
//创建阿根廷vs葡萄牙，摩洛哥vs西班牙比赛
int testBuilder()
{
    Director director;
    director.set(new AvPGameBuilder);
    director.construct();

std:cout << "今晚的两场比赛将是：\n";

    Game game1 = director.get();
    std::cout << "1st Game: " << game1.get() << std::endl << std::endl;

    director.set(new MvSGameBuilder);
    director.construct();

    Game game2 = director.get();
    cout << "2nd Game: " << game2.get() << endl << std::endl;

    cout << endl;

    return 0;
}