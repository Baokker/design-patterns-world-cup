#pragma once
#include <iostream>
using namespace std;

//������
class Luggage
{
public:
	Luggage() {};
	void settingOwner(string ownerName) { this->luggageOwner = ownerName; };
	string luggageSize;
	string luggageName;
	string luggageOwner;
};

//С����
class SmallLuggage : public Luggage
{
public:
	SmallLuggage() { this->luggageSize = "С��"; };
};

//��������
class MediumLuggage : public Luggage
{
public:
	MediumLuggage() { this->luggageSize = "����"; };
};

//��������
class LargeLuggage : public Luggage
{
public:
	LargeLuggage() { this->luggageSize = "����"; };
};

//����
class Clothes : public SmallLuggage
{
public:
	Clothes() { this->luggageName = "����"; };
	~Clothes() {};
};

//��ʳ
class Snacks : public SmallLuggage
{
public:
	Snacks() { this->luggageName = "��ʳ"; };
	~Snacks() {};
};

//��������
class FitnessEquipment : public MediumLuggage
{
public:
	FitnessEquipment() { this->luggageName = "��������"; };
	~FitnessEquipment() {};
};

//���г�
class Bicycle : public MediumLuggage
{
public:
	Bicycle() { this->luggageName = "���г�"; };
	~Bicycle() {};
};

//����
class Piano : public LargeLuggage
{
public:
	Piano() { this->luggageName = "����"; };
	~Piano() {};
};

//����
class Table : public LargeLuggage
{
public:
	Table() { this->luggageName = "����"; };
	~Table() {};
};

class Servant
{
public:
	void checkingLuggage(Luggage luggage[], string nameList[]);
	void handlingLuggage(Luggage luggage[]);
};

void testServant();