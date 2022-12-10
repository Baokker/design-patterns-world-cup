#include <iostream>
#include "cstdlib"
 /*
  * AbstractClass
  * implements a template method defining the skeleton of an algorithm
  */
  //��������

class Match
{//���������
    std::string name;
public:
    virtual ~Match() {}

    void templateMethod()//ģ�巽��
    {
        holdMatch();
    }

    virtual void holdMatch() = 0;

    void setName(std::string name)
    {
        this->name = name;
    }
    std::string getName()
    {
        return this->name;
    }
    // ...
};
/*
 * Concrete Class
 * implements the primitive operations to carry out specific steps
 * of the algorithm, there may be many Concrete classes, each implementing
 * the full set of the required operation
 */
class Group : public Match
{
public:
    ~Group() {}
    Group(std::string name)
    {
        this->setName(name);
    }
    void holdMatch();
    // ...
};
class SemiFinals : public Match
{
public:
    ~SemiFinals() {}
    SemiFinals(std::string name)
    {
        this->setName(name);
    }

    void holdMatch();

    // ...
};
class Finals : public Match
{
public:
    ~Finals() {}
    Finals(std::string name)
    {
        this->setName(name);
    }

    void holdMatch();
    // ...
};

int testTemplateMethod();
