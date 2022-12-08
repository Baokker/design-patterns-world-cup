#include"Prototype.h"

void PrototypeClient(PrototypeFactory& prototype_factory) {
	std::cout << "让我们来生产一个2018年俄罗斯的世界杯足球Telstar 18\n";

	Football* f1 = prototype_factory.CreatePrototype(Type::TELSTAR18);
	f1->show();
	delete f1;

	std::cout << "\n";

	std::cout << "让我们再来生产一个2022年卡塔尔的世界杯足球ALRIHLA\n";

	f1 = prototype_factory.CreatePrototype(Type::ALRIHLA);
	f1->show();

	delete f1;
}

void testPrototype() {
	PrototypeFactory* prototype_factory = new PrototypeFactory();
	PrototypeClient(*prototype_factory);
	delete prototype_factory;

	return;
}