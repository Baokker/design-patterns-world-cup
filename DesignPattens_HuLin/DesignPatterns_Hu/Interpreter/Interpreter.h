#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>
#include<iomanip>

using namespace std;

//������ʽ��
class Expression
{
public:
	virtual bool Interpret(const string& info) = 0;
};

//�ս�����ʽ��
class TerminalExpressin : public Expression
{
private:
	set<string> infos;

public:
	TerminalExpressin(const vector<string> datas)
	{
		//��datas�����ݴ��infos
		infos.insert(datas.begin(), datas.end());
	}

	bool Interpret(const string& info)
	{
		//����ҵ������ʣ�������
		if (infos.find(info) != infos.end())
			return true;
		//����ҵ������Ȼ�Ҳ��������ؼ�
		return false;
	}
};

//���ս�����ʽ��
class AndExpression : public Expression
{
private:
	shared_ptr<Expression> setCountry;
	shared_ptr<Expression> setPeople;

public:
	AndExpression(shared_ptr<Expression> country, shared_ptr<Expression> person) : setCountry(country), setPeople(person) {}

	bool Interpret(const string& info)
	{
		regex pattern("��");
		vector<string> results(sregex_token_iterator(info.begin(), info.end(), pattern, -1), sregex_token_iterator());
		if (results.size() != 2)
		{
			cout << "���������Ϣ�����޷�������" << endl;
			return false;
		}

		//�����������ս�����в��ҽ���Ĳ�
		return setCountry->Interpret(results[0]) && setPeople->Interpret(results[1]);
	}
};

//������ȫ����Ϣ��
class Context {
private:
	vector<string> countries;
	vector<string> people;
	shared_ptr<Expression> andExpr;

public:
	Context()
	{
		//���ɹ��ҵ��ս�����Լ���Ա���ַ���
		countries.push_back("�й�");
		people.push_back("����");
		people.push_back("ʩ����");
		people.push_back("����");
		people.push_back("�����");
		andExpr = make_shared<AndExpression>(make_shared<TerminalExpressin>(countries), make_shared<TerminalExpressin>(people));
	}

	void SearchForPeople(const string& info)
	{
		if (andExpr->Interpret(info))
		{
			cout << setiosflags(ios::left) << setfill(' ') << setw(30) << info << "�����˿�����" << endl;
		}
		else
		{
			cout << setiosflags(ios::left) << setfill(' ') << setw(30) << info << "û����������" << endl;
		}
	}
};

void testInterpreter();
