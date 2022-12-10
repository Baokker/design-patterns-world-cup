#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#define PRI_GOLD 1
#define PRI_TOTAL 2
using namespace std;

//An item of PointsRanking
class NationPoints {
public:
	std::string country;
	int points;
	NationPoints(string country, int p) : country(country), points(p) {}
	NationPoints(const NationPoints& m);
	NationPoints& operator=(const NationPoints& m);
	void setPoints(int p);
};

class AbstractPointsRanking
{
public:
	void addCountry(string country, int p);
	void setCountryPoints(string country, int p);
	void sortPoints();
	void print();
	void print(int numNations);
protected:
	vector<NationPoints*> nationList;
};
