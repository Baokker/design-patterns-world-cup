#pragma once
#include <iostream>
#include <string>

using namespace std;

//����������Ϣ��
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

//���������ĳ���ӿ�
class GameBuilder
{
protected:
    Game game;
public:
    //��������
    virtual ~GameBuilder() {}

    //��ȡ����
    Game get();

    //�麯��
    virtual void buildTime() = 0;
    virtual void buildPlace() = 0;
    virtual void buildJury() = 0;

};

//����͢vs���������������ߣ��̳��Գ������������
class AvPGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildJury();
};


//Ħ���vs���������������ߣ��̳��Գ������������
class MvSGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildJury();
};

//�����ָ࣬����������Ľ���
class Director {
private:
    GameBuilder* builder;
public:
    Director() : builder() {}

    ~Director();

    void set(GameBuilder* b);

    //���ر���
    Game get();

    void construct();
};

//���Ժ���
//��������͢vs��������Ħ���vs����������
int testBuilder();
