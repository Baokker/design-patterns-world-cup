#include<iostream>
#include"FrontController/FrontController.h"
#include"./utils/animate.h"
#include<string>

using namespace std;



int main()
{
	startAnimate();//开场动画

	Dispatcher dispatcher;
	FrontController frontController;
	frontController.set(&dispatcher);
	const string noTestPattern[] = { "frontController", "RAII", "singleton"}; //这些设计模式被合并到了其他设计模式中

	int preNum = 8;//比赛前建设准备阶段设计模式数量
	int numOpeningCeremony = 4; //开幕式期间的设计模式
	int competitionNum = 16;//世界杯比赛期间的场景

	for (int i = 0; i < 30; i++)
	{
		bool continueFlag = false;
		for (auto str : noTestPattern) {

			if (designPatterns[i] == str) {
				continueFlag = true;
				break;
			}
		}

		if (continueFlag) {
			continue;
		}

		//三个主场景之间的过渡动画
		if (i == 0) {
			system("pause");
			transferAnimate(0, 1);
			system("pause");
		}
		else if (i == preNum) {
			transferAnimate(1, 2);
			system("pause");
		}
		else if (i == preNum + numOpeningCeremony) {
			transferAnimate(2, 3);
			system("pause");
		}
		else if (i == preNum + numOpeningCeremony + competitionNum) {
			transferAnimate(3, 4);
			system("pause");
		}

		frontController.dispatchRequest(designPatterns[i]);
		system("pause");
		cout << endl;
	}

	transferAnimate(4, 5);//结束动画
	system("pause");

	testAll();
	return 0;
}