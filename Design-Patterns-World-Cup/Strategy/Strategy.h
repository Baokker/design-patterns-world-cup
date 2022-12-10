#pragma once
#include <iostream>
#include <string>

// Ϊ��startPonit���������Ĺ��ҹ���·��
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string findWay(std::string startPonit) const = 0;
};


class Navigator
{
private:
    Strategy* strategy_;
    std::string startPoint;
public:

    Navigator(std::string startP) {
        this->startPoint = startP;
    }

    Navigator(std::string startP, Strategy* strategy) {
        this->startPoint = startP;
        this->setStrategy(strategy);
    }

    // ��̬�޸ķ�ʽ
    void setStrategy(Strategy* strategy)
    {
        strategy_ = strategy;
    }
    
    void findWay() const
    {
        if (strategy_) {
            std::cout << "��" << startPoint << "������·�����£�";
            std::string result = strategy_->findWay(startPoint);
            std::cout << result << "\n";
        }
        else {
            std::cout << "������: ����Ϊ��\n";
        }
    }
};


class Airplane : public Strategy
{
public:
    std::string findWay(std::string start) const override
    {
        if (start == "A")
        {
            return std::string("A - �����ֱ�ɣ�");
        }
        else if (start == "B")
        {
            return std::string("B - �����ֱ�ɣ�");
        }
        else if (start == "C")
        {
            return std::string("C - �����ֱ�ɣ�");
        }
        return "";
    }
};

class Boat : public Strategy
{
    // ·���鹹����Ϊ���ģʽ��Ҫ����������ʵ��
    std::string findWay(std::string start) const override
    {
        if (start == "A")
        {
            return std::string("A - E - ��������֣�");
        }
        else if (start == "B")
        {
            return std::string("B - D - C - ��������֣�");
        }
        else if (start == "C")
        {
            return std::string("C - ��������֣�");
        }
        return "";
    }
};


void testStrategy();