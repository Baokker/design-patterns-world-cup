#include "Strategy.h"

void testStrategy()
{
    Strategy* strategyAriplane = new Airplane;
    Strategy* strategyBoat = new Boat;

    Navigator nav1("A", strategyAriplane);
    std::cout << "采用航空道路：\n";
    nav1.findWay();

    std::cout << "\n";
    std::cout << "重设道路：\n\n";
    nav1.setStrategy(strategyBoat);
    std::cout << "采用渡轮：\n";
    nav1.findWay();

    std::cout << "\n";

    Navigator nav2("B", strategyAriplane);
    std::cout << "采用航空道路：\n";
    nav2.findWay();

    std::cout << "\n";
    std::cout << "重设道路：\n\n";
    nav2.setStrategy(strategyBoat);
    std::cout << "采用渡轮：\n";
    nav2.findWay();

    delete strategyAriplane;
    delete strategyBoat;
}