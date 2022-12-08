#include"FactoryMethod.h"

void FactoryClientCode(const Person& person) {
    cout << "�Ҳ���֪�����������Ĺ��ˣ�����֪�������ҽ��������" << std::endl
        << person.show() << std::endl;
}

void testFactoryMethod() {
    std::cout << "������1���й���\n";
    Person* chinaPerson = new ChinaPerson();
    FactoryClientCode(*chinaPerson);
    std::cout << std::endl;
    std::cout << "������2��������\n";
    Person* americaPerson = new AmericaPerson();
    FactoryClientCode(*americaPerson);
    std::cout << std::endl;
    std::cout << "������3����������\n";
    Person* arabPerson = new ArabPerson();
    FactoryClientCode(*arabPerson);
    std::cout << std::endl;
    delete chinaPerson;
    delete americaPerson;
    delete arabPerson;
    return;
}