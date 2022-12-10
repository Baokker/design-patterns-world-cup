#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;


class PlayerFilter {

private :
    string name;
    string gender;
    int age;

public:
    PlayerFilter(string name, string gender, int age ) {
        this->name = name;
        this->gender = gender;
        this->age = age;
    }

    string getName() {
        return name;
    }
    string getGender() {
        return gender;
    }
    int getAge() {
        return age;
    }
    
};

class Filter {
public:
    Filter() {}
    virtual list<PlayerFilter> meetFilter(list<PlayerFilter>& players) { 
        list<PlayerFilter> lis;
        return lis;
    }
};

class FilterMale : public Filter {
protected:
    string criteria_ = "Male";
public:
    list<PlayerFilter> meetFilter(list<PlayerFilter>& players) override
    {
        list<PlayerFilter> malePersons;
        for (PlayerFilter player : players) {
            if (player.getGender() == this->criteria_) {
                malePersons.push_back(player);
            }
        }
        return malePersons;
    }
};

class FilterFemale : public Filter {
protected:
    string criteria_ = "Female";
public:
    list<PlayerFilter> meetFilter(list<PlayerFilter>& players) override
    {
        list<PlayerFilter> femalePersons;
        for (PlayerFilter player : players) {
            if (player.getGender() == this->criteria_) {
                femalePersons.push_back(player);
            }
        }
        return femalePersons;
    }
};

class FilterAge : public Filter
{
private:
    int age;
    bool greater = false;
public:
    FilterAge(int age, bool greater = false)
    {
        this->age = age;
        this->greater = greater;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    list<PlayerFilter> meetFilter(list<PlayerFilter>& players) override
    {
        if (greater) {
            return greaterFilter(players, this->age);
        }
        else {
            return lessFilter(players, this->age);
        }
    }

    list<PlayerFilter> greaterFilter(list<PlayerFilter> players, int age)
    {
        list<PlayerFilter> result;
        for (PlayerFilter player : players) {
            if (player.getAge() > age) {
                result.push_back(player);
            }
        }
        return result;
    }

    list<PlayerFilter> lessFilter(list<PlayerFilter> players, int age)
    {
        list<PlayerFilter> result;
        for (PlayerFilter player : players) {
            if (player.getAge() < age) {
                result.push_back(player);
            }
        }
        return result;
    }
};
class AndOperation : public Filter {

private:
    Filter filter_;
    Filter otherFilter_;

public:
    AndOperation(Filter filter, Filter otherFilter) {
        this->filter_ = filter;
        this->otherFilter_ = otherFilter;
    }

public:
    list<PlayerFilter> meetFilter(list<PlayerFilter>& players) override
    {
        list<PlayerFilter> firstCriteriaPersons = filter_.meetFilter(players);
        return otherFilter_.meetFilter(firstCriteriaPersons);
    }
};


class OrOperation : public Filter {

private:
    Filter filter_;
    Filter otherFilter_;

    bool hasItem(list<PlayerFilter> set, PlayerFilter target)
    {
        for (PlayerFilter player : set) {
            if (player.getName() == target.getName()) {
                return true;
            }
        }
        return false;
    }

public:
    OrOperation(Filter filter, Filter otherFilter) {
        this->filter_ = filter;
        this->otherFilter_ = otherFilter;
    }


public:
    list<PlayerFilter> meetFilter(list<PlayerFilter>& players) override
    {
        list<PlayerFilter> firstFilterItems = filter_.meetFilter(players);
        list<PlayerFilter> otherFilterItems = otherFilter_.meetFilter(players);

        for (PlayerFilter player : otherFilterItems) {
            if (!hasItem(firstFilterItems, player)) {
                firstFilterItems.push_back(player);
            }
        }
        return firstFilterItems;
    }
};

void testFilter();
void printFiletr(list<PlayerFilter> players);