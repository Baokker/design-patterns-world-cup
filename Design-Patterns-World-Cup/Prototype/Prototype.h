#pragma once
#include<iostream>
#include<string>
#include <unordered_map>

using std::string;

// 原型模式
// 复制现有对象而不使代码依赖于它们的类

enum Type {
	TELSTAR18 = 0,
	ALRIHLA
};


class Football {
protected:
	string footballName;
	string color;

public:
	Football() {}
	Football(string footballName)
		: footballName(footballName) {
	}
	virtual ~Football() {}
	virtual Football* Clone() const = 0;
	virtual void show() {
		std::cout << "这个足球叫" + footballName + ",配色是" + color << std::endl;
	}
};


class Telstar18 : public Football {
public:
	Telstar18(string name, string color)
	{
		this->footballName = name;
		this->color = color;
	}

	Football* Clone() const override {
		return new Telstar18(*this);
	}
};

class Alrihla : public Football {
public:
	Alrihla(string name, string color)
	{
		this->footballName = name;
		this->color = color;
	}
	Football* Clone() const override {
		return new Alrihla(*this);
	}
};


class PrototypeFactory {
private:
	std::unordered_map<Type, Football*, std::hash<int>> prototypes_;

public:
	PrototypeFactory() {
		prototypes_[Type::TELSTAR18] = new Telstar18("Telstar 18", "经典黑白配色");
		prototypes_[Type::ALRIHLA] = new Alrihla("ALRIHLA", "热力红蓝白配色");
	}


	~PrototypeFactory() {
		delete prototypes_[Type::TELSTAR18];
		delete prototypes_[Type::ALRIHLA];
	}

	/**
	* 根据type调用不同的clone函数
	 */
	Football* CreatePrototype(Type type) {
		return prototypes_[type]->Clone();
	}
};

void PrototypeClient(PrototypeFactory& prototype_factory);
void testPrototype();
