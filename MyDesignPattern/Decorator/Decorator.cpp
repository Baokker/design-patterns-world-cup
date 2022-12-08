#include "Decorator.h"

void DecorateResult(Player* component) {
    std::cout << "(" << component->Operation() << ")";
}


void testDecorate()
{
    Player* player1 = new ConcretePlayer("Alex");
    std::cout << player1->getName() << "��ʼ�����Լ��������ɫ��\n";
    
    Player* decorator1 = new BlackHair(player1);
    Player* decorator2 = new YellowSkin(decorator1);
    Player* decorator3 = new StraightHair(decorator2);
    std::cout << "����װ�κ�Ľ�ɫ��\n";
    DecorateResult(decorator3);
    std::cout << "\n";

    delete player1;
    delete decorator1;
    delete decorator2;
    delete decorator3;

    Player* player2 = new ConcretePlayer("Tom");
    std::cout << player2->getName() << "��ʼ�����Լ��������ɫ��\n";

    Player* decorator4 = new YellowHair(player2);
    Player* decorator5 = new BlackSkin(decorator4);
    Player* decorator6 = new CurlyHair(decorator5);
    std::cout << "����װ�κ�Ľ�ɫ��\n";
    DecorateResult(decorator6);
    std::cout << "\n";
    return;
}