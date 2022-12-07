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
		cout << name << "开始准备比赛，其他活动不能在此场地举办。" << endl;
	};
	~Prepare() {
		cout << name << "上的比赛已经结束，开始清理场地，其他活动可在该场地举办。" << endl;
	};
	void startMatch() {
		cout << activity << "即将开始" << endl;
		cout << "....." << endl;
		cout << activity << "比赛结束" << endl;
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

