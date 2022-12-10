#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mediator;

/*
 *  Player: ����ĳ����Ա����,��Ϊ�������о�����Ա�Ļ���
 *  ÿ��Player����һ��ָ��Mediator��ָ�룬�ڱ�������Mediator���Ϊ��Ӧ��ӵ�������
 *  ��Ա����ֱ�Ӵ����Ϸ����¼���Ҫ�Բ���Ϊ�н��������Լ���ͼ
 */
class Player {
public:
	Player(Mediator* const m);//����ʱ����Mediator*������Ϊ����
	~Player();
	int getID();//��ȡ��Ա���
	virtual void send() = 0; //������Ϣ��Mediator
	virtual void off() = 0; //���滻�³�
private:
	static int idCount;//��¼�Ѿ������˶��ٸ���Ա�����Դ���Ϊ����Ա���
protected:
	int ID;//��Ա���
	Mediator* mediator;//����Ϊ����
};


/*
 *  FootballPlayer_Substitute: ������油��Ա
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class FootballPlayer_Substitute : public Player {
public:
	FootballPlayer_Substitute(Mediator* const m);
	~FootballPlayer_Substitute();

	void send();//�������������й���Ϣ
	void play();  //�油�ϳ�
	void off();  //���滻�³�
};


/*
 *  FootballPlayer_Defender: ����Ӻ�����Ա
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class FootballPlayer_Defender : public Player {
public:
	FootballPlayer_Defender(Mediator* const m);
	~FootballPlayer_Defender();

	void send();//�������������й���Ϣ
	void off();  //���滻�³�
};


/*
 *  FootballPlayer_Midfielder: ������г���Ա
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class FootballPlayer_Midfielder : public Player {
public:
	FootballPlayer_Midfielder(Mediator* const m);
	~FootballPlayer_Midfielder();

	void send();//�������������й���Ϣ
	void off();  //���滻�³�
};


/*
 *  FootballPlayer_Forward: �����ǰ����Ա
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class FootballPlayer_Forward : public Player {
public:
	FootballPlayer_Forward(Mediator* const m);
	~FootballPlayer_Forward();

	void send();//�������������й���Ϣ
	void off();  //���滻�³�
};


/*
 *  FootballPlayer_Goalkeeper: ���������Ա
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class FootballPlayer_Goalkeeper : public Player {
public:
	FootballPlayer_Goalkeeper(Mediator* const m);
	~FootballPlayer_Goalkeeper();

	void send();//�������������й���Ϣ
	void off();  //���滻�³�
};



/*
*  Mediator: �н��߳�����
*/
class Mediator {
public:
	virtual void add(Player* const p) = 0;
	virtual void addSubstitute(FootballPlayer_Substitute* const p) = 0;
	virtual void removePlayer(Player* const p) = 0;
	virtual void receiveAndReact(Player* const p) = 0;
};


/*
*  ConcreteMediator: ���������������
*/
class ConcreteMediator : public Mediator {
public:
	ConcreteMediator();
	void add(Player* const p);//��������˶�Ա
	void addSubstitute(FootballPlayer_Substitute* const p); //����油ϯ
	void removePlayer(Player* const p);  //����Ա���³�
	void receiveAndReact(Player* const p);
	~ConcreteMediator();
private:
	vector<Player*> playerList;  //����������˶�Ա�б�
	vector<FootballPlayer_Substitute*> playerListSubstitute;  //��Ϊ�油���˶�Ա�б�
};

void testMediator();//���Ժ���