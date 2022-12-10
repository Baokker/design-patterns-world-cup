#pragma once
#ifndef _PROXY_H_
#define _PROXY_H_
//subject
class PlayersDrugTest
{
public:
	virtual ~PlayersDrugTest();
	PlayersDrugTest();
	virtual void check() = 0;
};
//real subject
class PlayersDrugTestResult :public PlayersDrugTest
{
public:
	PlayersDrugTestResult();
	virtual ~PlayersDrugTestResult();
	void check();
};
class Proxy :public PlayersDrugTest
{
public:
	virtual ~Proxy();
	Proxy();
	void check();
private:
	PlayersDrugTestResult* result;
};

int testProxy();
#endif // !_PROXY_H_