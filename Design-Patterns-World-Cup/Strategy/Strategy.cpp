#include "Strategy.h"

void testStrategy()
{
    Strategy* strategyAriplane = new Airplane;
    Strategy* strategyBoat = new Boat;

    Navigator nav1("A", strategyAriplane);
    std::cout << "���ú��յ�·��\n";
    nav1.findWay();

    std::cout << "\n";
    std::cout << "�����·��\n\n";
    nav1.setStrategy(strategyBoat);
    std::cout << "���ö��֣�\n";
    nav1.findWay();

    std::cout << "\n";

    Navigator nav2("B", strategyAriplane);
    std::cout << "���ú��յ�·��\n";
    nav2.findWay();

    std::cout << "\n";
    std::cout << "�����·��\n\n";
    nav2.setStrategy(strategyBoat);
    std::cout << "���ö��֣�\n";
    nav2.findWay();

    delete strategyAriplane;
    delete strategyBoat;
}