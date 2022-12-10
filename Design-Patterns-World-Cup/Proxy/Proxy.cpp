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
	cout << "询问球员信息中..." << endl;
	cout << "球员信息审核成功... " << endl;
	cout << "返回药检结果 ..." << endl;
	cout << "药检结果返回成功！" << endl;
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
	cout << "球员申请查看药检结果!" << endl;
	cout << "通过中介发出申请 ..." << endl;
	cout << "药物检测中心返回申请响应 ..." << endl;
	cout << "中介联系药物检测中心..." << endl;
	result->check();
}
int testProxy()
{
	Proxy* proxy = new Proxy();
	proxy->check();
	delete proxy;
	return 0;
}
