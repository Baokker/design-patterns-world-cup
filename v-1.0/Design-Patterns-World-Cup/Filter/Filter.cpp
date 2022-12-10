#include "Filter.h"

void testFilter()
{
    list<PlayerFilter> players;
    PlayerFilter player1("Robert", "Male", 18);
    PlayerFilter player2("John", "Male", 20);
    PlayerFilter player3("Laura", "Female", 31);
    PlayerFilter player4("Diana", "Female", 38);
    PlayerFilter player5("Mike", "Male", 25);
    PlayerFilter player6("Bobby", "Male", 29);
    PlayerFilter player7("Alex", "Male", 24);
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    players.push_back(player4);
    players.push_back(player5);
    players.push_back(player6);


    Filter* male = new FilterMale();
    Filter* female = new FilterFemale();
    Filter* filterAge1 = new FilterAge(20, true);
    Filter* filterAge2 = new FilterAge(30, false);
    Filter* maleLessTwenty = new AndOperation(*filterAge1, *male);
    Filter* femaleGreaterTwenty = new OrOperation(*filterAge2, *female);

    std::cout << "������Ա��\n";
    printFiletr(male->meetFilter(players));

    std::cout << "Ů����Ա��\n";
    printFiletr(female->meetFilter(players));

    cout << "����20�����Ա��\n";
    printFiletr(filterAge1->meetFilter(players));

    cout << "С��30�����Ա��\n";
    printFiletr(filterAge2->meetFilter(players));

    delete male;
    delete female;
    delete filterAge1;
    delete filterAge2;
    delete maleLessTwenty;
    delete femaleGreaterTwenty;
}

void printFiletr(list<PlayerFilter> players)
{
    for (PlayerFilter player : players)
    {
        std::cout << "Person : [ Name : " << player.getName()
            << ", Gender : " << player.getGender()
            << ", Age : " << player.getAge()
            << " ] \n";
    }
}