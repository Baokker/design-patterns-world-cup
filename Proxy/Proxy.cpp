#include"Proxy.h"
#include<iostream>
using namespace std;
/*
	in this pattern,Olympic Drug Testing Center as the pointer, olympian as proxy
*/
PlayersDrugTest::PlayersDrugTest() {}
PlayersDrugTest::~PlayersDrugTest() {}
PlayersDrugTestResult::PlayersDrugTestResult() {}
PlayersDrugTestResult::~PlayersDrugTestResult() {}
void PlayersDrugTestResult::check()
{
	cout << "ѯ����Ա��Ϣ��..." << endl;
	cout << "��Ա��Ϣ��˳ɹ�... " << endl;
	cout << "����ҩ���� ..." << endl;
	cout << "ҩ�������سɹ���" << endl;
}
Proxy::Proxy()
{
	result = new PlayersDrugTestResult();
}
Proxy::~Proxy()
{
	delete result;
}
void Proxy::check()
{
	cout << "��Ա����鿴ҩ����!" << endl;
	cout << "ͨ���н鷢������ ..." << endl;
	cout << "ҩ�������ķ���������Ӧ ..." << endl;
	cout << "�н���ϵҩ��������..." << endl;
	result->check();
}
int testProxy()
{
	Proxy* proxy = new Proxy();
	proxy->check();
	delete proxy;
	return 0;
}
