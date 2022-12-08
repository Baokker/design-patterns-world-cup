#include "Memento.h"


Memento::Memento(const PointsRanking& m) {
	this->PointsState = m;
}

PointsRanking Memento::getState() {
	return this->PointsState;
}

void Originator::setState(PointsRanking m) {
	this->state = m;
	cout << "����������Ϣ���ڸ���.......\n";
}

void Originator::setState(Memento* m) {
	this->state = m->getState();
	cout << "����������Ϣ���ڸ���.......\n";
}

void Originator::showState() {
	state.print();
}

PointsRanking Originator::getState() {
	return state;
}

Memento* Originator::createMemento() {
	return new Memento(state);
}

CareTaker::CareTaker(Originator* const o) :
	originator(o) {}

CareTaker::~CareTaker() {
	for (auto eachHistory : history) {
		delete eachHistory;
	}
	history.clear();
}

void CareTaker::save() {
	cout << "���浱ǰ״̬......\n";
	history.push_back(originator->createMemento());
}

void CareTaker::undo() {
	if (!history.empty()) {
		Memento* m = history.back();
		originator->setState(m);
		cout << "���� (undo) ״̬�仯......\n";
	}
}

void CareTaker::showState() {
	cout << "��ǰ״̬......\n";
	originator->showState();
}

void testMemento() {
	Originator* originator = new Originator();
	CareTaker* careTaker = new CareTaker(originator);

	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();
	originator->setState(singletonPointsStatus);//��ǰ���ְ�
	careTaker->showState();//��ʾ��ǰ���ְ�
	careTaker->save();//��ǰ״̬�浵

	singletonPointsStatus.setCountryPoints("һ������", 26);
	originator->setState(singletonPointsStatus);//��ǰ���ְ�
	careTaker->showState();//��ʾ��ǰ���ְ�

	cout << "�����Զ�Խλʶ�����ж�,��Ϊ��һ������Խλ���÷���Ч.\n";
	careTaker->undo();//�˻�֮ǰ״̬
	careTaker->showState();
}