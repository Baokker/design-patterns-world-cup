#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * 产品
 */
class Transport {
public:
	virtual ~Transport() {}
	virtual std::string show() const = 0;
};

/**
 * 具体类提供具体实现
 */
class Truck : public Transport {
public:
	std::string show() const override {
		return "一辆货车";
	}
};
class Plane : public Transport {
public:
	std::string show() const override {
		return "一架飞机";
	}
};
class Ship : public Transport {
public:
	std::string show() const override {
		return "一艘轮船";
	}
};


/**
* 创建者
 */
class Person {
public:
	virtual ~Person() {};
	virtual Transport* getTransport() const = 0;
	virtual string getName() const = 0;

	std::string show() const {
		// 创建工厂方法
		Transport* transport = this->getTransport();
		// 输出产品
		string result = getName() + "使用相同的方法，提供了 " + transport->show();
		delete transport;
		return result;
	}
};

/**
* 具体的创造者
 */
class ChinaPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Ship();
	}
	string getName() const override {
		return "中国人";
	}
};

class AmericaPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Plane();
	}
	string getName() const override {
		return "美国人";
	}
};

class ArabPerson : public Person {
public:
	Transport* getTransport() const override {
		return new Truck();
	}
	string getName() const override {
		return "阿拉伯人";
	}
};

/**
* 客户并不知道是创建者是哪国人
 */
void FactoryClientCode(const Person& person);

void testFactoryMethod();
