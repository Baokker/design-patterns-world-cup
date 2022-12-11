#include "Compose.h"

void composeClientCode(Component* component) {
    std::cout << "RESULT: " << component->Operation();
}


int testCompose() {

    Component* tree = new Composite;
    Component* container1 = new Composite;

    Component* item1 = new Item(std::string("�˶�����"));
    Component* item2 = new Item(std::string("�����ֻ�"));
    Component* item3 = new Item(std::string("ˮ��������"));
    Component* item4 = new Item(std::string("�˶�ˮ��"));
    Component* item5 = new Item(std::string("����Ʒ�Ҽ�"));
    
    container1->Add(item1);
    container1->Add(item2);

    Component* container2 = new Composite;
    container2->Add(item3);
    container2->Add(item4);

    tree->Add(container1);
    tree->Add(container2);
    tree->Add(item5);
    std::cout << "Ϊ��Ա׼�������Ϊ��\n";
    composeClientCode(tree);
    std::cout << "\n\n";


    delete tree;
    delete container1;
    delete container2;
    delete item1;
    delete item2;
    delete item3;
    delete item4;
    delete item5;

    return 0;
}