#pragma once
#pragma once
//设计模式--visitor模式类

#include <list>
#include <string>
using namespace std;


class VisitorFootBall;
class FootBallData {
public:
    ~FootBallData() {};
    void setData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY);
    int redPoint;
    int bluePoint;
    int redFoulTimes;
    int blueFoulTimes;
    string countary;
};

//以足球为例
class FootBall {
private:
    FootBallData footballdata;
    const std::string name;
public:
    FootBall(const std::string& name);
    virtual ~FootBall() {};
    virtual void setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) {};
    virtual int redPoint();
    virtual int bluePoint();
    virtual int redFoulTimes();
    virtual int blueFoulTimes();
    virtual string countary();
};

//定义决赛类
class Final :public FootBall {
private:
    FootBallData footballdata;
public:
    Final(const std::string& name);
    ~Final() override {};
    void setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    int redPoint() override;
    int bluePoint() override;
    int redFoulTimes() override;
    int blueFoulTimes() override;
    string countary() override;
};
//定义半决赛类
class SemiFinal :public FootBall {
private:
    FootBallData footballdata;
public:
    SemiFinal(const std::string& name);
    ~SemiFinal() override {};
    virtual void setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    virtual int redPoint() override;
    virtual int bluePoint() override;
    virtual int redFoulTimes() override;
    virtual int blueFoulTimes() override;
    virtual string countary() override;
};

//定义小组赛类
class GroupGame :public FootBall {
private:
    FootBallData footballdata;
public:
    GroupGame(const std::string& name);
    ~GroupGame() override {};
    void setFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    int redPoint() override;
    int bluePoint() override;
    int redFoulTimes() override;
    int blueFoulTimes() override;
    string countary() override;
};

class VisitorFootBall {
private:
    int total = 0;
protected:
    VisitorFootBall() {};
public:
    virtual ~VisitorFootBall() {};
    virtual void visit(Final*) {};
    virtual void visit(SemiFinal*) {};
    virtual void visit(GroupGame*) {};
};


class VisitorFootBallRedPoint : public VisitorFootBall {
private:
    int total = 0;
public:
    VisitorFootBallRedPoint() {};
    ~VisitorFootBallRedPoint() override {};
    int& getRedPoint();
    void visit(Final* final) override;
    void visit(SemiFinal* semifinal1) override;
    void visit(GroupGame* groupgame) override;
};

class VisitorFootBallBluePoint : public VisitorFootBall {
private:
    int total = 0;
public:
    VisitorFootBallBluePoint() {};
    ~VisitorFootBallBluePoint() override {};
    int& getBluePoint();
    void visit(Final* final) override;
    void visit(SemiFinal* semifinal1) override;
    void visit(GroupGame* groupgame) override;
};

class VisitorFootBallRedFoulTimes : public VisitorFootBall {
private:
    int total = 0;
public:
    VisitorFootBallRedFoulTimes() {};
    ~VisitorFootBallRedFoulTimes() override {};
    int& getRedFoulTimes();
    void visit(Final* final) override;
    void visit(SemiFinal* semifinal1) override;
    void visit(GroupGame* groupgame) override;
};

class VisitorFootBallBlueFoulTimes : public VisitorFootBall {
private:
    int total = 0;
public:
    VisitorFootBallBlueFoulTimes() {};
    ~VisitorFootBallBlueFoulTimes() override {};
    int& getBlueFoulTimes();
    void visit(Final* final) override;
    void visit(SemiFinal* semifinal1) override;
    void visit(GroupGame* groupgame) override;
};

class VisitorFootBallCountary : public VisitorFootBall {
private:
    string total;
public:
    VisitorFootBallCountary() {};
    ~VisitorFootBallCountary() override {};
    string& getCountary();
    void visit(Final* final) override;
    void visit(SemiFinal* semifinal1) override;
    void visit(GroupGame* groupgame) override;
};

void testVisitor();