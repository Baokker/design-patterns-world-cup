#include"Flyweight.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
	In this design pattern,we can use the track-and-field ground as flyweight.
*/
Flyweight::Flyweight() {}
Flyweight::~Flyweight() {}
CompetitionPhase::CompetitionPhase(string item)
{
	this->item = item;
}
void CompetitionPhase::execute(int extrinsicState)
{
	cout << "Status" << extrinsicState << ": " << this->item << endl;
}
CompetitionPhase::~CompetitionPhase() {}
FlyweightFactory::FlyweightFactory()
{
	flyweights.insert(make_pair("小组赛", new CompetitionPhase("小组赛")));
	flyweights.insert(make_pair("十六分之一决赛", new CompetitionPhase("十六分之一决赛")));
	flyweights.insert(make_pair("八分之一决赛", new CompetitionPhase("八分之一决赛")));
	flyweights.insert(make_pair("四分之一决赛", new CompetitionPhase("四分之一决赛")));
	flyweights.insert(make_pair("半决赛", new CompetitionPhase("半决赛")));
	flyweights.insert(make_pair("决赛", new CompetitionPhase("决赛")));
}
CompetitionPhase* FlyweightFactory::getFlyweight(string key)
{
	if (!flyweights.count(key))
	{
		flyweights.insert(make_pair(key, new CompetitionPhase(key)));
		cout << "Add Status :" << key << endl;
	}
	return (CompetitionPhase*)flyweights[key];
}
FlyweightFactory::~FlyweightFactory() {}

int testFlyweight()
{
	FlyweightFactory* factory = new FlyweightFactory();
	CompetitionPhase* items;
	int i = 0;
	items = factory->getFlyweight("小组赛");
	items->execute(++i);
	items = factory->getFlyweight("十六分之一决赛");
	items->execute(++i);
	items = factory->getFlyweight("热身赛");
	items->execute(++i);
	items = factory->getFlyweight("八分之一决赛");
	items->execute(++i);
	items = factory->getFlyweight("四分之一决赛");
	items->execute(++i);
	items = factory->getFlyweight("半决赛");
	items->execute(++i);
	items = factory->getFlyweight("决赛");
	items->execute(++i);
	items = factory->getFlyweight("友谊赛");
	items->execute(++i);
	cout << endl;
	return 0;
}