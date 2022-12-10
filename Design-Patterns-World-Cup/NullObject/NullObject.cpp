#include "NullObject.h"

//ʵ�ַ���ͷ�ļ��лᷢ���ظ����壬������
string NullObjectPlayerFactory::name[PLAYER_NUM] = {
	"Τ����",
	"��ά��",
	"÷��"
};

string NullObjectPlayerFactory::info[PLAYER_NUM] = {
	"2017���״���ѡ������Ҷӡ�2017��12��9�գ��ڶ��Ǳ�����������Ҷ��������ţ����չ���2-2սƽ������2019��1��5�գ���ѡ2019�갢�������ޱ�����23�˴�������2020��1�£�Τ������ѡ���������й�����Ա���������⡣",
	"2015��05��24�գ��г���һ��������ս��������һ������������������ʱ���������սƽ�������췢�����򣬶��������ţ�����ʱ��ͷ�������Ž���ά�ܾ�Ȼ�������еĺ�ˮ��",
	"ȫ�������ڶ���������˹��÷�����������ᣨLionel Andr��s Messi Cuccitini�����ǳ����¡�÷����Leo Messi����1987��6��24�ճ����ڰ���͢ʥ��ʡ������£�����ְ͢ҵ�����˶�Ա��˾ְǰ�棬��Ч���ڷ�������׼������İ���ʥ�ն���������ֲ�"
};

NullObjectAbstractPlayer* NullObjectPlayerFactory::getPlayer(string inName)
{
	int i = 0;
	for (i = 0; i < PLAYER_NUM; i++)
	{
		if (name[i] == inName)
		{
			return (NullObjectAbstractPlayer*)new NullObjectRealPlayer(info[i]);
		}
	}
	return (NullObjectAbstractPlayer*)new NullObjectNullPlayer();
}


void testNullObject() {
	cout << "���Կն���ģ�ͣ�Null Object��" << endl;
	NullObjectAbstractPlayer* c1 = NullObjectPlayerFactory::getPlayer("Τ����");
	NullObjectAbstractPlayer* c2 = NullObjectPlayerFactory::getPlayer("��ά��");
	NullObjectAbstractPlayer* c3 = NullObjectPlayerFactory::getPlayer("÷��");
	NullObjectAbstractPlayer* c4 = NullObjectPlayerFactory::getPlayer("Ҧ��");
	//cout << "======================================" << endl;
	cout << endl;
	cout << "Τ����: " << c1->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "��ά��: " << c2->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "÷��: " << c3->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "Ҧ��: " << c4->getInfo() << endl;
	//cout << "======================================" << endl;

	delete c1;
	c1 = NULL;

	delete c2;
	c2 = NULL;

	delete c3;
	c3 = NULL;

	delete c4;
	c4 = NULL;
}

//void main() {
//	testNullObject();
//}