#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"../utils/AbstractPointsRanking.h"
#include"../utils/PointsRanking.h"
#include"../utils/SingletonPointsRanking.h"
using namespace std;

class Subject;

/*
 *  Observer: 观察者抽象类
 *  当Subject改变时，各个Observer会被notify并更新
 */
class Observer {
public:
	virtual ~Observer() {}
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
	virtual void showLeave() = 0;
};

/*
 *  ObserverAudience: 观察者具体类，这里对应的是媒体
 *  媒体的状态就是积分榜的信息，当积分榜改变时，各家媒体
 */
class ObserverMedia : public Observer {
public:
	ObserverMedia(string name, PointsRanking const state);//根据媒体名字与当前积分榜信息初始化
	~ObserverMedia();
	PointsRanking getState(); // 获取媒体状态，即积分榜信息
	void update(Subject* subject); // 积分榜信息改变，更新媒体的积分榜信息
	void showState(); // 打印媒体状态，以新闻播报形式呈现
	void showLeave(); //打印观察者停止观察信息
private:
	PointsRanking state; // 积分榜信息
	string name; // 媒体名称
};


//观察者(观众)的状态，积分榜更新前为sleepy，积分榜更新后为excited
enum class ObserverAudienceState { sleepy = 0, excited = 1 };

/*
 *  ObserverAudience: 观察者具体类，这里对应的是观众
 *  其状态更新的结果是打印相应的信息
 */
class ObserverAudience : public Observer {
public:
	ObserverAudience(string name);//根据观众名字初始化
	void update(Subject* s); // 积分榜信息改变，观众变兴奋
	void timePassed(); //一段时间过去,观众变无聊
	void showState();// 打印当前状态信息
	void showLeave(); //打印观察者停止观察信息
private:
	string name; // 观众名字
	ObserverAudienceState state;
};


/*
 *  Subject: 被观察者，它存有所有其观察者的信息，可在状态改变时通知各观察者
 */
class Subject {
public:
	void attach(Observer* observer); //添加观察者
	void detach(const int index); //根据序号删除某观察者
	void notify();//状态改变时，将会通知各观察者
	virtual SingletonPointsRanking& getState() = 0;
private:
	vector<Observer*> observers;// 记录所有的观察者
};


/*
 *  ConcreteSubject: 这里对应的是积分榜，当积分榜改变时，各家媒体会收到通知，并更新自身数据
 */
class ConcreteSubject :public Subject {
public:
	ConcreteSubject() :state(SingletonPointsRanking::Instance()) {}
	SingletonPointsRanking& getState();//获取当前状态，直接返回自身存储的积分榜实例
private:
	SingletonPointsRanking& state; //积分榜状态
};

void testObserver();//测试函数