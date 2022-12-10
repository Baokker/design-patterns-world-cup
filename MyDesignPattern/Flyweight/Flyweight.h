#pragma once
#include<string>
#include<map>
#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_
using namespace std;
class Flyweight
{
public:
	Flyweight();
	virtual ~Flyweight();
	virtual void execute(int extrinsicState) = 0;
};
class CompetitionPhase :public Flyweight
{
public:
	CompetitionPhase(string item);
	~CompetitionPhase();
	void execute(int extrinsicState);
private:
	string item;
};
class FlyweightFactory
{
private:
	map<string, CompetitionPhase* >flyweights;
public:
	FlyweightFactory();
	virtual ~FlyweightFactory();
	virtual CompetitionPhase* getFlyweight(string key);
	map<string, CompetitionPhase*>* getFlyWeights()
	{
		return  &flyweights;
	}
};

int testFlyweight();

#endif // !_FLYWEIGHT_H_
#pragma once
