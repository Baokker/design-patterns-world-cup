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

//通过id得到队伍名称，1-5为
string getTeamName(int id) {
	if (id % 32 <= 16 && id % 32 > 0) {
		return "中国 队";
	}
	else {
		return "日本 队";
	}
}


FootballPlayer_Substitute::FootballPlayer_Substitute(Mediator* const m) :
	Player(m) {}

FootballPlayer_Substitute::~FootballPlayer_Substitute() {}

void FootballPlayer_Substitute::FootballPlayer_Substitute::send() {
	cout << getTeamName(ID) << "替补球员 No. " << ID << " 发出体力不支的信号." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Substitute::play() {
	cout << getTeamName(ID) << "替补球员 No. " << ID << " 上场比赛." << endl;
	this->mediator->add(this);
}

void FootballPlayer_Substitute::off() {
	this->mediator->removePlayer(this);
	cout << "替补球员 No. " << this->getID() << "(" << getTeamName(this->getID()) << ") 因体力不支被替换下场.\n";
}


FootballPlayer_Defender::FootballPlayer_Defender(Mediator* const m) :
	Player(m) {}

FootballPlayer_Defender::~FootballPlayer_Defender() {}

void FootballPlayer_Defender::FootballPlayer_Defender::send() {
	cout << getTeamName(ID) << "后卫球员 No. " << ID << " 发出体力不支的信号." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Defender::off() {
	this->mediator->removePlayer(this);
	cout << "后卫球员 No. " << this->getID() << "(" << getTeamName(this->getID()) << ") 因体力不支被替换下场.\n";
}

FootballPlayer_Midfielder::FootballPlayer_Midfielder(Mediator* const m) :
	Player(m) {}

FootballPlayer_Midfielder::~FootballPlayer_Midfielder() {}

void FootballPlayer_Midfielder::FootballPlayer_Midfielder::send() {
	cout << getTeamName(ID) << "中场球员 No. " << ID << " 发出体力不支的信号." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Midfielder::off() {
	this->mediator->removePlayer(this);
	cout << "中场球员 No. " << this->getID() << "(" << getTeamName(this->getID()) << ") 因体力不支被替换下场.\n";
}

FootballPlayer_Forward::FootballPlayer_Forward(Mediator* const m) :
	Player(m) {}

FootballPlayer_Forward::~FootballPlayer_Forward() {}

void FootballPlayer_Forward::FootballPlayer_Forward::send() {
	cout << getTeamName(ID) << "前锋球员 No. " << ID << " 发出体力不支的信号." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Forward::off() {
	this->mediator->removePlayer(this);
	cout << "前锋球员 No. " << this->getID() << "(" << getTeamName(this->getID()) << ") 因体力不支被替换下场.\n";
}

FootballPlayer_Goalkeeper::FootballPlayer_Goalkeeper(Mediator* const m) :
	Player(m) {}

FootballPlayer_Goalkeeper::~FootballPlayer_Goalkeeper() {}

void FootballPlayer_Goalkeeper::FootballPlayer_Goalkeeper::send() {
	cout << getTeamName(ID) << "守门员选手 No. " << ID << " 发出体力不支的信号." << endl;
	this->mediator->receiveAndReact(this);
}

void FootballPlayer_Goalkeeper::off() {
	this->mediator->removePlayer(this);
	cout << "守门员选手 No. " << this->getID() << "(" << getTeamName(this->getID()) << ") 因体力不支被替换下场.\n";
}

ConcreteMediator::ConcreteMediator() {}
void ConcreteMediator::add(Player* const p) {
	playerList.push_back(p);
	cout << "球员" << p->getID() << "(" << getTeamName(p->getID()) << ") 进入比赛赛场.\n";
}

void ConcreteMediator::addSubstitute(FootballPlayer_Substitute* const p)
{
	this->playerListSubstitute.push_back(p);
	cout << "替补球员 No. " << p->getID() << "(" << getTeamName(p->getID()) << ") 加入替补席.\n";
}

void ConcreteMediator::removePlayer(Player* const p) {
	remove(playerList.begin(), playerList.end(), p);
}

void ConcreteMediator::receiveAndReact(Player* const p) {
	cout << "主教练作出回应 : " << endl;
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
	Mediator* coach = new ConcreteMediator();//中介者，这里可以理解为球队教练

	//依次添加10个篮球运动员，对应双方篮球赛的10名队员
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

	//scoreform->compute(new ScoreCommand(receiver, 0, 2));// 主队得2分
	//scoreform->compute(new ScoreCommand(receiver, 0, 3));// 主队得3分
	//scoreform->compute(new ScoreCommand(receiver, 1, 2));// 客队得2分

	p1->send();//p1发信号表示体力不支，示意主教练进行人员替换
	cout << endl;


	//scoreform->undo();// 撤销上一次计分
	//scoreform->compute(new ScoreCommand(receiver, 1, 1));// 客队得1分
	//scoreform->compute(new ScoreCommand(receiver, 1, 3));// 客队得3分

	p8->send();//p7要求停止比赛，通知裁判。裁判同意后要求其他运动员也停下
	cout << endl;

	// 撤销上一次计分
	//scoreform->undo();
	//scoreform->redo();
	//delete scoreform;
}