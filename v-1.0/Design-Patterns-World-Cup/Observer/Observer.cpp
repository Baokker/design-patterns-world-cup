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
	cout << "�۲���(ý��) " << this->name << " ����:" << endl;
	cout << this->name << " ����Ϊ������ : ������Ŀǰ�Ļ���������Ϣ.\n";
	this->state.print();
}

void ObserverMedia::showLeave() {
	cout << "�۲���(ý��)" << this->name << "����ȥ�ϲ���ȥ�ˣ���˴ӹ۲����б��Ƴ�" << endl;
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
		cout << "�۲���(����) " << this->name << " �е������˯(��Ϊ���������Ѿ��ܳ�ʱ��û�б仯��).\n";
	}
	else if (this->state == ObserverAudienceState::excited) {
		cout << "�۲���(����) " << this->name << " �е�ʮ���˷�!(��Ϊ����������Ϣ�ոշ�������).\n";
	}
}

void ObserverAudience::showLeave() {
	cout << "�۲���(����)" << this->name << "����ȥ�ϲ���ȥ�ˣ���˴ӹ۲����б��Ƴ�" << endl;
}

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::detach(const int index) {
	(*(observers.begin() + index))->showLeave();
	observers.erase(observers.begin() + index);
}

void Subject::notify() {
	cout << "�����ٷ�֪ͨ�����۲���...\n";
	for (auto observer : observers) {
		observer->update(this);
	}
}

SingletonPointsRanking& ConcreteSubject::getState() {
	return state;
}


void testObserver()
{
	//���ְ�״̬
	SingletonPointsRanking& singletonPointsStatus = SingletonPointsRanking::Instance();
	singletonPointsStatus.addCountry("�й�", 38);
	singletonPointsStatus.addCountry("����", 39);
	singletonPointsStatus.addCountry("����", 29);
	singletonPointsStatus.addCountry("Ӣ����", 28);
	singletonPointsStatus.addCountry("����͢", 27);
	singletonPointsStatus.addCountry("������", 24);
	singletonPointsStatus.addCountry("���޵���", 17);
	singletonPointsStatus.addCountry("Ħ���", 16);
	singletonPointsStatus.addCountry("�ձ�", 15);
	singletonPointsStatus.addCountry("һ������", 14);

	//4���۲���(2��ý�壬2������)
	ObserverMedia media1("��Ѷ����", singletonPointsStatus);
	ObserverMedia media2("BBC News", singletonPointsStatus);
	ObserverAudience audience1("��־��");
	ObserverAudience audience2("����");

	//��ӹ۲�����subject����ʾ״̬
	Subject* subject = new ConcreteSubject();
	subject->attach(&media1);
	subject->attach(&media2);
	subject->attach(&audience1);
	subject->attach(&audience2);
	cout << "�۲��ߵ�ԭʼ״̬����: \n";
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	//�ı�subject״̬
	singletonPointsStatus.setCountryPoints("һ������", 21);
	cout << "�����ٷ��ı�������Ϣ����֪ͨ���۲���\n";
	subject->notify();

	//�ٴ�չʾ�۲���״̬
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	cout << endl << "һ��ʱ���ȥ��..." << endl;
	audience1.timePassed();
	audience2.timePassed();

	//�Ƴ����ֹ۲���
	subject->detach(0);
	subject->detach(1);

	//�ٴ�չʾ�۲���״̬
	cout << "�۲��ߴ�ʱ״̬����: \n";
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	singletonPointsStatus.setCountryPoints("һ������", 25);
	cout << "�����ٷ��ı�������Ϣ����֪ͨ���۲���\n";
	subject->notify();

	//�ٴ�չʾ�۲���״̬
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	delete subject;
}