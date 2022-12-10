#pragma once
#include<iostream>
#include<string>

using namespace std;


#define PLAYER_NUM 3

//����һ��������NullObjectAbstractPlayer��
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

//������չ�˳�����AbstractPlayer��ʵ����RealPlayer��
class NullObjectRealPlayer :NullObjectAbstractPlayer
{
public:
	NullObjectRealPlayer(string inInfo) { info = inInfo; };
	~NullObjectRealPlayer() {};
	bool isnull() { return false; };
	string getInfo() { return info; };
};

//������չ�˳�����NullObjectAbstractPlayer�Ŀ���NullObjectNullPlayer��
class NullObjectNullPlayer :NullObjectAbstractPlayer
{
public:
	NullObjectNullPlayer() {};
	~NullObjectNullPlayer() {};
	bool isnull() { return true; };
	string getInfo() { return "û�и���Ա��Ϣ���볢�Ը���"; };
};

//����NullObjectPlayerFactory�࣬������ȡʵ���������ʵ��
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
