#include"PublishSubscribe.h"

void SubscriberAudience::subscribe(Broker* broker, SubscribeType type) {
	this->type = type;
	if (this->type == SubscribeType::numCountryFive) {
		cout << "订阅者(观众) " << this->name << " 订阅了前五名国家的积分排名情况.\n";
		broker->attachFive(this);
	}
	else if (this->type == SubscribeType::numCountryTen) {
		cout << "订阅者(观众) " << this->name << " 订阅了前十名国家的积分排名情况.\n";
		broker->attachTen(this);
	}
	else if (this->type == SubscribeType::CountryAsian) {
		cout << "订阅者(观众) " << this->name << " 订阅了亚洲国家的积分排名情况.\n";
		broker->attachAsian(this);
	}
	else
	{
		cout << "订阅者(观众) " << this->name << " 订阅了欧洲国家的积分排名情况.\n";
		broker->attachEU(this);
	}
}

void SubscriberAudience::showGetUpdate() {
	cout << "订阅者(观众)" << this->name << "接收到订阅消息!" << endl;
	if (this->type == SubscribeType::numCountryFive)
		cout << "前五名国家的积分排名情况发生变化.\n";
	else if (this->type == SubscribeType::numCountryTen)
		cout << "前十名国家的积分排名情况发生变化.\n";
	else if (this->type == SubscribeType::CountryAsian)
		cout << "亚洲国家的积分排名情况发生变化.\n";
	else
		cout << "欧洲国家的积分排名情况发生变化.\n";
}

SubscriberAudience::SubscriberAudience(string name) :state(SubscriberAudienceState::sleepy) {
	this->name = name;
}

void SubscriberAudience::update(Publisher* s) {
	this->state = SubscriberAudienceState::excited;
}

void SubscriberAudience::timePassed() {
	this->state = SubscriberAudienceState::sleepy;
}

void SubscriberAudience::showSubscribe() {
	if (this->type == SubscribeType::numCountryFive) {
		cout << "订阅者(观众) " << this->name << " 订阅了前五名国家的积分排名情况.\n";
	}
	else if (this->type == SubscribeType::numCountryTen) {
		cout << "订阅者(观众) " << this->name << " 订阅了前十名国家的积分排名情况.\n";
	}
	else if (this->type == SubscribeType::CountryAsian) {
		cout << "订阅者(观众) " << this->name << " 订阅了亚洲国家的积分排名情况.\n";
	}
	else
		cout << "订阅者(观众) " << this->name << " 订阅了欧洲国家的积分排名情况.\n";
}

void ConcretePublisher::notify(bool ifFive, bool ifTen, bool ifAsian, bool ifEU) {
	this->broker->recieve(ifFive, ifTen, ifAsian, ifEU);
}

void Broker::attachAsian(SubscriberAudience* subscriber) {
	subscribersAsian.push_back(subscriber);
}

void Broker::attachEU(SubscriberAudience* subscriber) {
	subscribersEU.push_back(subscriber);
}

void Broker::attachFive(SubscriberAudience* subscriber) {
	subscribersFive.push_back(subscriber);
}

void Broker::attachTen(SubscriberAudience* subscriber) {
	subscribersTen.push_back(subscriber);
}

void ConcreteChannel::notify(bool ifFive, bool ifTen, bool ifAsian, bool ifEU) {
	if (ifFive)
		for (auto subscriber : subscribersFive)
			subscriber->showGetUpdate();
	if (ifTen)
		for (auto subscriber : subscribersTen)
			subscriber->showGetUpdate();
	if (ifAsian)
		for (auto subscriber : subscribersAsian)
			subscriber->showGetUpdate();
	if (ifEU)
		for (auto subscriber : subscribersEU)
			subscriber->showGetUpdate();
}

void ConcreteChannel::recieve(bool ifFive, bool ifTen, bool ifAsian, bool ifEU) {
	notify(ifFive, ifTen, ifAsian, ifEU);
}

SingletonPointsRanking& ConcretePublisher::getState() {
	return state;
}

void testPublishSubscribe()
{
	//积分榜状态
	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();

	PointsRanking& AsianPointsStatus = *(new PointsRanking);
	AsianPointsStatus.addCountry("中国", 38);
	AsianPointsStatus.addCountry("日本", 15);
	AsianPointsStatus.addCountry("韩国", 12);
	AsianPointsStatus.addCountry("一个国家", 25);
	PointsRanking& EUPointsStatus = *(new PointsRanking);
	EUPointsStatus.addCountry("法国", 29);
	EUPointsStatus.addCountry("英格兰", 28);
	EUPointsStatus.addCountry("葡萄牙", 24);
	EUPointsStatus.addCountry("克罗地亚", 17);
	EUPointsStatus.addCountry("摩洛哥", 16);

	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();

	//2个订阅者
	SubscriberAudience audience1("中国球迷A");
	SubscriberAudience audience2("荷兰球迷B");

	SubscriberAudience audience3("某国球迷C");
	SubscriberAudience audience4("另一国球迷D");

	//添加订阅者至Channel并显示状态
	ConcreteChannel* broker = new ConcreteChannel();
	Publisher* publisher = new ConcretePublisher(AsianPointsStatus, EUPointsStatus, broker);

	audience1.subscribe(broker, SubscribeType::CountryAsian);
	audience2.subscribe(broker, SubscribeType::CountryEU);
	audience3.subscribe(broker, SubscribeType::numCountryFive);
	audience4.subscribe(broker, SubscribeType::numCountryTen);

	cout << "订阅者的原始状态如下: \n";
	audience1.showSubscribe();
	audience2.showSubscribe();
	audience3.showSubscribe();
	audience4.showSubscribe();

	//改变publisher状态
	singletonPointsStatus.setCountryPoints("日本", 18);
	AsianPointsStatus.setCountryPoints("日本", 18);
	cout << "主办方发布比赛新动态 :" << endl;
	cout << "当前各榜单排名情况" << endl;
	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();
	publisher->notify(0, 1, 1, 0);

	singletonPointsStatus.setCountryPoints("中国", 40);
	AsianPointsStatus.setCountryPoints("中国", 40);
	cout << "主办方发布比赛新动态 :" << endl;
	cout << "当前各榜单排名情况" << endl;
	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();
	publisher->notify(1, 1, 1, 0);

	delete publisher;
}