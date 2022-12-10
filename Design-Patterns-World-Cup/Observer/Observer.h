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
 *  Observer: �۲��߳�����
 *  ��Subject�ı�ʱ������Observer�ᱻnotify������
 */
class Observer {
public:
	virtual ~Observer() {}
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
	virtual void showLeave() = 0;
};

/*
 *  ObserverAudience: �۲��߾����࣬�����Ӧ����ý��
 *  ý���״̬���ǻ��ְ����Ϣ�������ְ�ı�ʱ������ý��
 */
class ObserverMedia : public Observer {
public:
	ObserverMedia(string name, PointsRanking const state);//����ý�������뵱ǰ���ְ���Ϣ��ʼ��
	~ObserverMedia();
	PointsRanking getState(); // ��ȡý��״̬�������ְ���Ϣ
	void update(Subject* subject); // ���ְ���Ϣ�ı䣬����ý��Ļ��ְ���Ϣ
	void showState(); // ��ӡý��״̬�������Ų�����ʽ����
	void showLeave(); //��ӡ�۲���ֹͣ�۲���Ϣ
private:
	PointsRanking state; // ���ְ���Ϣ
	string name; // ý������
};


//�۲���(����)��״̬�����ְ����ǰΪsleepy�����ְ���º�Ϊexcited
enum class ObserverAudienceState { sleepy = 0, excited = 1 };

/*
 *  ObserverAudience: �۲��߾����࣬�����Ӧ���ǹ���
 *  ��״̬���µĽ���Ǵ�ӡ��Ӧ����Ϣ
 */
class ObserverAudience : public Observer {
public:
	ObserverAudience(string name);//���ݹ������ֳ�ʼ��
	void update(Subject* s); // ���ְ���Ϣ�ı䣬���ڱ��˷�
	void timePassed(); //һ��ʱ���ȥ,���ڱ�����
	void showState();// ��ӡ��ǰ״̬��Ϣ
	void showLeave(); //��ӡ�۲���ֹͣ�۲���Ϣ
private:
	string name; // ��������
	ObserverAudienceState state;
};


/*
 *  Subject: ���۲��ߣ�������������۲��ߵ���Ϣ������״̬�ı�ʱ֪ͨ���۲���
 */
class Subject {
public:
	void attach(Observer* observer); //��ӹ۲���
	void detach(const int index); //�������ɾ��ĳ�۲���
	void notify();//״̬�ı�ʱ������֪ͨ���۲���
	virtual SingletonPointsRanking& getState() = 0;
private:
	vector<Observer*> observers;// ��¼���еĹ۲���
};


/*
 *  ConcreteSubject: �����Ӧ���ǻ��ְ񣬵����ְ�ı�ʱ������ý����յ�֪ͨ����������������
 */
class ConcreteSubject :public Subject {
public:
	ConcreteSubject() :state(SingletonPointsRanking::Instance()) {}
	SingletonPointsRanking& getState();//��ȡ��ǰ״̬��ֱ�ӷ�������洢�Ļ��ְ�ʵ��
private:
	SingletonPointsRanking& state; //���ְ�״̬
};

void testObserver();//���Ժ���