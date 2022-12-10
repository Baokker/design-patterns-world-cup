#pragma once
#include <iostream>
#include <stack>
#include<string>
using namespace std;


// �÷֣����������Receiver
class CommandScoreReceiver
{
public:
	CommandScoreReceiver()
	{
		score[0] = 0;
		score[1] = 0;
	}
	void headStrike(string team, int type) {
		if (type < 0) {
			this->score[-type - 1] -= 1;
			cout << team << "���ǿ�ͷ���㣬��ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "�ӽ���һ��ͷ�򣬵�ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
	void footStrike(string team, int type) {
		if (type < 0) {
			this->score[-type - 1] -= 1;
			cout << team << "�Ӹո��ǿ�����Ч����ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "��һ�����ţ���ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
	void longStrike(string team, int type) {
		if (type < 0) {
			this->score[-type - 1] -= 1;
			cout << team << "���ǿ�Զ�䲻�㣬��ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "������һ�����粨����ǰ�ȷ�Ϊ" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
private:
	int score[2];
};


// ����������
class CommandScore
{
public:
	~CommandScore()
	{
		;
	}
	CommandScore()
	{
		;
	}
	CommandScore(CommandScoreReceiver* receiver)
	{
		this->receiver = receiver;
	}
	virtual void execute() = 0; //��������ִ�з���execute()
	//virtual void* Redo() = 0;
	virtual void undo() = 0; //������������undo()
	string team;
	int type;
protected:
	CommandScoreReceiver* receiver;
};

//ͷ��
class HeadStrike : public CommandScore {
public:
	HeadStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//ʵ�ֳ�����������������execute()���������÷�����ļƷֲ���
	virtual void execute()
	{
		this->receiver->headStrike(this->team, this->type);
	}

	virtual void undo()
	{
		this->receiver->headStrike(this->team, -(this->type));
	}

	string team;
	int type;
};

//�ý�����
class FootStrike : public CommandScore {
public:
	FootStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//ʵ�ֳ�����������������execute()���������÷�����ļƷֲ���
	virtual void execute()
	{
		this->receiver->footStrike(this->team, this->type);
	}

	virtual void undo()
	{
		this->receiver->footStrike(this->team, -(this->type));
	}

	string team;
	int type;
};

//Զ��������
class LongStrike : public CommandScore {
public:
	LongStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//ʵ�ֳ�����������������execute()���������÷�����ļƷֲ���
	virtual void execute()
	{
		this->receiver->longStrike(this->team, this->type);
	}

	virtual void undo()
	{
		this->receiver->longStrike(this->team, -(this->type));
	}

	string team;
	int type;
};

// �Ʒֽ����ࣺ��������
class ScoreForm {
public:
	ScoreForm()
	{
		;
	}

	//��¼������ʾ
	void recordScore(CommandScore* commandScore) {
		scoreRecord.push(commandScore);
		commandScore->execute();
	}

	//����
	void undo() {
		if (scoreRecord.empty()) {
			cout << 10086;
			return;
		}

		//��ȡ��һ�������¼
		CommandScore* preCommand = scoreRecord.top();
		scoreRecord.pop();
		//����
		preCommand->undo();
	}

private:
	stack<CommandScore*> scoreRecord;
};

void testCommand();