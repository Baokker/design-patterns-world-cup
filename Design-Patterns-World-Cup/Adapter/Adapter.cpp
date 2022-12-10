#include<iostream>
#include "Adapter.h"
using namespace std;
void testAdaptor()
{
    cout << "Ϊ�˽�����Խ������⣬" 
        << "���������췽����������Ҳ����������ǲ��־Ը���롣" << endl << endl;
    ForeignLanguage* japanese = new ForeignLanguage("�ձ�", "����");
    ForeignLanguage* spanish = new ForeignLanguage("����͢", "��������");
    ForeignLanguage* german = new ForeignLanguage("�¹�", "����");
    ForeignLanguage* french = new ForeignLanguage("����", "����");

    Volunteer1* v1 = new VolunteerTranslator(japanese);
    Volunteer1* v2 = new VolunteerTranslator(spanish);
    Volunteer1* v3 = new VolunteerTranslator(german);
    Volunteer1* v4 = new VolunteerTranslator(french);

    cout << "־Ը����a����ǲ���ձ��ӣ�";
    v1->request(); cout << endl;

    cout << "־Ը����b����ǲ������͢�ӣ�";
    v2->request(); cout << endl;

    cout << "־Ը����c����ǲ���¹��ӣ�";
    v3->request();; cout << endl;

    cout << "־Ը����d����ǲ�������ӣ�";
    v4->request();; cout << endl;

    cout << "....." << endl << endl;

    delete v4;
    delete v3;
    delete v2;
    delete v1;
}



