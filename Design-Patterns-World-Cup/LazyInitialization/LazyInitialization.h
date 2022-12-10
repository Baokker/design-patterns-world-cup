#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

// ³¡¹Ý
class Venue {
public:
    static Venue* getVenue(const string& name);
    static void printCurrentTypes();

private:
    static map<string, Venue*> types;
    string name;

    Venue(const string& n) : name(n) {}
};

void testLazyInitialization();