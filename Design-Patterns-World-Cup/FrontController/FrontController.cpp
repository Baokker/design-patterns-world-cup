#include<iostream>
#include"FrontController.h"

using namespace std;

void Dispatcher::dispatch(string request)
{
	if (request == "abstractFactory")
	{
		testAbstractfactory();
	}

	else if (request == "adapter")
	{
		testAdaptor();
	}
	else if (request == "blackBoard")
	{
		testBlackBoard();
	}
	else if (request == "bridge")
	{
		testBridge();
	}
	else if (request == "builder")
	{
		testBuilder();
	}
	else if (request == "chainOfResponsibility")
	{
		testChainOfResponsibility();
	}
	else if (request == "command")
	{
		testCommand();
	}
	else if (request == "compose")
	{
		testCompose();
	}
	else if (request == "decorator")
	{
		testDecorate();
	}
	else if (request == "facade")
	{
		testFacade();
	}
	else if (request == "factoryMethod")
	{
		testFactoryMethod();
	}
	else if (request == "filter")
	{
		testFilter();
	}
	else if (request == "flyWeight")
	{
		testFlyweight();
	}
	else if (request == "interpreter")
	{
		testInterpreter();
	}
	else if (request == "iterator")
	{
		testIterator();
	}
	else if (request == "lazyInitialization")
	{
		testLazyInitialization();
	}
	else if (request == "mediator")
	{
		testMediator();
	}
	else if (request == "memento")
	{
		testMemento();
	}
	else if (request == "nullObject")
	{
		testNullObject();
	}
	else if (request == "objectPool")
	{
		testObjectPool();
	}
	else if (request == "observer")
	{
		testObserver();
	}
	else if (request == "prototype")
	{
		testPrototype();
	}
	else if (request == "proxy")
	{
		testProxy();
	}
	else if (request == "publishSubscribe")
	{
		testPublishSubscribe();
	}
	else if (request == "servant")
	{
		testServant();
	}
	else if (request == "state")
	{
		testState();
	}
	else if (request == "strategy")
	{
		testStrategy();
	}
	else if (request == "templateMethod")
	{
		testTemplateMethod();
	}
	else if (request == "transferObject")
	{
		testTransferObject();
	}
	else if (request == "visitor")
	{
		testVisitor();
	}
}

//���������ʾ
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_HBLUE);
	if (request == "compose") {
		cout << "Ϊǰ�������Ķ�Ա�ṩ���";
	}
	else if (request == "decorator") {
		cout << "Ϊÿһ����Ա����һ���Զ��������3dͷ��������ƻ�����Զ���emoji��";
	}
	else if (request == "factoryMethod") {
		cout << "���쳡��ʱ��ʹ�ù���ģʽ�����ݲ�ͬ�ͻ�������������ͬ����������";
	}
	else if (request == "filter") {
		cout << "ͳ�Ʋ�����Ա����Ϣ���������Ա��";
	}
	else if (request == "interpreter") {
		cout << "����ǰ��ʾ�й��ĸ�����Ա�Ƿ��е����������й�������ӡ��й���ʩ���ӵ�";
	}
	else if (request == "lazyInitialization") {
		cout << "���ݵĽ�������Ǹ߰��ģ�������������ӽ��죬ֱ��������ʱ�ٽ��죨���Գ�ʼģʽ��";
	}
	else if (request == "prototype") {
		cout << "���籭�����������࣬�����׵������죬���ǿ�����ԭ��ģʽ��¡";
	}
	else if (request == "strategy") {
		cout << "��ͬ�ĳ����ص��Ӧ��ͬ��·��ѡ��";
	}
	else if (request == "iterator") {
		cout << "�����������Ҵ����������ڿ������᳡�Ǽǡ�";
	}
	else if (request == "facade") {
		cout << "��Ա�ִ�����ص㣬��ʼ��ס�Ƶ�";
	}
	else if (request == "nullObject") {
		cout << "��Ļʽʱ��ʾ������Ա����ƽ��Ϣ�������ڻ�������";
	}
	else if (request == "servant") {
		cout << "����ס�Ƶ�Ĺ����У��͹���ʼΪ�˶�Ա��������";
	}
	else if (request == "adapter") {
		cout << "Ϊ�˽�����Խ������⣬���������췽����������Ҳ����������ǲ��־Ը���롣";
	}
	else if (request == "blackBoard") {
		cout << "���̰��Ž���������Ա�����Լ��ı������̣������Ͽⷢ���鿴���룬�Բ�ͬ����������ͬ��Ӧ����ʾ��������(�ڰ�ģʽ)";
	}
	else if (request == "bridge") {
		cout << "ÿ��������ʼʱ��չʾ������Ա����Ϣ��";
	}
	else if (request == "builder") {
		cout << "��Ļʽ������׼����ʼ��ʽ�ı�������ʱ��������ÿһ��������Ӧ��ʱ�䡢���ҡ����������Ϣ";
	}
	else if (request == "chainOfResponsibility") {
		cout << "���������г�����Ա���ߣ���ʼ������Ա����";
	}
	else if (request == "command") {
		cout << "�ڱ���ʱ����÷ַ�ʽ�Լ���ǰ�������";
	}
	else if (request == "observer") {
		cout << "����������Ǻ�ý��ӿ���������籭�����ֳ���ս��ȫ���ע���������ܵ�һʱ�䲶�����¶����������Ļ����ܾͻ��ʧ���ʳ��档";
	}
	else if (request == "flyWeight") {
		cout << "���籭�������Ʒ��࣬������Ԫģʽ�Ա������ͽ���������á�";
	}
	else if (request == "mediator") {
		cout << "90��120���ӵ��������Ƕ���Ա�����������˫�ؿ��飡������Ҳ��ҪȨ��ÿλ��Ա��״̬����Ҫ�滮���޵��滻��Ա�Ļ��ᣬ�������ÿһλ��Ա��������";
	}
	else if (request == "memento") {
		cout << "2022�꿨�������籭�����ð��Զ�Խλʶ����(SAOT),11��22�գ�����͢�ڶ���ɳ�ذ������ı����У�3������SAOTϵͳ�ж�ΪԽλ�����ձ���1:2����ɳ�ذ�������";
	}
	else if (request == "objectPool") {
		cout << "ÿ�����������󣬸��������Ƿ���ʣ��ı����������Ƿ���������ӷ���";
	}
	else if (request == "proxy") {
		cout << "��Աҩ����ϣ����������Ҫ�鿴ҩ���������ô���ģʽ���н鷢������:";
	}
	else if (request == "state") {
		cout << "���籭��ʽ����������������״̬ģʽ���Ա������������̽���ģ��:";
	}
	else if (request == "templateMethod") {
		cout << "ĳһ���������������ʼ!";
	}
	else if (request == "transferObject") {
		cout << "�������������������������";
	}
	else if (request == "visitor") {
		cout << "������ʼ����ʼ������Ҫ�����½��";
	}
	else if (request == "abstractFactory") {
		cout << "��ʽ������ʼǰ������ÿ�����ҶӵĹ�������¡����Կ���׼���׶εĹ�����Ҳ���Կ���ÿһ�����������ʼ֮ǰ�Ĺ����������ģʽ��Ŀ���������������ĸ������С�";
	}
	else if (request == "publishSubscribe") {
		cout << "�ܶ�������Ϊ����ԭ�򣬲������ۼ�֤��������������ͨ������һЩƵ������ȡ���Ǹ���Ȥ�����½�չ��";
	}

	cct_setcolor();
}

void FrontController::trackRequest(string request)
{
	string originRequest = request;
	if (request == "observer") {
		request += " && singleton";
	}
	else if (request == "memento") {
		request += " && singleton";
	}
	else if (request == "publishSubscribe") {
		request += " && singleton";
	}
	else if (request == "templateMethod") {
		request += " && RAII";
	}

	//���������ʾ
	cout << "---------------------------------------------------------------------------\n\n";
	outputScene(originRequest);
	cout << "\n";

	//������ģʽ��ʾ
	cct_setcolor(COLOR_BLACK, COLOR_HGREEN);
	cout << "design pattern request:" << request << endl;
	cct_setcolor();
}

void FrontController::set(Dispatcher* d)
{
	dispatcher = d;
}

void FrontController::dispatchRequest(string request)
{
	trackRequest(request);
	dispatcher->dispatch(request);
}

void testAll() {
	while (1) {
		cct_cls();
		for (int i = 0; i < 30; i++) {
			string request = designPatterns[i];
			if (request == "observer") {
				request += " && singleton";
			}
			else if (request == "memento") {
				request += " && singleton";
			}
			else if (request == "publishSubscribe") {
				request += " && singleton";
			}
			else if (request == "templateMethod") {
				request += " && RAII";
			}
			cout << i << "." << request << endl;
		}
		cout << "30.�˳�\n";
		cout << "���������ģʽ��Ӧ���:";
		int index;
		cin >> index;
		if (index == 30) {
			break;
		}
		FrontController frontController;
		frontController.dispatchRequest(designPatterns[index]);
		system("pause");
	}
}
