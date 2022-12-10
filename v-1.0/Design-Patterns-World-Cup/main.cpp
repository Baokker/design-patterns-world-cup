#include<iostream>
#include"FrontController/FrontController.h"
#include"./utils/animate.h"
#include<string>

using namespace std;



int main()
{
	startAnimate();//��������

	Dispatcher dispatcher;
	FrontController frontController;
	frontController.set(&dispatcher);
	const string noTestPattern[] = { "frontController", "RAII", "singleton"}; //��Щ���ģʽ���ϲ������������ģʽ��

	int preNum = 8;//����ǰ����׼���׶����ģʽ����
	int numOpeningCeremony = 4; //��Ļʽ�ڼ�����ģʽ
	int competitionNum = 16;//���籭�����ڼ�ĳ���

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

		//����������֮��Ĺ��ɶ���
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

	transferAnimate(4, 5);//��������
	system("pause");

	testAll();
	return 0;
}