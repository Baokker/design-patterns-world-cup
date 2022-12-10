#include"BlackBoard.h"
#include<iostream>
using namespace std;

BlackBoard::BlackBoard()
{
	argentina.setSchedule("11��27�� ����ī���� \n12��1�� ������ \n12��4�� ����Ĵ����� \n12��10�� �������\n");
	france.setSchedule("12��4�� ������ \n12��11�� ����Ӣ���� \n");
	portual.setSchedule("12��7�� ������ʿ \n12��10�� ����Ħ��� \n");
};
BlackBoard::~BlackBoard() {};

void BlackBoard::output(int type)
{
	switch (type)
	{
		case 1:
			cout << "����͢���̣�" << endl;
			argentina.output();
			break;
		case 2:
			cout << "�������̣�" << endl;
			france.output();
			break;
		case 3:
			cout << "���������̣�" << endl;
			portual.output();
			break;
		default:
			cout << "���޸ù�������";
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
		cout << "������Ҫ�˶�Ա�Ĺ��ң����鿴���̣�1-����͢ 2-���� 3-������ 0-�˳���" << endl;
		int type;
		cin >> type;
		if (type == 0)
			break;
		blackboard->output(type);
	}
	return 0;
}
