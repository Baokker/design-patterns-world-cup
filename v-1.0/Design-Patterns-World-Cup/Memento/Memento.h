#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include"../utils/AbstractPointsRanking.h"
#include"../utils/PointsRanking.h"
#include"../utils/SingletonPointsRanking.h"
using namespace std;

/*
 *  Memento: 记录了Originator实例的state，且只能被Originator类访问
 *  这里的state就是一个积分榜PointsRanking实例
 */
class Memento {
private:
	friend class Originator;
	Memento(const PointsRanking& m); //根据积分榜实例创建Memento对象
	PointsRanking getState(); // 获取当前状态
	PointsRanking PointsState; // 状态(state)信息，是一个积分榜实例
};


/*
 *  Originator: 为某些信息建立备忘录，每一个待记录的状态都记录在一个Menmento实例中
 *  这里的Orignator为积分榜信息建立备忘录
 */
class Originator {
public:
	void setState(PointsRanking m); //根据积分榜类实例直接设置state
	void setState(Memento* m); //根据Menmento中存放的积分榜信息设置state
	void showState(); //打印当前状态
	PointsRanking getState(); //获取当前状态
	Memento* createMemento(); //根据当前状态建立一个新的Memento类实例并返回其指针
private:
	PointsRanking state; // 状态，这里是一个积分榜实例
};


/*
 *  CareTaker: 它对应一个Originator，此Originator创建的每一个状态对应的Memento都会记录在它的
 *	数据成员history(Vector<Memento*>)中; CareTaker用于保存、恢复历史信息
 */
class CareTaker {
public:
	CareTaker(Originator* const o); //构造函数中传入Originator指针以初始化其对应成员
	~CareTaker();
	void save();//保存当前状态
	void undo();//恢复为上一个状态
	void showState(); //打印当前状态
private:
	Originator* originator;
	vector<Memento*> history; //此数组用于记录各历史状态
};

void testMemento();//测试函数