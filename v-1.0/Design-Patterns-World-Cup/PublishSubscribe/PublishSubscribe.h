#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"../utils/AbstractPointsRanking.h"
#include"../utils/PointsRanking.h"
#include"../utils/SingletonPointsRanking.h"
using namespace std;

class Publisher;
class Broker;
//订阅者(观众)的状态，得分榜更新前为sleepy，得分榜更新后为excited
enum class SubscriberAudienceState { sleepy = 0, excited = 1 };
enum class SubscribeType { numCountryFive = 0, numCountryTen = 1, CountryAsian = 2, CountryEU = 3 };

/*
 *  Subscriber: 订阅者抽象类
 *  当Publisher改变时，各个Subscriber会被notify并更新
 */
class Subscriber {
public:
	virtual ~Subscriber() {}
	virtual void update(Publisher* publisher) = 0;
	virtual void subscribe(Broker* broker, SubscribeType type) = 0;
};

/*
 *  SubscriberAudience: 订阅者具体类，这里对应的是观众
 *  其状态更新的结果是打印相应的信息
 */
class SubscriberAudience : public Subscriber {
public:
	SubscriberAudience(string name);//根据观众名字初始化
	void update(Publisher* s); // 得分榜信息改变，观众变兴奋
	void subscribe(Broker* broker, SubscribeType type); //用户订阅信息
	void timePassed(); //一段时间过去,观众变无聊
	void showSubscribe();  //打印观众订阅信息
	void showGetUpdate();  //打印接到订阅消息
private:
	string name; // 观众名字
	SubscriberAudienceState state;
	SubscribeType type;  //订阅种类
};


/*
 *  Publisher: 被订阅者，它存有所有其订阅者的信息，可在状态改变时通知各订阅者
 */
class Publisher {
public:
	virtual void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;//状态改变时，将会通知媒体
	virtual SingletonPointsRanking& getState() = 0;
};

/*
 *  ConcretePublisher: 这里对应的是得分榜，当得分榜改变时，各媒体会收到通知，并更新自身数据
 */
class ConcretePublisher :public Publisher {
public:
	ConcretePublisher(PointsRanking asian, PointsRanking EU, Broker* broker) :state(SingletonPointsRanking::Instance()), stateAsian(asian), stateEU(EU), broker(broker) {}
	void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);
	SingletonPointsRanking& getState();//获取当前状态，直接返回自身存储的得分榜实例
private:
	SingletonPointsRanking& state; //得分榜状态
	PointsRanking& stateAsian; //得分榜状态
	PointsRanking& stateEU; //得分榜状态
	Broker* broker;  //发送给频道
};

/*
 *  Broker: 代理方，负责对消息进行处理，转发送到符合要求的订阅者
 */
class Broker {
public:
	virtual void recieve(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;  //接受发布者消息
	virtual void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;  //状态改变时，将会通知各订阅者
	void attachFive(SubscriberAudience* subscriber); //添加前5名订阅者
	void attachTen(SubscriberAudience* subscriber); //添加前10名订阅者
	void attachAsian(SubscriberAudience* subscriber); //添加亚洲榜订阅者
	void attachEU(SubscriberAudience* subscriber); //添加欧洲榜订阅者

protected:
	vector<SubscriberAudience*> subscribersFive;// 记录所有的订阅者
	vector<SubscriberAudience*> subscribersTen;// 记录所有的订阅者
	vector<SubscriberAudience*> subscribersAsian;// 记录所有的订阅者
	vector<SubscriberAudience*> subscribersEU;// 记录所有的订阅者
};

/*
 *  Broker: 代理方，负责对消息进行处理，转发送到符合要求的订阅者
 */
class ConcreteChannel :public Broker{
public:
	void recieve(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);  //接受发布者消息
	void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);  //状态改变时，将会通知各订阅者
};

void testPublishSubscribe();//测试函数