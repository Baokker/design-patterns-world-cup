#include<iostream>
#include "Adapter.h"
using namespace std;
void testAdaptor()
{
    cout << "为了解决语言交流问题，" 
        << "卡塔尔主办方已向各个国家参赛队伍队派遣了志愿翻译。" << endl << endl;
    ForeignLanguage* japanese = new ForeignLanguage("日本", "日语");
    ForeignLanguage* spanish = new ForeignLanguage("阿根廷", "西班牙语");
    ForeignLanguage* german = new ForeignLanguage("德国", "德语");
    ForeignLanguage* french = new ForeignLanguage("法国", "法语");

    Volunteer1* v1 = new VolunteerTranslator(japanese);
    Volunteer1* v2 = new VolunteerTranslator(spanish);
    Volunteer1* v3 = new VolunteerTranslator(german);
    Volunteer1* v4 = new VolunteerTranslator(french);

    cout << "志愿翻译a被派遣到日本队，";
    v1->request(); cout << endl;

    cout << "志愿翻译b被派遣到阿根廷队，";
    v2->request(); cout << endl;

    cout << "志愿翻译c被派遣到德国队，";
    v3->request();; cout << endl;

    cout << "志愿翻译d被派遣到法国队，";
    v4->request();; cout << endl;

    cout << "....." << endl << endl;

    delete v4;
    delete v3;
    delete v2;
    delete v1;
}



