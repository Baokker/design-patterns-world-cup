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
	flyweights.insert(make_pair("С����", new CompetitionPhase("С����")));
	flyweights.insert(make_pair("ʮ����֮һ����", new CompetitionPhase("ʮ����֮һ����")));
	flyweights.insert(make_pair("�˷�֮һ����", new CompetitionPhase("�˷�֮һ����")));
	flyweights.insert(make_pair("�ķ�֮һ����", new CompetitionPhase("�ķ�֮һ����")));
	flyweights.insert(make_pair("�����", new CompetitionPhase("�����")));
	flyweights.insert(make_pair("����", new CompetitionPhase("����")));
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
	items = factory->getFlyweight("С����");
	items->execute(++i);
	items = factory->getFlyweight("ʮ����֮һ����");
	items->execute(++i);
	items = factory->getFlyweight("������");
	items->execute(++i);
	items = factory->getFlyweight("�˷�֮һ����");
	items->execute(++i);
	items = factory->getFlyweight("�ķ�֮һ����");
	items->execute(++i);
	items = factory->getFlyweight("�����");
	items->execute(++i);
	items = factory->getFlyweight("����");
	items->execute(++i);
	items = factory->getFlyweight("������");
	items->execute(++i);
	cout << endl;
	return 0;
}