#include "Interpreter.h"

void testInterpreter()
{


	shared_ptr<ContextInterpreter> worldCup = make_shared<ContextInterpreter>();
	vector<string> people = { "�й��ļ���" , "�й���ʩ����" , "�й��Ĳ���" , "�й��Ĺ����", "�й��������" };
	for (string item : people)
	{
		worldCup->SearchForPeople(item);
	}

}