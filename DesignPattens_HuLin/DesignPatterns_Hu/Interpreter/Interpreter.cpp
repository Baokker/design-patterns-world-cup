#include "Interpreter.h"

void testInterpreter()
{


	shared_ptr<Context> worldCup = make_shared<Context>();
	vector<string> people = { "�й��ļ���" , "�й���ʩ����" , "�й��Ĳ���" , "�й��Ĺ����", "�й��������" };
	for (string item : people)
	{
		worldCup->SearchForPeople(item);
	}

}