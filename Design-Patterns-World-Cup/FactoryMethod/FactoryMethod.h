#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * ��Ʒ
 */
class Transport {
public:
	virtual ~Transport() {}
	virtual std::string show() const = 0;
};

/**
 * �������ṩ����ʵ��
 */
class Truck : public Transport {
public:
	std::string show() const override {
		return "һ������";
	}
};
class Plane : public Transport {
public:
	std::string show() const override {
		return "һ�ܷɻ�";
	}
};
class Ship : public Transport {
public:
	std::string show() const override {
		return "һ���ִ�";
	}
};


/**
* ������
 */
class Person {
public:
	virtual ~Person() {};
	virtual Transport* getTransport() const = 0;
	virtual string getName() const = 0;

	std::string show() const {
		// ������������
		Transport* transport = this->getTransport();
		// �����Ʒ
		string result = getName() + "ʹ����ͬ�ķ������ṩ�� " + transport->show();
		delete transport;
		return result;
	}
};

/**
* ����Ĵ�����
 */
class ChinaPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Ship();
	}
	string getName() const override {
		return "�й���";
	}
};

class AmericaPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Plane();
	}
	string getName() const override {
		return "������";
	}
};

class ArabPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Truck();
	}
	string getName() const override {
		return "��������";
	}
};

/**
* �ͻ�����֪���Ǵ��������Ĺ���
 */
void FactoryClientCode(const Person& person);

void testFactoryMethod();
