#pragma once
#include <iostream>
#include <string>

using namespace std;

//球赛对象信息类
class Game
{
private:
    string time;
    string place;
    string jury;

public:
    void setTime(const std::string& part);
    void setPlace(const std::string& part);
    void setJury(const std::string& part);
    string get();

};

//创建比赛的抽象接口
class GameBuilder
{
protected:
    Game game;
public:
    //析构函数
    virtual ~GameBuilder() {}

    //获取比赛
    Game get();

    //虚函数
    virtual void buildTime() = 0;
    virtual void buildPlace() = 0;
    virtual void buildJury() = 0;

};

//阿根廷vs葡萄牙比赛创建者，继承自抽象比赛建造者
class AvPGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildJury();
};


//摩洛哥vs西班牙比赛创建者，继承自抽象比赛建造者
class MvSGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildJury();
};

//导演类，指导具体比赛的建造
class Director {
private:
    GameBuilder* builder;
public:
    Director() : builder() {}

    ~Director();

    void set(GameBuilder* b);

    //返回比赛
    Game get();

    void construct();
};

//测试函数
//创建阿根廷vs葡萄牙，摩洛哥vs西班牙比赛
int testBuilder();
