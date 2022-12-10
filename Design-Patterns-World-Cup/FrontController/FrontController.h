#pragma once
#include<iostream>
#include"../AbstractFactory/AbstractFactory.h"
#include"../Adapter/Adapter.h"
#include"../BlackBoard/BlackBoard.h"
#include"../Bridge/Bridge.h"
#include"../Builder/Builder.h"
#include"../ChainOfResponsibility/ChainOfResponsibility.h"
#include"../Command/Command.h"
#include"../Compose/Compose.h"
#include"../Decorator/Decorator.h"
#include"../Facade/Facade.h"
#include"../FactoryMethod/FactoryMethod.h"
#include"../Filter/Filter.h"
#include"../Flyweight/Flyweight.h"
#include"../Interpreter/Interpreter.h"
#include"../Iterator/Iterator.h"
#include"../LazyInitialization/LazyInitialization.h"
#include"../Mediator/Mediator.h"
#include"../Memento/Memento.h"
#include"../NullObject/NullObject.h"
#include"../ObjectPool/ObjectPool.h"
#include"../Observer/Observer.h"
#include"../Prototype/Prototype.h"
#include"../Proxy/Proxy.h"
#include"../PublishSubscribe/PublishSubscribe.h"
#include"../RAII/RAII.h"
#include"../Servant/Servant.h"
#include"../State/State.h"
#include"../Strategy/Strategy.h"
#include"../TemplateMethod/TemplateMethod.h"
#include"../TransferObject/TransferObject.h"
#include"../Visitor/Visitor.h"
#include"../utils/cct_tools.h"

using namespace std;

const string designPatterns[33] = {

	//���籭��Ļǰ����׶εļ������ģʽ
	"compose", //��Ա����֮���ṩ���
	"decorator",//��ʵ�ʱ������̸���
	"factoryMethod",//���쳡����������ʱ��ȡ��ͬ������
	"filter", //��ʵ�ʱ�������
	"interpreter", //����ǰ��ʾ�й��ĸ�����Ա�Ƿ��е����������й�������ӡ��й���ʩ���ӵ�
	"lazyInitialization", //���쳡��
	"prototype", //������ͬ������
	"strategy",//����ǰ�ĳ��������������ȵ�һ�����ģʽ��

	//���籭��Ļʽ�ڼ��������ģʽ
	"iterator",// �����������Ҵ����������ڿ������᳡�Ǽ�
	"facade",//�ڱ���֮ǰ�˶�Ա��ס�Ƶ겢�Ǽǲ�������
	"nullObject", //��Ļʽʱ��ʾ������Ա����ƽ��Ϣ�������ڻ�������
	"servant", //����֮ǰ�͹����˶�Ա��������

	//���籭�����ڼ��������ģʽ
	"adapter",//���ⷭ��
	"blackBoard", //�����У���Ա�鿴��������
	"bridge",//�˶�Ա��������־Ը�����ҽ���
	"builder",//�����ٰ�ÿһ����������Ϣ
	"chainOfResponsibility", //�ڱ��������д�����Ա����
	"command", //�ڱ���ʱ����÷ַ�ʽ�Լ���ǰ�������
	"observer",//���¹ٷ��ı�������������֪ͨ���ڻ�ý��(Observer)
	"flyWeight", //�������̺����Ƶ��ƶ�
	"mediator",//��Ա�����źţ�ͨ��������(Mediator)���ж�Ա���³��滻
	"memento",  // һ�������г��ֽ����� SAOT �ж�ΪԽλ�����ӷֲ���
	"objectPool", //������ͬ���ҵĶӷ�������������ö�û��ʣ�����
	"proxy",//���������д���鿴ҩ����������
	"state",//���������籭�����У���С��������̭���ٵ����վ��������̽���ת��
	"templateMethod",//�ٰ������С�����������������
	"transferObject",//�������������������������
	"visitor",//�ڱ��������в�������

	//����
	"abstractFactory",  //������ͬ���ҵĶӷ�������
	"publishSubscribe", //����(Subscriber)��ͨ��Ƶ���������(Channel)��ȡ���¹ٷ�(Publisher)�����ĸ�������ֱ仯�����̰���

	//�����������ģʽ���ϲ����������ģʽ���Ժ�����
	"frontController", 
	"RAII",  //ÿ�α����������������
	"singleton" //�Ի�������ʹ�õ���ģʽ���ڷ��ʻ�������ʱ��������һ��ʵ��
};
//, "privateClassData";����ɾ���Ķ������ģʽ

class Dispatcher
{
public:
	Dispatcher() {}

	void dispatch(string request);
};

class FrontController
{
private:
	Dispatcher* dispatcher;

	void trackRequest(string request);
public:
	FrontController() : dispatcher() {}

	void set(Dispatcher* d);

	void dispatchRequest(string request);
};

void testAll();