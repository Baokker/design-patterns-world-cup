#include <iostream>
#include <string>
using namespace std;

class Prepare
{
public:
	Prepare() {};
	Prepare(string name,string activity) {
		this->name = name;
		this->activity = activity;
		cout << name << "��ʼ׼������������������ڴ˳��ؾٰ졣" << endl;
	};
	~Prepare() {
		cout << name << "�ϵı����Ѿ���������ʼ�����أ���������ڸó��ؾٰ졣" << endl;
	};
	void startMatch() {
		cout << activity << "������ʼ" << endl;
		cout << "....." << endl;
		cout << activity << "��������" << endl;
	}
	string getName() {
		return name;
	}
	string getActivity() {
		return activity;
	}

private:
	string name;
	string activity;
};

