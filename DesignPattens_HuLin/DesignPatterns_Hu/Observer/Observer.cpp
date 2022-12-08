#include"Observer.h"

ObserverMedia::ObserverMedia(string name, PointsRanking const state) :
	name(name), state(state) {}

ObserverMedia::~ObserverMedia() {}

PointsRanking ObserverMedia::getState() {
	return state;
}

void ObserverMedia::update(Subject* subject) {

	this->state = subject->getState();
}

void ObserverMedia::showState() {
	cout << "观察者(媒体) " << this->name << " 声明:" << endl;
	cout << this->name << " 持续为您播报 : 以下是目前的积分排名信息.\n";
	this->state.print();
}

void ObserverMedia::showLeave() {
	cout << "观察者(媒体)" << this->name << "可能去上厕所去了，因此从观察者列表移除" << endl;
}

ObserverAudience::ObserverAudience(string name) :state(ObserverAudienceState::sleepy) {
	this->name = name;
}

void ObserverAudience::update(Subject* s) {
	this->state = ObserverAudienceState::excited;
}

void ObserverAudience::timePassed() {
	this->state = ObserverAudienceState::sleepy;
}

void ObserverAudience::showState() {
	if (this->state == ObserverAudienceState::sleepy) {
		cout << "观察者(观众) " << this->name << " 感到昏昏欲睡(因为积分排名已经很长时间没有变化了).\n";
	}
	else if (this->state == ObserverAudienceState::excited) {
		cout << "观察者(观众) " << this->name << " 感到十分兴奋!(因为积分排名信息刚刚发生更新).\n";
	}
}

void ObserverAudience::showLeave() {
	cout << "观察者(观众)" << this->name << "可能去上厕所去了，因此从观察者列表移除" << endl;
}

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::detach(const int index) {
	(*(observers.begin() + index))->showLeave();
	observers.erase(observers.begin() + index);
}

void Subject::notify() {
	cout << "比赛官方通知其他观察者...\n";
	for (auto observer : observers) {
		observer->update(this);
	}
}

SingletonPointsRanking& ConcreteSubject::getState() {
	return state;
}


void testObserver()
{
	//积分榜状态
	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();
	singletonPointsStatus.addCountry("中国", 38);
	singletonPointsStatus.addCountry("巴西", 39);
	singletonPointsStatus.addCountry("法国", 29);
	singletonPointsStatus.addCountry("英格兰", 28);
	singletonPointsStatus.addCountry("阿根廷", 27);
	singletonPointsStatus.addCountry("葡萄牙", 24);
	singletonPointsStatus.addCountry("克罗地亚", 17);
	singletonPointsStatus.addCountry("摩洛哥", 16);
	singletonPointsStatus.addCountry("日本", 15);
	singletonPointsStatus.addCountry("一个国家", 14);

	//4个观察者(2个媒体，2个观众)
	ObserverMedia media1("疼讯新闻", singletonPointsStatus);
	ObserverMedia media2("BBC News", singletonPointsStatus);
	ObserverAudience audience1("范志毅");
	ObserverAudience audience2("赵鹏");

	//添加观察者至subject并显示状态
	Subject* subject = new ConcreteSubject();
	subject->attach(&media1);
	subject->attach(&media2);
	subject->attach(&audience1);
	subject->attach(&audience2);
	cout << "观察者的原始状态如下: \n";
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	//改变subject状态
	singletonPointsStatus.setCountryPoints("一个国家", 21);
	cout << "比赛官方改变排名信息，并通知各观察者\n";
	subject->notify();

	//再次展示观察者状态
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	cout << endl << "一段时间过去了..." << endl;
	audience1.timePassed();
	audience2.timePassed();

	//移除部分观察者
	subject->detach(0);
	subject->detach(1);

	//再次展示观察者状态
	cout << "观察者此时状态如下: \n";
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	singletonPointsStatus.setCountryPoints("一个国家", 25);
	cout << "比赛官方改变排名信息，并通知各观察者\n";
	subject->notify();

	//再次展示观察者状态
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	delete subject;
}