#pragma once
#include <iostream>
using namespace std;

//行李类
class Luggage
{
public:
	Luggage() {};
	void settingOwner(string ownerName) { this->luggageOwner = ownerName; };
	string luggageSize;
	string luggageName;
	string luggageOwner;
};

//小行李
class SmallLuggage : public Luggage
{
public:
	SmallLuggage() { this->luggageSize = "小型"; };
};

//中型行李
class MediumLuggage : public Luggage
{
public:
	MediumLuggage() { this->luggageSize = "中型"; };
};

//大型行李
class LargeLuggage : public Luggage
{
public:
	LargeLuggage() { this->luggageSize = "大型"; };
};

//衣物
class Clothes : public SmallLuggage
{
public:
	Clothes() { this->luggageName = "衣物"; };
	~Clothes() {};
};

//零食
class Snacks : public SmallLuggage
{
public:
	Snacks() { this->luggageName = "零食"; };
	~Snacks() {};
};

//健身器材
class FitnessEquipment : public MediumLuggage
{
public:
	FitnessEquipment() { this->luggageName = "健身器材"; };
	~FitnessEquipment() {};
};

//自行车
class Bicycle : public MediumLuggage
{
public:
	Bicycle() { this->luggageName = "自行车"; };
	~Bicycle() {};
};

//钢琴
class Piano : public LargeLuggage
{
public:
	Piano() { this->luggageName = "钢琴"; };
	~Piano() {};
};

//餐桌
class Table : public LargeLuggage
{
public:
	Table() { this->luggageName = "餐桌"; };
	~Table() {};
};

class Servant
{
public:
	void checkingLuggage(Luggage luggage[], string nameList[]);
	void handlingLuggage(Luggage luggage[]);
};

void testServant();