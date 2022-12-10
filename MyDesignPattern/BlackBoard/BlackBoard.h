#pragma once
#include<string>
#ifndef _BLACKBOARD_H_
#define _BLACKBOARD_H_
using namespace std;
class Argentina
{
public:
	Argentina();
	~Argentina();
	virtual void setSchedule(string _schedule);
	virtual void output();
private:
	string schedule;
};


class France
{
public:
	France();
	~France();
	virtual void setSchedule(string _schedule);
	virtual void output();
private:
	string schedule;
};

class Portugal
{
public:
	Portugal();
	~Portugal();
	virtual void setSchedule(string _schedule);
	virtual void output();
private:
	string schedule;
};

class BlackBoard
{
public:
	BlackBoard();
	virtual ~BlackBoard();
	virtual void output(int type);
private:
	Argentina argentina;
	France france;
	Portugal portual;
};
#endif