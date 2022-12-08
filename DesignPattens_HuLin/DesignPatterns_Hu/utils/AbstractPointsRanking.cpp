#include "AbstractPointsRanking.h"
NationPoints::NationPoints(const NationPoints& m)
{
    this->country = m.country;
    this->points = m.points;
}
NationPoints& NationPoints::operator=(const NationPoints& m)
{
    this->country = m.country;
    this->points = m.points;
    return *this;
}
void NationPoints::setPoints(int p)
{
    points = p;
}

void AbstractPointsRanking::addCountry(string country, int p)
{
    nationList.push_back(new NationPoints(country, p));
}
void AbstractPointsRanking::setCountryPoints(string country, int p)
{
    for (auto nation : nationList)
    {
        if (nation->country == country)
        {
            nation->setPoints(p);
            break;
        }
    }
}
void AbstractPointsRanking::sortPoints()
{
    auto pointsPol = [](const NationPoints* lhs, const NationPoints* rhs) -> bool
    {
        if (lhs->points >= rhs->points)
            return true;
        else
            return false;
    };
    sort(nationList.begin(), nationList.end(), pointsPol);
}
void AbstractPointsRanking::print()
{
    sortPoints();
    cout << "------------------- 积分 排名 ------------------------\n";
    cout << left << setw(7) << "* rank";
    cout << left << setw(11) << "counrry";
    cout << left << setw(9) << "points *" << endl;
    cout << "------------------------------------------------------\n";

    int rank = 1;
    for (auto nation : nationList)
    {
        cout << "*  " << left << setw(4) << rank++;
        cout << left << setw(12) << nation->country;
        cout << left << setw(9) << nation->points;
        cout << "*" << endl;
    }
    cout << "------------------------------------------------------\n";
}

void AbstractPointsRanking::print(int numCountry)
{
    sortPoints();
    cout << "------------------- 积分 排名 ------------------------\n";
    cout << left << setw(7) << "* rank";
    cout << left << setw(11) << "country";
    cout << left << setw(9) << "points *" << endl;
    cout << "------------------------------------------------------\n";

    int rank = 1;
    for (auto nation = nationList.begin(); nation < nationList.end() && nation < nationList.begin() + numCountry; nation++)
    {
        cout << "*  " << left << setw(4) << rank++;
        cout << left << setw(12) << (*nation)->country;
        cout << left << setw(9) << (*nation)->points;
        cout << " *" << endl;
    }
    cout << "------------------------------------------------------\n";
}