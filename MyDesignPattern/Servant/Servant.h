#pragma once
#include <iostream>
using namespace std;

//������
class Luggage
{
public:
	Luggage() {};
	void SettingOwner(string ownerName) { this->LuggageOwner = ownerName; };
	string LuggageSize;
	string LuggageName;
	string LuggageOwner;
};

//С����
class SmallLuggage : public Luggage
{
public:
	SmallLuggage() { this->LuggageSize = "С��"; };
};

//��������
class MediumLuggage : public Luggage
{
public:
	MediumLuggage() { this->LuggageSize = "����"; };
};

//��������
class LargeLuggage : public Luggage
{
public:
	LargeLuggage() { this->LuggageSize = "����"; };
};

//����
class Clothes : public SmallLuggage
{
public:
	Clothes() { this->LuggageName = "����"; };
	~Clothes() {};
};

//��ʳ
class Snacks : public SmallLuggage
{
public:
	Snacks() { this->LuggageName = "��ʳ"; };
	~Snacks() {};
};

//��������
class FitnessEquipment : public MediumLuggage
{
public:
	FitnessEquipment() { this->LuggageName = "��������"; };
	~FitnessEquipment() {};
};

//���г�
class Bicycle : public MediumLuggage
{
public:
	Bicycle() { this->LuggageName = "���г�"; };
	~Bicycle() {};
};

//����
class Piano : public LargeLuggage
{
public:
	Piano() { this->LuggageName = "����"; };
	~Piano() {};
};

//����
class Table : public LargeLuggage
{
public:
	Table() { this->LuggageName = "����"; };
	~Table() {};
};

class Servant
{
public:
	void CheckingLuggage(Luggage luggage[], string nameList[]);
	void HandlingLuggage(Luggage luggage[]);
};

void TestServant();