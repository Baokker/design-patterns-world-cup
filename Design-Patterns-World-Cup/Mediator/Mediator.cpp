#include "Mediator.h"
//#include "../Command/Command.h"
#include <algorithm>
using namespace std;

int Player::idCount = 0;

Player::Player(Mediator* const m) :
	mediator(m), ID(++idCount) {}

Player::~Player() {}

int Player::getID() {
	return this->ID;
}

//ͨ��id�õ��������ƣ�1-5Ϊ
string getTeamName(int id) {
	if (id % 32 <= 16 && id % 32 > 0) {
		return "�й� ��";
	}
	else {
		return "�ձ� ��";
	}
}


FootballPlayer_Substitute::FootballPlayer_Substitute(Mediator* const m) :
	Player(m) {}

FootballPlayer_Substitute::~FootballPlayer_Substitute() {}

void FootballPlayer_Substitute::FootballPlayer_Substitute::send() {
	cout << getTeamName(ID) << "�油��Ա No. " << ID << " ����������֧���ź�." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Substitute::play() {
	cout << getTeamName(ID) << "�油��Ա No. " << ID << " �ϳ�����." << endl;
	this->mediator->add(this);
}

void FootballPlayer_Substitute::off() {
	this->mediator->removePlayer(this);
	cout << "�油��Ա No. " << this->getID() << "(" << getTeamName(this->getID()) << ") ��������֧���滻�³�.\n";
}


FootballPlayer_Defender::FootballPlayer_Defender(Mediator* const m) :
	Player(m) {}

FootballPlayer_Defender::~FootballPlayer_Defender() {}

void FootballPlayer_Defender::FootballPlayer_Defender::send() {
	cout << getTeamName(ID) << "������Ա No. " << ID << " ����������֧���ź�." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Defender::off() {
	this->mediator->removePlayer(this);
	cout << "������Ա No. " << this->getID() << "(" << getTeamName(this->getID()) << ") ��������֧���滻�³�.\n";
}

FootballPlayer_Midfielder::FootballPlayer_Midfielder(Mediator* const m) :
	Player(m) {}

FootballPlayer_Midfielder::~FootballPlayer_Midfielder() {}

void FootballPlayer_Midfielder::FootballPlayer_Midfielder::send() {
	cout << getTeamName(ID) << "�г���Ա No. " << ID << " ����������֧���ź�." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Midfielder::off() {
	this->mediator->removePlayer(this);
	cout << "�г���Ա No. " << this->getID() << "(" << getTeamName(this->getID()) << ") ��������֧���滻�³�.\n";
}

FootballPlayer_Forward::FootballPlayer_Forward(Mediator* const m) :
	Player(m) {}

FootballPlayer_Forward::~FootballPlayer_Forward() {}

void FootballPlayer_Forward::FootballPlayer_Forward::send() {
	cout << getTeamName(ID) << "ǰ����Ա No. " << ID << " ����������֧���ź�." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Forward::off() {
	this->mediator->removePlayer(this);
	cout << "ǰ����Ա No. " << this->getID() << "(" << getTeamName(this->getID()) << ") ��������֧���滻�³�.\n";
}

FootballPlayer_Goalkeeper::FootballPlayer_Goalkeeper(Mediator* const m) :
	Player(m) {}

FootballPlayer_Goalkeeper::~FootballPlayer_Goalkeeper() {}

void FootballPlayer_Goalkeeper::FootballPlayer_Goalkeeper::send() {
	cout << getTeamName(ID) << "����Աѡ�� No. " << ID << " ����������֧���ź�." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Goalkeeper::off() {
	this->mediator->removePlayer(this);
	cout << "����Աѡ�� No. " << this->getID() << "(" << getTeamName(this->getID()) << ") ��������֧���滻�³�.\n";
}

ConcreteMediator::ConcreteMediator() {}
void ConcreteMediator::add(Player* const p) {
	playerList.push_back(p);
	cout << "��Ա" << p->getID() << "(" << getTeamName(p->getID()) << ") �����������.\n";
}

void ConcreteMediator::addSubstitute(FootballPlayer_Substitute* const p)
{
	this->playerListSubstitute.push_back(p);
	cout << "�油��Ա No. " << p->getID() << "(" << getTeamName(p->getID()) << ") �����油ϯ.\n";
}

void ConcreteMediator::removePlayer(Player* const p) {
	remove(playerList.begin(), playerList.end(), p);
}

void ConcreteMediator::receiveAndReact(Player* const p) {
	cout << "������������Ӧ : " << endl;
	p->off();
	(*(playerListSubstitute.begin()))->play();
}

ConcreteMediator::~ConcreteMediator() {
	for (auto player : playerList) {
		delete[] player;
	}
	playerList.clear();
}

void testMediator() {
	Mediator* coach = new ConcreteMediator();//�н��ߣ�����������Ϊ��ӽ���

	//�������10�������˶�Ա����Ӧ˫����������10����Ա
	Player* p1 = new FootballPlayer_Goalkeeper(coach);
	Player* p2 = new FootballPlayer_Defender(coach);
	Player* p3 = new FootballPlayer_Defender(coach);
	Player* p4 = new FootballPlayer_Midfielder(coach);
	Player* p5 = new FootballPlayer_Midfielder(coach);
	Player* p6 = new FootballPlayer_Midfielder(coach);
	Player* p7 = new FootballPlayer_Forward(coach);
	Player* p8 = new FootballPlayer_Forward(coach);
	Player* p9 = new FootballPlayer_Forward(coach);
	Player* p10 = new FootballPlayer_Forward(coach);
	Player* p11 = new FootballPlayer_Forward(coach);
	FootballPlayer_Substitute* p12 = new FootballPlayer_Substitute(coach);
	FootballPlayer_Substitute* p13 = new FootballPlayer_Substitute(coach);
	FootballPlayer_Substitute* p14 = new FootballPlayer_Substitute(coach);
	FootballPlayer_Substitute* p15 = new FootballPlayer_Substitute(coach);
	FootballPlayer_Substitute* p16 = new FootballPlayer_Substitute(coach);

	coach->add(p1);
	coach->add(p2);
	coach->add(p3);
	coach->add(p4);
	coach->add(p5);
	coach->add(p6);
	coach->add(p7);
	coach->add(p8);
	coach->add(p9);
	coach->add(p10);
	coach->add(p11);

	coach->addSubstitute(p12);
	coach->addSubstitute(p13);
	coach->addSubstitute(p14);
	coach->addSubstitute(p15);
	coach->addSubstitute(p16);

	cout << "\nGame start!\n";
	//Point* receiver = new Point();
	//ScoreForm* scoreform = new ScoreForm();

	//scoreform->compute(new ScoreCommand(receiver, 0, 2));// ���ӵ�2��
	//scoreform->compute(new ScoreCommand(receiver, 0, 3));// ���ӵ�3��
	//scoreform->compute(new ScoreCommand(receiver, 1, 2));// �Ͷӵ�2��

	p1->send();//p1���źű�ʾ������֧��ʾ��������������Ա�滻
	cout << endl;


	//scoreform->undo();// ������һ�μƷ�
	//scoreform->compute(new ScoreCommand(receiver, 1, 1));// �Ͷӵ�1��
	//scoreform->compute(new ScoreCommand(receiver, 1, 3));// �Ͷӵ�3��

	p8->send();//p7Ҫ��ֹͣ������֪ͨ���С�����ͬ���Ҫ�������˶�ԱҲͣ��
	cout << endl;

	// ������һ�μƷ�
	//scoreform->undo();
	//scoreform->redo();
	//delete scoreform;
}