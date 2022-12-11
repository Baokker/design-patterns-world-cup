#include "Compose.h"

void composeClientCode(Component* component) {
    std::cout << "RESULT: " << component->Operation();
}


int testCompose() {

    Component* tree = new Composite;
    Component* container1 = new Composite;

    Component* item1 = new Item(std::string("运动耳机"));
    Component* item2 = new Item(std::string("三星手机"));
    Component* item3 = new Item(std::string("水杯防滑套"));
    Component* item4 = new Item(std::string("运动水杯"));
    Component* item5 = new Item(std::string("纪念品挂件"));
    
    container1->Add(item1);
    container1->Add(item2);

    Component* container2 = new Composite;
    container2->Add(item3);
    container2->Add(item4);

    tree->Add(container1);
    tree->Add(container2);
    tree->Add(item5);
    std::cout << "为球员准备的礼包为：\n";
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