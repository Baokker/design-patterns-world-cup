#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>
#include<iomanip>

using namespace std;

//抽象表达式类
class Expression
{
public:
	virtual bool Interpret(const string& info) = 0;
};

//终结符表达式类
class TerminalExpressin : public Expression
{
private:
	set<string> infos;

public:
	TerminalExpressin(const vector<string> datas)
	{
		//将datas的数据存进infos
		infos.insert(datas.begin(), datas.end());
	}

	bool Interpret(const string& info)
	{
		//如果找到该名词，返回真
		if (infos.find(info) != infos.end())
			return true;
		//如果找到最后仍然找不到，返回假
		return false;
	}
};

//非终结符表达式类
class AndExpression : public Expression
{
private:
	shared_ptr<Expression> setCountry;
	shared_ptr<Expression> setPeople;

public:
	AndExpression(shared_ptr<Expression> country, shared_ptr<Expression> person) : setCountry(country), setPeople(person) {}

	bool Interpret(const string& info)
	{
		regex pattern("的");
		vector<string> results(sregex_token_iterator(info.begin(), info.end(), pattern, -1), sregex_token_iterator());
		if (results.size() != 2)
		{
			cout << "输入解释信息有误，无法解析！" << endl;
			return false;
		}

		//返回在两个终结符集中查找结果的并
		return setCountry->Interpret(results[0]) && setPeople->Interpret(results[1]);
	}
};

//上下文全局信息类
class Context {
private:
	vector<string> countries;
	vector<string> people;
	shared_ptr<Expression> andExpr;

public:
	Context()
	{
		//生成国家的终结符集以及人员的字符集
		countries.push_back("中国");
		people.push_back("记者");
		people.push_back("施工队");
		people.push_back("裁判");
		people.push_back("广告商");
		andExpr = make_shared<AndExpression>(make_shared<TerminalExpressin>(countries), make_shared<TerminalExpressin>(people));
	}

	void SearchForPeople(const string& info)
	{
		if (andExpr->Interpret(info))
		{
			cout << setiosflags(ios::left) << setfill(' ') << setw(30) << info << "来到了卡塔尔" << endl;
		}
		else
		{
			cout << setiosflags(ios::left) << setfill(' ') << setw(30) << info << "没有来卡塔尔" << endl;
		}
	}
};

void testInterpreter();
