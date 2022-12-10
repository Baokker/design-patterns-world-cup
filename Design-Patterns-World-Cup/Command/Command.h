#pragma once
#include <iostream>
#include <stack>
#include<string>
using namespace std;


// 得分：请求接收者Receiver
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
			cout << team << "队那颗头球不算，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "队进了一颗头球，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
	void footStrike(string team, int type) {
		if (type < 0) {
			this->score[-type - 1] -= 1;
			cout << team << "队刚刚那颗球无效，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "队一脚破门，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
	void longStrike(string team, int type) {
		if (type < 0) {
			this->score[-type - 1] -= 1;
			cout << team << "队那颗远射不算，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
		else {
			this->score[type - 1] += 1;
			cout << team << "队来了一记世界波，当前比分为" << this->score[0] << ':' << this->score[1] << endl;
		}
	}
private:
	int score[2];
};


// 抽象命令类
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
	virtual void execute() = 0; //声明命令执行方法execute()
	//virtual void* Redo() = 0;
	virtual void undo() = 0; //声明撤销方法undo()
	string team;
	int type;
protected:
	CommandScoreReceiver* receiver;
};

//头球
class HeadStrike : public CommandScore {
public:
	HeadStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//实现抽象命令类中声明的execute()方法，调用分数类的计分操作
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

//用脚破门
class FootStrike : public CommandScore {
public:
	FootStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//实现抽象命令类中声明的execute()方法，调用分数类的计分操作
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

//远距离射门
class LongStrike : public CommandScore {
public:
	LongStrike(CommandScoreReceiver* receiver, string team, int type)
	{
		this->team = team;
		this->type = type;
		this->receiver = receiver;
	}
	//实现抽象命令类中声明的execute()方法，调用分数类的计分操作
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

// 计分界面类：请求发送者
class ScoreForm {
public:
	ScoreForm()
	{
		;
	}

	//记录进球并显示
	void recordScore(CommandScore* commandScore) {
		scoreRecord.push(commandScore);
		commandScore->execute();
	}

	//撤回
	void undo() {
		if (scoreRecord.empty()) {
			cout << 10086;
			return;
		}

		//获取上一个进球记录
		CommandScore* preCommand = scoreRecord.top();
		scoreRecord.pop();
		//回退
		preCommand->undo();
	}

private:
	stack<CommandScore*> scoreRecord;
};

void testCommand();