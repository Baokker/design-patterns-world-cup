#include "Interpreter.h"

void testInterpreter()
{


	shared_ptr<ContextInterpreter> worldCup = make_shared<ContextInterpreter>();
	vector<string> people = { "中国的记者" , "中国的施工队" , "中国的裁判" , "中国的广告商", "中国的足球队" };
	for (string item : people)
	{
		worldCup->SearchForPeople(item);
	}

}