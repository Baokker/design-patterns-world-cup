#pragma once
#include <iostream>
using namespace std;

//行李类
class Luggage
{
public:
	Luggage() {};
	void SettingOwner(string ownerName) { this->LuggageOwner = ownerName; };
	string LuggageSize;
	string LuggageName;
	string LuggageOwner;
};

//小行李
class SmallLuggage : public Luggage
{
public:
	SmallLuggage() { this->LuggageSize = "小型"; };
};

//中型行李
class MediumLuggage : public Luggage
{
public:
	MediumLuggage() { this->LuggageSize = "中型"; };
};

//大型行李
class LargeLuggage : public Luggage
{
public:
	LargeLuggage() { this->LuggageSize = "大型"; };
};

//衣物
class Clothes : public SmallLuggage
{
public:
	Clothes() { this->LuggageName = "衣物"; };
	~Clothes() {};
};

//零食
class Snacks : public SmallLuggage
{
public:
	Snacks() { this->LuggageName = "零食"; };
	~Snacks() {};
};

//健身器材
class FitnessEquipment : public MediumLuggage
{
public:
	FitnessEquipment() { this->LuggageName = "健身器材"; };
	~FitnessEquipment() {};
};

//自行车
class Bicycle : public MediumLuggage
{
public:
	Bicycle() { this->LuggageName = "自行车"; };
	~Bicycle() {};
};

//钢琴
class Piano : public LargeLuggage
{
public:
	Piano() { this->LuggageName = "钢琴"; };
	~Piano() {};
};

//餐桌
class Table : public LargeLuggage
{
public:
	Table() { this->LuggageName = "餐桌"; };
	~Table() {};
};

class Servant
{
public:
	void CheckingLuggage(Luggage luggage[], string nameList[]);
	void HandlingLuggage(Luggage luggage[]);
};

void TestServant();