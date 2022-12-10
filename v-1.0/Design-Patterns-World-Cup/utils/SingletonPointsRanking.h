#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include "AbstractPointsRanking.h"
#define PRI_GOLD 1
#define PRI_TOTAL 2
using namespace std;

/*
  SingletonPointsRanking: 单例模式创建的积分榜
*/
class SingletonPointsRanking : public AbstractPointsRanking {
    friend class PointsRanking;
public:
    static SingletonPointsRanking& Instance()
    {
        static SingletonPointsRanking instance;
        return instance;
    }

private:
    SingletonPointsRanking() = default;
    SingletonPointsRanking(const SingletonPointsRanking& m) = delete;
    SingletonPointsRanking& operator=(const SingletonPointsRanking& m) = delete;
};