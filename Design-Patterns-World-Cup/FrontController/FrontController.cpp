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

//输出场景提示
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_HBLUE);
	if (request == "compose") {
		cout << "为前来参赛的队员提供礼包";
	}
	else if (request == "decorator") {
		cout << "为每一个球员生成一个自定义虚拟的3d头像（类似于苹果的自定义emoji）";
	}
	else if (request == "factoryMethod") {
		cout << "建造场馆时，使用工厂模式，根据不同客户的需求，生产不同的物流工具";
	}
	else if (request == "filter") {
		cout << "统计参赛队员的信息，如年龄性别等";
	}
	else if (request == "interpreter") {
		cout << "比赛前显示中国的各种人员是否有到来，比如中国的足球队、中国的施工队等";
	}
	else if (request == "lazyInitialization") {
		cout << "场馆的建造代价是高昂的，因此我们先拖延建造，直到有需求时再建造（惰性初始模式）";
	}
	else if (request == "prototype") {
		cout << "世界杯的足球花样繁多，不容易单独制造，但是可以用原型模式克隆";
	}
	else if (request == "strategy") {
		cout << "不同的出发地点对应不同的路线选择";
	}
	else if (request == "iterator") {
		cout << "各个参赛国家代表团依次在卡塔尔会场登记。";
	}
	else if (request == "facade") {
		cout << "球员抵达比赛地点，开始入住酒店";
	}
	else if (request == "nullObject") {
		cout << "开幕式时显示若干球员的生平信息，类似于基本介绍";
	}
	else if (request == "servant") {
		cout << "在入住酒店的过程中，雇工开始为运动员搬运行李";
	}
	else if (request == "adapter") {
		cout << "为了解决语言交流问题，卡塔尔主办方已向各个国家参赛队伍队派遣了志愿翻译。";
	}
	else if (request == "blackBoard") {
		cout << "赛程安排结束，各球员关心自己的比赛赛程，向资料库发出查看申请，对不同申请作出不同回应，显示各自赛程(黑板模式)";
	}
	else if (request == "bridge") {
		cout << "每场比赛开始时，展示明星球员的信息。";
	}
	else if (request == "builder") {
		cout << "开幕式结束后，准备开始正式的比赛，此时用于生成每一场比赛对应的时间、国家、裁判组等信息";
	}
	else if (request == "chainOfResponsibility") {
		cout << "比赛过程中出现球员上诉，开始处理球员上诉";
	}
	else if (request == "command") {
		cout << "在比赛时输出得分方式以及当前分数情况";
	}
	else if (request == "observer") {
		cout << "热情的球迷们和媒体涌向卡塔尔世界杯比赛现场观战，全神贯注的球迷总能第一时间捕获赛事动向，如果走神的话可能就会错失精彩场面。";
	}
	else if (request == "flyWeight") {
		cout << "世界杯比赛赛制繁多，采用享元模式对比赛类型进行添加设置。";
	}
	else if (request == "mediator") {
		cout << "90到120分钟的足球赛是对球员体力和心理的双重考验！主教练也需要权衡每位球员的状态，还要规划有限的替换球员的机会，充分利用每一位球员的耐力。";
	}
	else if (request == "memento") {
		cout << "2022年卡塔尔世界杯将启用半自动越位识别技术(SAOT),11月22日，阿根廷在对阵沙特阿拉伯的比赛中，3粒进球被SAOT系统判定为越位，最终爆冷1:2负于沙特阿拉伯。";
	}
	else if (request == "objectPool") {
		cout << "每场比赛结束后，根据两队是否还有剩余的比赛来决定是否保留国旗与队服。";
	}
	else if (request == "proxy") {
		cout << "球员药检完毕，各大机构需要查看药检结果，采用代理模式向中介发出申请:";
	}
	else if (request == "state") {
		cout << "世界杯正式开赛！接下来采用状态模式，对比赛的整个过程进行模拟:";
	}
	else if (request == "templateMethod") {
		cout << "某一场足球比赛即将开始!";
	}
	else if (request == "transferObject") {
		cout << "比赛过程中输出各国观众数量";
	}
	else if (request == "visitor") {
		cout << "比赛开始，开始播报重要的赛事结果";
	}
	else if (request == "abstractFactory") {
		cout << "正式比赛开始前，生产每个国家队的国旗和球衣。可以看作准备阶段的工作，也可以看作每一场具体比赛开始之前的工作，请根据模式数目情况决定具体放在哪个场景中。";
	}
	else if (request == "publishSubscribe") {
		cout << "很多球迷因为种种原因，不能亲眼见证比赛，于是他们通过订阅一些频道，获取他们感兴趣的赛事进展。";
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

	//输出场景提示
	cout << "---------------------------------------------------------------------------\n\n";
	outputScene(originRequest);
	cout << "\n";

	//输出设计模式提示
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
		cout << "30.退出\n";
		cout << "请输入测试模式对应序号:";
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
