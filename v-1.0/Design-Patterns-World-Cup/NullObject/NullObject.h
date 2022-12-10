#pragma once
#include<iostream>
#include<string>

using namespace std;


#define PLAYER_NUM 3

//创建一个抽象类NullObjectAbstractPlayer。
class NullObjectAbstractPlayer
{
public:
	NullObjectAbstractPlayer() {};
	virtual ~NullObjectAbstractPlayer() {};
	virtual bool isnull() = 0;
	virtual string getInfo() = 0;

protected:
	string info;
};

//创建扩展了抽象类AbstractPlayer的实体类RealPlayer。
class NullObjectRealPlayer :NullObjectAbstractPlayer
{
public:
	NullObjectRealPlayer(string inInfo) { info = inInfo; };
	~NullObjectRealPlayer() {};
	bool isnull() { return false; };
	string getInfo() { return info; };
};

//创建扩展了抽象类NullObjectAbstractPlayer的空类NullObjectNullPlayer。
class NullObjectNullPlayer :NullObjectAbstractPlayer
{
public:
	NullObjectNullPlayer() {};
	~NullObjectNullPlayer() {};
	bool isnull() { return true; };
	string getInfo() { return "没有该球员信息，请尝试更换"; };
};

//创建NullObjectPlayerFactory类，用来获取实体类或空类的实例
class NullObjectPlayerFactory
{
public:
	NullObjectPlayerFactory() {};
	~NullObjectPlayerFactory() {};
	static string name[PLAYER_NUM];
	static string info[PLAYER_NUM];
	static NullObjectAbstractPlayer* getPlayer(string inName);
};




void testNullObject();
