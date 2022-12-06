#include <iostream>
#include "Servant.h"

using namespace std;

void Servant::CheckingLuggage(Luggage luggage[], string nameList[])
{

	cout << "��ʼ�������" << endl <<endl;

	for (int i = 0; i < 6; i++)
	{
		luggage[i].SettingOwner(nameList[i]);
		cout << i << "������" << endl;
		cout << "��������                  " << luggage[i].LuggageName << endl;
		cout << "����ߴ磺                " << luggage[i].LuggageSize << endl;
		cout << "���������ߣ�              " << luggage[i].LuggageOwner << endl;
		cout << endl;
	}

	cout << "���������" << endl;

}

void Servant::HandlingLuggage(Luggage luggage[])
{
	string smallSize = "С��";
	string mediumSize = "����";
	string largeSize = "����";

	cout << "�͹���ʼ���˹���" << endl << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		cout << "��ǰ�������ǣ�" << luggage[i].LuggageName << endl;
		cout << "����ĳߴ�Ϊ��" << luggage[i].LuggageSize << endl;
		
		cout << "�͹���ʼ����" << endl;

		if (smallSize == luggage[i].LuggageSize)
		{
			cout << "�͹���ʾ��������������" << endl;
		}
		else if (mediumSize == luggage[i].LuggageSize)
		{
			cout << "�͹���ʾ���������������" << endl;
		}
		else
		{
			cout << "�͹�ʹ���˳��̵ľ���" << endl;
		}

		cout << "�͹��ɹ�����Ʒ���˵���" << luggage[i].LuggageOwner << "�ķ�����" << endl << endl;
	}

	cout << "�͹��������˹���" << endl << endl;
}

void TestServant()
{
	//�����б�
	Luggage luggage[6];
	//����
	Clothes clothes;
	//��ʳ
	Snacks snacks;
	//��������
	FitnessEquipment fitnessEquipment;
	//���г�
	Bicycle bicycle;
	//����
	Piano piano;
	//����
	Table table;

	//�͹�
	Servant servant;

	//����
	string nameList[6] = {
		"����",
		"Τ����",
		"����",
		"����",
		"ˮһ��",
		"�Ը�"
	};

	luggage[0] = clothes;
	luggage[1] = snacks;
	luggage[2] = fitnessEquipment;
	luggage[3] = bicycle;
	luggage[4] = piano;
	luggage[5] = table;

	//�͹��������
	servant.CheckingLuggage(luggage, nameList);
	//�͹���������
	servant.HandlingLuggage(luggage);

}