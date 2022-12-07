#include"BlackBoard.h"
#include<iostream>
using namespace std;

BlackBoard::BlackBoard()
{
	argentina.setSchedule("11月27日 对阵墨西哥 \n12月1日 对阵波兰 \n12月4日 对阵澳大利亚 \n12月10日 对阵荷兰\n");
	france.setSchedule("12月4日 对阵波兰 \n12月11日 对阵英格兰 \n");
	portual.setSchedule("12月7日 对阵瑞士 \n12月10日 对阵摩洛哥 \n");
};
BlackBoard::~BlackBoard() {};

void BlackBoard::output(int type)
{
	switch (type)
	{
		case 1:
			cout << "阿根廷赛程：" << endl;
			argentina.output();
			break;
		case 2:
			cout << "法国赛程：" << endl;
			france.output();
			break;
		case 3:
			cout << "葡萄牙赛程：" << endl;
			portual.output();
			break;
		default:
			cout << "暂无该国家赛程";
	}
}

Argentina::Argentina() {};
Argentina::~Argentina() {};
void Argentina::setSchedule(string _schedule)
{
	schedule = _schedule;
}
void Argentina::output()
{
	cout << schedule;
}

France::France() {};
France::~France() {};
void France::setSchedule(string _schedule) 
{
	schedule = _schedule;
}
void France::output()
{
	cout << schedule;
}

Portugal::Portugal() {};
Portugal::~Portugal() {};
void Portugal::setSchedule(string _schedule)
{
	schedule = _schedule;
}
void Portugal::output()
{
	cout << schedule;
}

int testBlackBoard()
{
	BlackBoard* blackboard = new BlackBoard();
	while (1)
	{
		cout << "请输入要运动员的国家，来查看赛程（1-阿根廷 2-法国 3-葡萄牙 0-退出）" << endl;
		int type;
		cin >> type;
		if (type == 0)
			break;
		blackboard->output(type);
	}
	return 0;
}
