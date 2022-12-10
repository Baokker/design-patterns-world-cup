#include <iostream>
#include "Servant.h"

using namespace std;

void Servant::checkingLuggage(Luggage luggage[], string nameList[])
{

	cout << "开始检查行李" << endl <<endl;

	for (int i = 0; i < 6; i++)
	{
		luggage[i].settingOwner(nameList[i]);
		cout << i << "号行李" << endl;
		cout << "行李名：                  " << luggage[i].luggageName << endl;
		cout << "行李尺寸：                " << luggage[i].luggageSize << endl;
		cout << "行李所有者：              " << luggage[i].luggageOwner << endl;
		cout << endl;
	}

	cout << "行李检查结束" << endl;

}

void Servant::handlingLuggage(Luggage luggage[])
{
	string smallSize = "小型";
	string mediumSize = "中型";
	string largeSize = "大型";

	cout << "雇工开始搬运工作" << endl << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		cout << "当前的行李是：" << luggage[i].luggageName << endl;
		cout << "行李的尺寸为：" << luggage[i].luggageSize << endl;
		
		cout << "雇工开始搬运" << endl;

		if (smallSize == luggage[i].luggageSize)
		{
			cout << "雇工表示搬运起来很轻松" << endl;
		}
		else if (mediumSize == luggage[i].luggageSize)
		{
			cout << "雇工表示搬运起来还算可以" << endl;
		}
		else
		{
			cout << "雇工使出了吃奶的劲儿" << endl;
		}

		cout << "雇工成功将物品搬运到了" << luggage[i].luggageOwner << "的房间里" << endl << endl;
	}

	cout << "雇工结束搬运工作" << endl << endl;
}

void testServant()
{
	//行李列表
	Luggage luggage[6];
	//衣物
	Clothes clothes;
	//零食
	Snacks snacks;
	//健身器材
	FitnessEquipment fitnessEquipment;
	//自行车
	Bicycle bicycle;
	//钢琴
	Piano piano;
	//餐桌
	Table table;

	//雇工
	Servant servant;

	//名单
	string nameList[6] = {
		"刘能",
		"韦世豪",
		"赵四",
		"跑跑",
		"水一哥",
		"赵哥"
	};

	luggage[0] = clothes;
	luggage[1] = snacks;
	luggage[2] = fitnessEquipment;
	luggage[3] = bicycle;
	luggage[4] = piano;
	luggage[5] = table;

	//雇工检查行李
	servant.checkingLuggage(luggage, nameList);
	//雇工搬运行李
	servant.handlingLuggage(luggage);

}