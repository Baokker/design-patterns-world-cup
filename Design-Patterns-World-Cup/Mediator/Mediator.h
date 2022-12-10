#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mediator;

/*
 *  Player: 代表某种球员的类,作为场上所有具体球员的基类
 *  每个Player都有一个指向Mediator的指针，在本场景，Mediator理解为对应球队的主教练
 *  球员不能直接处理场上发生事件，要以裁判为中介来传达自己意图
 */
class Player {
public:
	Player(Mediator* const m);//构造时传入Mediator*，可视为裁判
	~Player();
	int getID();//获取球员编号
	virtual void send() = 0; //发送信息给Mediator
	virtual void off() = 0; //被替换下场
private:
	static int idCount;//记录已经加入了多少个球员，并以此作为新球员编号
protected:
	int ID;//球员编号
	Mediator* mediator;//可视为裁判
};


/*
 *  FootballPlayer_Substitute: 足球队替补队员
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与足球赛有关
 */
class FootballPlayer_Substitute : public Player {
public:
	FootballPlayer_Substitute(Mediator* const m);
	~FootballPlayer_Substitute();

	void send();//发送与足球赛有关信息
	void play();  //替补上场
	void off();  //被替换下场
};


/*
 *  FootballPlayer_Defender: 足球队后卫球员
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与足球赛有关
 */
class FootballPlayer_Defender : public Player {
public:
	FootballPlayer_Defender(Mediator* const m);
	~FootballPlayer_Defender();

	void send();//发送与足球赛有关信息
	void off();  //被替换下场
};


/*
 *  FootballPlayer_Midfielder: 足球队中场球员
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与足球赛有关
 */
class FootballPlayer_Midfielder : public Player {
public:
	FootballPlayer_Midfielder(Mediator* const m);
	~FootballPlayer_Midfielder();

	void send();//发送与足球赛有关信息
	void off();  //被替换下场
};


/*
 *  FootballPlayer_Forward: 足球队前锋球员
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与足球赛有关
 */
class FootballPlayer_Forward : public Player {
public:
	FootballPlayer_Forward(Mediator* const m);
	~FootballPlayer_Forward();

	void send();//发送与足球赛有关信息
	void off();  //被替换下场
};


/*
 *  FootballPlayer_Goalkeeper: 足球队守门员
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与足球赛有关
 */
class FootballPlayer_Goalkeeper : public Player {
public:
	FootballPlayer_Goalkeeper(Mediator* const m);
	~FootballPlayer_Goalkeeper();

	void send();//发送与足球赛有关信息
	void off();  //被替换下场
};



/*
*  Mediator: 中介者抽象类
*/
class Mediator {
public:
	virtual void add(Player* const p) = 0;
	virtual void addSubstitute(FootballPlayer_Substitute* const p) = 0;
	virtual void removePlayer(Player* const p) = 0;
	virtual void receiveAndReact(Player* const p) = 0;
};


/*
*  ConcreteMediator: 足球比赛的主教练
*/
class ConcreteMediator : public Mediator {
public:
	ConcreteMediator();
	void add(Player* const p);//添加球赛运动员
	void addSubstitute(FootballPlayer_Substitute* const p); //添加替补席
	void removePlayer(Player* const p);  //将球员换下场
	void receiveAndReact(Player* const p);
	~ConcreteMediator();
private:
	vector<Player*> playerList;  //参与比赛的运动员列表
	vector<FootballPlayer_Substitute*> playerListSubstitute;  //作为替补的运动员列表
};

void testMediator();//测试函数