#pragma once
#include <iostream>
#include <string>

// 为从startPonit到卡塔尔的国家构建路线
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

    // 动态修改方式
    void setStrategy(Strategy* strategy)
    {
        strategy_ = strategy;
    }
    
    void findWay() const
    {
        if (strategy_) {
            std::cout << "从" << startPoint << "出发，路线如下：";
            std::string result = strategy_->findWay(startPoint);
            std::cout << result << "\n";
        }
        else {
            std::cout << "导航类: 策略为空\n";
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
            return std::string("A - 多哈（直飞）");
        }
        else if (start == "B")
        {
            return std::string("B - 多哈（直飞）");
        }
        else if (start == "C")
        {
            return std::string("C - 多哈（直飞）");
        }
        return "";
    }
};

class Boat : public Strategy
{
    // 路线虚构，仅为设计模式需要，不代表真实性
    std::string findWay(std::string start) const override
    {
        if (start == "A")
        {
            return std::string("A - E - 多哈（渡轮）");
        }
        else if (start == "B")
        {
            return std::string("B - D - C - 多哈（渡轮）");
        }
        else if (start == "C")
        {
            return std::string("C - 多哈（渡轮）");
        }
        return "";
    }
};


void testStrategy();