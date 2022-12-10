#include"LazyInitialization.h"

// 设为静态类型
map<string, Venue*> Venue::types;

Venue* Venue::getVenue(const string& name) {
	Venue*& v = types[name];   // 尝试在map中获取 如果没有就新建一个

	if (!v) {                   // 如果是NULL
		v = new Venue(name); // 惰性初始
	}
	return v;
}

/*
 * 查看情况
 */
void Venue::printCurrentTypes() {
	if (!types.empty()) {
		cout << "已建造场馆" << types.size() << "个" << endl;
		for (map<string, Venue*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
			cout << (*iter).first << " ";
		}
		cout << endl;
	}
}

void testLazyInitialization() {
	Venue::getVenue("艾哈迈德本阿里体育场（Ahmad Bin Ali Stadium）");
	Venue::printCurrentTypes();

	Venue::getVenue("海湾球场 (Al Bayt Stadium)");
	Venue::printCurrentTypes();

	Venue::getVenue("贾努布球场 （Al Janoub Stadium）");
	Venue::printCurrentTypes();

	return;
}