#include"PublishSubscribe.h"

void SubscriberAudience::subscribe(Broker* broker, SubscribeType type) {
	this->type = type;
	if (this->type == SubscribeType::numCountryFive) {
		cout << "������(����) " << this->name << " ������ǰ�������ҵĻ����������.\n";
		broker->attachFive(this);
	}
	else if (this->type == SubscribeType::numCountryTen) {
		cout << "������(����) " << this->name << " ������ǰʮ�����ҵĻ����������.\n";
		broker->attachTen(this);
	}
	else if (this->type == SubscribeType::CountryAsian) {
		cout << "������(����) " << this->name << " ���������޹��ҵĻ����������.\n";
		broker->attachAsian(this);
	}
	else
	{
		cout << "������(����) " << this->name << " ������ŷ�޹��ҵĻ����������.\n";
		broker->attachEU(this);
	}
}

void SubscriberAudience::showGetUpdate() {
	cout << "������(����)" << this->name << "���յ�������Ϣ!" << endl;
	if (this->type == SubscribeType::numCountryFive)
		cout << "ǰ�������ҵĻ���������������仯.\n";
	else if (this->type == SubscribeType::numCountryTen)
		cout << "ǰʮ�����ҵĻ���������������仯.\n";
	else if (this->type == SubscribeType::CountryAsian)
		cout << "���޹��ҵĻ���������������仯.\n";
	else
		cout << "ŷ�޹��ҵĻ���������������仯.\n";
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
		cout << "������(����) " << this->name << " ������ǰ�������ҵĻ����������.\n";
	}
	else if (this->type == SubscribeType::numCountryTen) {
		cout << "������(����) " << this->name << " ������ǰʮ�����ҵĻ����������.\n";
	}
	else if (this->type == SubscribeType::CountryAsian) {
		cout << "������(����) " << this->name << " ���������޹��ҵĻ����������.\n";
	}
	else
		cout << "������(����) " << this->name << " ������ŷ�޹��ҵĻ����������.\n";
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
	//���ְ�״̬
	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();

	PointsRanking& AsianPointsStatus = *(new PointsRanking);
	AsianPointsStatus.addCountry("�й�", 38);
	AsianPointsStatus.addCountry("�ձ�", 15);
	AsianPointsStatus.addCountry("����", 12);
	AsianPointsStatus.addCountry("һ������", 25);
	PointsRanking& EUPointsStatus = *(new PointsRanking);
	EUPointsStatus.addCountry("����", 29);
	EUPointsStatus.addCountry("Ӣ����", 28);
	EUPointsStatus.addCountry("������", 24);
	EUPointsStatus.addCountry("���޵���", 17);
	EUPointsStatus.addCountry("Ħ���", 16);

	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();

	//2��������
	SubscriberAudience audience1("�й�����A");
	SubscriberAudience audience2("��������B");

	SubscriberAudience audience3("ĳ������C");
	SubscriberAudience audience4("��һ������D");

	//��Ӷ�������Channel����ʾ״̬
	ConcreteChannel* broker = new ConcreteChannel();
	Publisher* publisher = new ConcretePublisher(AsianPointsStatus, EUPointsStatus, broker);

	audience1.subscribe(broker, SubscribeType::CountryAsian);
	audience2.subscribe(broker, SubscribeType::CountryEU);
	audience3.subscribe(broker, SubscribeType::numCountryFive);
	audience4.subscribe(broker, SubscribeType::numCountryTen);

	cout << "�����ߵ�ԭʼ״̬����: \n";
	audience1.showSubscribe();
	audience2.showSubscribe();
	audience3.showSubscribe();
	audience4.showSubscribe();

	//�ı�publisher״̬
	singletonPointsStatus.setCountryPoints("�ձ�", 18);
	AsianPointsStatus.setCountryPoints("�ձ�", 18);
	cout << "���췽���������¶�̬ :" << endl;
	cout << "��ǰ�����������" << endl;
	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();
	publisher->notify(0, 1, 1, 0);

	singletonPointsStatus.setCountryPoints("�й�", 40);
	AsianPointsStatus.setCountryPoints("�й�", 40);
	cout << "���췽���������¶�̬ :" << endl;
	cout << "��ǰ�����������" << endl;
	singletonPointsStatus.print();
	AsianPointsStatus.print();
	EUPointsStatus.print();
	publisher->notify(1, 1, 1, 0);

	delete publisher;
}