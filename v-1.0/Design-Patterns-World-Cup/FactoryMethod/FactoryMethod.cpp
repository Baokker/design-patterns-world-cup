#include"FactoryMethod.h"

void FactoryClientCode(const Person& person) {
    cout << "我并不知道创建者是哪国人，但我知道他帮我解决了物流" << std::endl
        << person.show() << std::endl;
}

void testFactoryMethod() {
    std::cout << "创建人1：中国人\n";
    Person* chinaPerson = new ChinaPerson();
    FactoryClientCode(*chinaPerson);
    std::cout << std::endl;
    std::cout << "创建人2：美国人\n";
    Person* americaPerson = new AmericaPerson();
    FactoryClientCode(*americaPerson);
    std::cout << std::endl;
    std::cout << "创建人3：阿拉伯人\n";
    Person* arabPerson = new ArabPerson();
    FactoryClientCode(*arabPerson);
    std::cout << std::endl;
    delete chinaPerson;
    delete americaPerson;
    delete arabPerson;
    return;
}