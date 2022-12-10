#pragma once
#include<iostream>
#include<string>
#include <unordered_map>

using std::string;

// ԭ��ģʽ
// �������ж������ʹ�������������ǵ���

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
		std::cout << "��������" + footballName + ",��ɫ��" + color << std::endl;
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
		prototypes_[Type::TELSTAR18] = new Telstar18("Telstar 18", "����ڰ���ɫ");
		prototypes_[Type::ALRIHLA] = new Alrihla("ALRIHLA", "������������ɫ");
	}


	~PrototypeFactory() {
		delete prototypes_[Type::TELSTAR18];
		delete prototypes_[Type::ALRIHLA];
	}

	/**
	* ����type���ò�ͬ��clone����
	 */
	Football* CreatePrototype(Type type) {
		return prototypes_[type]->Clone();
	}
};

void PrototypeClient(PrototypeFactory& prototype_factory);
void testPrototype();
