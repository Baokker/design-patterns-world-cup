#include "Memento.h"


Memento::Memento(const PointsRanking& m) {
	this->PointsState = m;
}

PointsRanking Memento::getState() {
	return this->PointsState;
}

void Originator::setState(PointsRanking m) {
	this->state = m;
	cout << "积分排名信息正在更新.......\n";
}

void Originator::setState(Memento* m) {
	this->state = m->getState();
	cout << "积分排名信息正在更新.......\n";
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
	cout << "保存当前状态......\n";
	history.push_back(originator->createMemento());
}

void CareTaker::undo() {
	if (!history.empty()) {
		Memento* m = history.back();
		originator->setState(m);
		cout << "重做 (undo) 状态变化......\n";
	}
}

void CareTaker::showState() {
	cout << "当前状态......\n";
	originator->showState();
}

void testMemento() {
	Originator* originator = new Originator();
	CareTaker* careTaker = new CareTaker(originator);

	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();
	originator->setState(singletonPointsStatus);//当前积分榜
	careTaker->showState();//显示当前积分榜
	careTaker->save();//当前状态存档

	singletonPointsStatus.setCountryPoints("一个国家", 26);
	originator->setState(singletonPointsStatus);//当前积分榜
	careTaker->showState();//显示当前积分榜

	cout << "经半自动越位识别技术判定,认为上一粒进球越位，得分无效.\n";
	careTaker->undo();//退回之前状态
	careTaker->showState();
}