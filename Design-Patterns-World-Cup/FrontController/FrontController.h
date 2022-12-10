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

	//世界杯开幕前建设阶段的几个设计模式
	"compose", //队员到了之后提供礼包
	"decorator",//与实际比赛流程割裂
	"factoryMethod",//建造场馆运送物流时采取不同的物流
	"filter", //与实际比赛割裂
	"interpreter", //比赛前显示中国的各种人员是否有到来，比如中国的足球队、中国的施工队等
	"lazyInitialization", //建造场馆
	"prototype", //生产不同的足球
	"strategy",//比赛前的出发（可能是最先的一个设计模式）

	//世界杯开幕式期间的相关设计模式
	"iterator",// 各个参赛国家代表团依次在卡塔尔会场登记
	"facade",//在比赛之前运动员入住酒店并登记并核酸检测
	"nullObject", //开幕式时显示若干球员的生平信息，类似于基本介绍
	"servant", //比赛之前雇工给运动员搬运行李

	//世界杯比赛期间的相关设计模式
	"adapter",//场外翻译
	"blackBoard", //比赛中，球员查看各自赛程
	"bridge",//运动员、教练、志愿者自我介绍
	"builder",//产生举办每一场比赛的信息
	"chainOfResponsibility", //在比赛过程中处理球员上诉
	"command", //在比赛时输出得分方式以及当前分数情况
	"observer",//赛事官方改变积分排名情况并通知观众或媒体(Observer)
	"flyWeight", //比赛赛程和赛制的制定
	"mediator",//球员发送信号，通过主教练(Mediator)进行队员上下场替换
	"memento",  // 一场比赛中出现进球并在 SAOT 判定为越位后撤销加分操作
	"objectPool", //生产不同国家的队服、国旗后保留至该队没有剩余比赛
	"proxy",//比赛过程中处理查看药检结果的事务
	"state",//在整个世界杯赛程中，从小组赛到淘汰赛再到最终决赛的赛程进度转变
	"templateMethod",//举办比赛：小组赛，半决赛，决赛
	"transferObject",//比赛过程中输出各国观众数量
	"visitor",//在比赛过程中播报比赛

	//其他
	"abstractFactory",  //生产不同国家的队服、国旗
	"publishSubscribe", //观众(Subscriber)并通过频道或过滤器(Channel)获取赛事官方(Publisher)发布的各队伍积分变化或赛程安排

	//下面所有设计模式被合并到其他设计模式测试函数中
	"frontController", 
	"RAII",  //每次比赛后清理比赛场地
	"singleton" //对积分排名使用单例模式，在访问积分排名时，访问其一个实例
};
//, "privateClassData";考虑删除的多余设计模式

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