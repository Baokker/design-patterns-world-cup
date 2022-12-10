#include <iostream>
using namespace std;

#include "visitor.h"

void FootBallData::setData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    redPoint = REDPOINT;
    bluePoint = BLUEPOINT;
    redFoulTimes = REDFOULTIMES;
    blueFoulTimes = BLUEFOULTIMES;
    countary = COUNTARY;
}

FootBall::FootBall(const std::string& name) : name(name) {};
int FootBall::redPoint() { return footballdata.redPoint; };
int FootBall::bluePoint() { return footballdata.bluePoint; };
int FootBall::redFoulTimes() { return footballdata.redFoulTimes; };
int FootBall::blueFoulTimes() { return footballdata.blueFoulTimes; };
string FootBall::countary() { return footballdata.countary; }

Final::Final(const std::string& name) : FootBall(name) {};
void Final::setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    footballdata.setData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int Final::redPoint() { return footballdata.redPoint; };
int Final::bluePoint() { return footballdata.bluePoint; };
int Final::redFoulTimes() { return footballdata.redFoulTimes; };
int Final::blueFoulTimes() { return footballdata.blueFoulTimes; };
string Final::countary() { return footballdata.countary; }

SemiFinal::SemiFinal(const std::string& name) : FootBall(name) {};
void SemiFinal::setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    footballdata.setData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int SemiFinal::redPoint() { return footballdata.redPoint; };
int SemiFinal::bluePoint() { return footballdata.bluePoint; };
int SemiFinal::redFoulTimes() { return footballdata.redFoulTimes; };
int SemiFinal::blueFoulTimes() { return footballdata.blueFoulTimes; };
string SemiFinal::countary() { return footballdata.countary; }

GroupGame::GroupGame(const std::string& name) : FootBall(name) {};
void GroupGame::setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    footballdata.setData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int GroupGame::redPoint() { return footballdata.redPoint; };
int GroupGame::bluePoint() { return footballdata.bluePoint; };
int GroupGame::redFoulTimes() { return footballdata.redFoulTimes; };
int GroupGame::blueFoulTimes() { return footballdata.blueFoulTimes; };
string GroupGame::countary() { return footballdata.countary; }

int& VisitorFootBallRedPoint::getRedPoint() { return total; }
void VisitorFootBallRedPoint::visit(Final* final) {
    total = final->redPoint();
}
void VisitorFootBallRedPoint::visit(SemiFinal* semifinal) {
    total = semifinal->redPoint();
}
void VisitorFootBallRedPoint::visit(GroupGame* groupgame) {
    total = groupgame->redPoint();
}

int& VisitorFootBallBluePoint::getBluePoint() { return total; }
void VisitorFootBallBluePoint::visit(Final* final) {
    total = final->bluePoint();
}
void VisitorFootBallBluePoint::visit(SemiFinal* semifinal) {
    total = semifinal->bluePoint();
}
void VisitorFootBallBluePoint::visit(GroupGame* groupgame) {
    total = groupgame->bluePoint();
}

int& VisitorFootBallRedFoulTimes::getRedFoulTimes() { return total; }
void VisitorFootBallRedFoulTimes::visit(Final* final) {
    total = final->redFoulTimes();
}
void VisitorFootBallRedFoulTimes::visit(SemiFinal* semifinal) {
    total = semifinal->redFoulTimes();
}
void VisitorFootBallRedFoulTimes::visit(GroupGame* groupgame) {
    total = groupgame->redFoulTimes();
}

int& VisitorFootBallBlueFoulTimes::getBlueFoulTimes() { return total; }
void VisitorFootBallBlueFoulTimes::visit(Final* final) {
    total = final->blueFoulTimes();
}
void VisitorFootBallBlueFoulTimes::visit(SemiFinal* semifinal) {
    total = semifinal->blueFoulTimes();
}
void VisitorFootBallBlueFoulTimes::visit(GroupGame* groupgame) {
    total = groupgame->blueFoulTimes();
}

string& VisitorFootBallCountary::getCountary() { return total; }
void VisitorFootBallCountary::visit(Final* final) {
    total = final->countary();
}
void VisitorFootBallCountary::visit(SemiFinal* semifinal) {
    total = semifinal->countary();
}
void VisitorFootBallCountary::visit(GroupGame* groupgame) {
    total = groupgame->countary();
}

void testVisitor()
{
    Final* final = new Final("Final");
    SemiFinal* semifinal1 = new SemiFinal("SemiFinal1");
    SemiFinal* semifinal2 = new SemiFinal("SemiFinal2");
    GroupGame* groupgame = new GroupGame("GroupGame");

    final->setFootBallData(1, 2, 2, 2, "巴西对战阿根廷");
    semifinal1->setFootBallData(4, 1, 3, 2, "巴西对战法国");
    semifinal2->setFootBallData(2, 0, 4, 1, "阿根廷对战克罗地亚");
    groupgame->setFootBallData(1, 4, 5, 3, "韩国对战巴西");

    VisitorFootBallRedPoint visitorFootBallRedPoint;
    VisitorFootBallBluePoint visitorFootBallBluePoint;
    VisitorFootBallRedFoulTimes visitorFootBallRedFoulTimes;
    VisitorFootBallBlueFoulTimes visitorFootBallBlueFoulTimes;
    VisitorFootBallCountary visitorFootBallCountary;

    cout << "开始比赛" << endl;

    visitorFootBallRedPoint.visit(groupgame);
    visitorFootBallBluePoint.visit(groupgame);
    visitorFootBallRedFoulTimes.visit(groupgame);
    visitorFootBallBlueFoulTimes.visit(groupgame);
    visitorFootBallCountary.visit(groupgame);
    cout << "小组赛对战的双方为：  " << visitorFootBallCountary.getCountary() << endl;
    cout << "比赛的比分为：        " << visitorFootBallRedPoint.getRedPoint() << ":" << visitorFootBallBluePoint.getBluePoint() << endl;
    cout << "双方犯规次数为：      " << visitorFootBallRedFoulTimes.getRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.getBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.visit(semifinal1);
    visitorFootBallBluePoint.visit(semifinal1);
    visitorFootBallRedFoulTimes.visit(semifinal1);
    visitorFootBallBlueFoulTimes.visit(semifinal1);
    visitorFootBallCountary.visit(semifinal1);
    cout << "第一场半决赛双方为：  " << visitorFootBallCountary.getCountary() << endl;
    cout << "比赛的比分为：        " << visitorFootBallRedPoint.getRedPoint() << ":" << visitorFootBallBluePoint.getBluePoint() << endl;
    cout << "双方犯规次数为：      " << visitorFootBallRedFoulTimes.getRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.getBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.visit(semifinal2);
    visitorFootBallBluePoint.visit(semifinal2);
    visitorFootBallRedFoulTimes.visit(semifinal2);
    visitorFootBallBlueFoulTimes.visit(semifinal2);
    visitorFootBallCountary.visit(semifinal2);
    cout << "第二场半决赛双方为：  " << visitorFootBallCountary.getCountary() << endl;
    cout << "比赛的比分为：        " << visitorFootBallRedPoint.getRedPoint() << ":" << visitorFootBallBluePoint.getBluePoint() << endl;
    cout << "双方犯规次数为：      " << visitorFootBallRedFoulTimes.getRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.getBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.visit(final);
    visitorFootBallBluePoint.visit(final);
    visitorFootBallRedFoulTimes.visit(final);
    visitorFootBallBlueFoulTimes.visit(final);
    visitorFootBallCountary.visit(final);
    cout << "决赛双方为：          " << visitorFootBallCountary.getCountary() << endl;
    cout << "比赛的比分为：        " << visitorFootBallRedPoint.getRedPoint() << ":" << visitorFootBallBluePoint.getBluePoint() << endl;
    cout << "双方犯规次数为：      " << visitorFootBallRedFoulTimes.getRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.getBlueFoulTimes() << endl;

    cout << "比赛结束" << endl;

    delete final;
    delete semifinal2;
    delete semifinal1;
    delete groupgame;
}