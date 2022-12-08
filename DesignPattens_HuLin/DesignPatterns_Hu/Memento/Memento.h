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
 *  Memento: ��¼��Originatorʵ����state����ֻ�ܱ�Originator�����
 *  �����state����һ�����ְ�PointsRankingʵ��
 */
class Memento {
private:
	friend class Originator;
	Memento(const PointsRanking& m); //���ݻ��ְ�ʵ������Memento����
	PointsRanking getState(); // ��ȡ��ǰ״̬
	PointsRanking PointsState; // ״̬(state)��Ϣ����һ�����ְ�ʵ��
};


/*
 *  Originator: ΪĳЩ��Ϣ��������¼��ÿһ������¼��״̬����¼��һ��Menmentoʵ����
 *  �����OrignatorΪ���ְ���Ϣ��������¼
 */
class Originator {
public:
	void setState(PointsRanking m); //���ݻ��ְ���ʵ��ֱ������state
	void setState(Memento* m); //����Menmento�д�ŵĻ��ְ���Ϣ����state
	void showState(); //��ӡ��ǰ״̬
	PointsRanking getState(); //��ȡ��ǰ״̬
	Memento* createMemento(); //���ݵ�ǰ״̬����һ���µ�Memento��ʵ����������ָ��
private:
	PointsRanking state; // ״̬��������һ�����ְ�ʵ��
};


/*
 *  CareTaker: ����Ӧһ��Originator����Originator������ÿһ��״̬��Ӧ��Memento�����¼������
 *	���ݳ�Աhistory(Vector<Memento*>)��; CareTaker���ڱ��桢�ָ���ʷ��Ϣ
 */
class CareTaker {
public:
	CareTaker(Originator* const o); //���캯���д���Originatorָ���Գ�ʼ�����Ӧ��Ա
	~CareTaker();
	void save();//���浱ǰ״̬
	void undo();//�ָ�Ϊ��һ��״̬
	void showState(); //��ӡ��ǰ״̬
private:
	Originator* originator;
	vector<Memento*> history; //���������ڼ�¼����ʷ״̬
};

void testMemento();//���Ժ���