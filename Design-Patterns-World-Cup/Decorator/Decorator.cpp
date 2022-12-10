#include "Decorator.h"

void DecorateResult(PlayerDecorator* component) {
    std::cout << "(" << component->Operation() << ")";
}


void testDecorate()
{
    PlayerDecorator* player1 = new ConcretePlayerDecorator("Alex");
    std::cout << player1->getName() << "��ʼ�����Լ��������ɫ��\n";
    
    PlayerDecorator* decorator1 = new BlackHair(player1);
    PlayerDecorator* decorator2 = new YellowSkin(decorator1);
    PlayerDecorator* decorator3 = new StraightHair(decorator2);
    std::cout << "����װ�κ�Ľ�ɫ��\n";
    DecorateResult(decorator3);
    std::cout << "\n";

    delete player1;
    delete decorator1;
    delete decorator2;
    delete decorator3;

    PlayerDecorator* player2 = new ConcretePlayerDecorator("Tom");
    std::cout << player2->getName() << "��ʼ�����Լ��������ɫ��\n";

    PlayerDecorator* decorator4 = new YellowHair(player2);
    PlayerDecorator* decorator5 = new BlackSkin(decorator4);
    PlayerDecorator* decorator6 = new CurlyHair(decorator5);
    std::cout << "����װ�κ�Ľ�ɫ��\n";
    DecorateResult(decorator6);
    std::cout << "\n";
    return;
}