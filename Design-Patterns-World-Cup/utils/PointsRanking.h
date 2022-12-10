#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include"AbstractPointsRanking.h"
#include"SingletonPointsRanking.h"
using namespace std;


//Ã½Ìå»ý·Ö°ñ
class PointsRanking : public AbstractPointsRanking {
public:
	PointsRanking() {}
	PointsRanking(const PointsRanking& m) {
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationPoints(*nation));
		}
	}
	PointsRanking& operator=(const PointsRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationPoints(*nation));
		}
		return *this;
	}
	PointsRanking(const SingletonPointsRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationPoints(*nation));
		}
	}
	PointsRanking& operator=(const SingletonPointsRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationPoints(*nation));
		}
		return *this;
	}
};