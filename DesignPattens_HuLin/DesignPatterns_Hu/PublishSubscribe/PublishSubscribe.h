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
//������(����)��״̬���÷ְ����ǰΪsleepy���÷ְ���º�Ϊexcited
enum class SubscriberAudienceState { sleepy = 0, excited = 1 };
enum class SubscribeType { numCountryFive = 0, numCountryTen = 1, CountryAsian = 2, CountryEU = 3 };

/*
 *  Subscriber: �����߳�����
 *  ��Publisher�ı�ʱ������Subscriber�ᱻnotify������
 */
class Subscriber {
public:
	virtual ~Subscriber() {}
	virtual void update(Publisher* publisher) = 0;
	virtual void subscribe(Broker* broker, SubscribeType type) = 0;
};

/*
 *  SubscriberAudience: �����߾����࣬�����Ӧ���ǹ���
 *  ��״̬���µĽ���Ǵ�ӡ��Ӧ����Ϣ
 */
class SubscriberAudience : public Subscriber {
public:
	SubscriberAudience(string name);//���ݹ������ֳ�ʼ��
	void update(Publisher* s); // �÷ְ���Ϣ�ı䣬���ڱ��˷�
	void subscribe(Broker* broker, SubscribeType type); //�û�������Ϣ
	void timePassed(); //һ��ʱ���ȥ,���ڱ�����
	void showSubscribe();  //��ӡ���ڶ�����Ϣ
	void showGetUpdate();  //��ӡ�ӵ�������Ϣ
private:
	string name; // ��������
	SubscriberAudienceState state;
	SubscribeType type;  //��������
};


/*
 *  Publisher: �������ߣ������������䶩���ߵ���Ϣ������״̬�ı�ʱ֪ͨ��������
 */
class Publisher {
public:
	virtual void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;//״̬�ı�ʱ������֪ͨý��
	virtual SingletonPointsRanking& getState() = 0;
};

/*
 *  ConcretePublisher: �����Ӧ���ǵ÷ְ񣬵��÷ְ�ı�ʱ����ý����յ�֪ͨ����������������
 */
class ConcretePublisher :public Publisher {
public:
	ConcretePublisher(PointsRanking asian, PointsRanking EU, Broker* broker) :state(SingletonPointsRanking::Instance()), stateAsian(asian), stateEU(EU), broker(broker) {}
	void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);
	SingletonPointsRanking& getState();//��ȡ��ǰ״̬��ֱ�ӷ�������洢�ĵ÷ְ�ʵ��
private:
	SingletonPointsRanking& state; //�÷ְ�״̬
	PointsRanking& stateAsian; //�÷ְ�״̬
	PointsRanking& stateEU; //�÷ְ�״̬
	Broker* broker;  //���͸�Ƶ��
};

/*
 *  Broker: �������������Ϣ���д���ת���͵�����Ҫ��Ķ�����
 */
class Broker {
public:
	virtual void recieve(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;  //���ܷ�������Ϣ
	virtual void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false) = 0;  //״̬�ı�ʱ������֪ͨ��������
	void attachFive(SubscriberAudience* subscriber); //���ǰ5��������
	void attachTen(SubscriberAudience* subscriber); //���ǰ10��������
	void attachAsian(SubscriberAudience* subscriber); //������ް�����
	void attachEU(SubscriberAudience* subscriber); //���ŷ�ް�����

protected:
	vector<SubscriberAudience*> subscribersFive;// ��¼���еĶ�����
	vector<SubscriberAudience*> subscribersTen;// ��¼���еĶ�����
	vector<SubscriberAudience*> subscribersAsian;// ��¼���еĶ�����
	vector<SubscriberAudience*> subscribersEU;// ��¼���еĶ�����
};

/*
 *  Broker: �������������Ϣ���д���ת���͵�����Ҫ��Ķ�����
 */
class ConcreteChannel :public Broker{
public:
	void recieve(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);  //���ܷ�������Ϣ
	void notify(bool ifFive = false, bool ifTen = false, bool ifAsian = false, bool ifEU = false);  //״̬�ı�ʱ������֪ͨ��������
};

void testPublishSubscribe();//���Ժ���