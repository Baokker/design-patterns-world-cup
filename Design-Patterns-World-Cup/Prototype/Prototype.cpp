#include"Prototype.h"

void PrototypeClient(PrototypeFactory& prototype_factory) {
	std::cout << "������������һ��2018�����˹�����籭����Telstar 18\n";

	Football* f1 = prototype_factory.CreatePrototype(Type::TELSTAR18);
	f1->show();
	delete f1;

	std::cout << "\n";

	std::cout << "��������������һ��2022�꿨���������籭����ALRIHLA\n";

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