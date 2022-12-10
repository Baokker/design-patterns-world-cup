#include "NullObject.h"

//实现放在头文件中会发生重复定义，并报错
string NullObjectPlayerFactory::name[PLAYER_NUM] = {
	"韦世豪",
	"隋维杰",
	"梅西"
};

string NullObjectPlayerFactory::info[PLAYER_NUM] = {
	"2017年首次入选男足国家队。2017年12月9日，在东亚杯比赛代表国家队首秀破门，最终国足2-2战平韩国。2019年1月5日，入选2019年阿联酋亚洲杯最终23人大名单。2020年1月，韦世豪入选联赛优秀中国籍球员技术档案库。",
	"2015年05年24日，中超的一场“保级战”出现了一个奇葩进球，辽足在最后时刻与重庆队战平，秦升快发任意球，丁海峰破门，而此时镜头中力帆门将隋维杰竟然还在悠闲的喝水。",
	"全名利昂内尔·安德烈斯·梅西·库西蒂尼（Lionel Andrés Messi Cuccitini），昵称莱奥·梅西（Leo Messi），1987年6月24日出生于阿根廷圣菲省罗萨里奥，阿根廷职业足球运动员，司职前锋，现效力于法国足球甲级联赛的巴黎圣日耳曼足球俱乐部"
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
	cout << "测试空对象模型（Null Object）" << endl;
	NullObjectAbstractPlayer* c1 = NullObjectPlayerFactory::getPlayer("韦世豪");
	NullObjectAbstractPlayer* c2 = NullObjectPlayerFactory::getPlayer("隋维杰");
	NullObjectAbstractPlayer* c3 = NullObjectPlayerFactory::getPlayer("梅西");
	NullObjectAbstractPlayer* c4 = NullObjectPlayerFactory::getPlayer("姚明");
	//cout << "======================================" << endl;
	cout << endl;
	cout << "韦世豪: " << c1->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "隋维杰: " << c2->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "梅西: " << c3->getInfo() << endl;
	//cout << "======================================" << endl;
	cout << endl;
	cout << "姚明: " << c4->getInfo() << endl;
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