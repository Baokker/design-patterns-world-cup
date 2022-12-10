
//
// Created by wlf on 2022/12/7.
//

#include <iostream>
#include <vector>
#include<string>
#include <cstdlib>
#include <windows.h>
using std::string;
using std::cout;
using std::cin;
class Iterator;
class ConcreteAggregate;
class Delegation1
{
private:
    string nation;//�������ҵ���
    int playerNum;//�˶�Ա����
    int order;//enter order
public:
    Delegation1()
    {
        this->playerNum = 0;
        this->order = 0;
    }
    void setValue(string nation, int num1, int num2)
    {
        this->nation = nation;
        this->playerNum = num1;
        this->order = num2;
    }
    void declare()
    {
        cout << "��" << this->order << "�ǼǵĶ�����" << this->nation << "�ӣ�";
        cout << "������Ա��" << this->playerNum << "�ˡ�" << std::endl;
    }
};
/*
 * Aggregate
 * defines an interface for aggregates and it decouples your
 * client from the implementation of your collection of objects
 */
class Aggregate
{
public:
    virtual ~Aggregate() {}

    virtual Iterator* createIterator() = 0;
    // ...
};

/*
 * Concrete Aggregate
 * has a collection of objects and implements the method
 * that returns an Iterator for its collection
 *
 */
 //���˴�������
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(unsigned int size)
    {
        list = new Delegation1[size];
        count = size;
        exist = 0;
    }
    ~ConcreteAggregate()
    {
        delete[] list;
    }
    Iterator* createIterator();
    unsigned int getSize() const
    {
        return count;
    }
    void at(unsigned int index)
    {
        list[index].declare();
    }
    void addDelegation(string nation, int num1, int num2)
    {
        if (exist == count)
        {
            cout << "���������Ѿ����ˡ�" << std::endl;
            return;
        }
        this->list[exist].setValue(nation, num1, num2);
        exist++;
    }
    // ...

private:
    Delegation1* list;
    unsigned int count;//capacity
    int exist;//number of teams that already exist
    // ...
};

/*
 * Iterator
 * provides the interface that all iterators must implement and
 * a set of methods for traversing over elements
 */
class Iterator
{
public:
    virtual ~Iterator() { /* ... */ }

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual void currentItem() = 0;
};

/*
 * Concrete Iterator
 * implements the interface and is responsible for managing
 * the current position of the iterator
 */
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(ConcreteAggregate* l) :
        list(l), index(0) {}

    ~ConcreteIterator() {}

    void first()
    {
        index = 0;
    }
    void next()
    {
        index++;
    }

    bool isDone() const
    {
        return (index >= list->getSize());
    }
    void currentItem()
    {
        if (isDone())
        {
            std::cout << "�����ˣ�";
        }
        list->at(index);
    }

private:
    ConcreteAggregate* list;
    unsigned int index;
    // ...
};

int testIterator();

