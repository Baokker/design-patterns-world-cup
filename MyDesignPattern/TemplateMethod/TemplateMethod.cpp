#include "TemplateMethod.h"
#include "iostream"
#include "../RAII/RAII.h"
#include <windows.h>

void Group::holdMatch() {
    Prepare* prepare = new Prepare("����1","����͢vs����");
    cout << this->getName() << "������ʼ" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void SemiFinals::holdMatch() {
    Prepare* prepare = new Prepare("����2", "����vs������");
    cout << this->getName() << "������ʼ" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void Finals::holdMatch() {
    Prepare* prepare = new Prepare("����1", "������vs����͢");
    cout << this->getName() << "������ʼ" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void delay_time()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << '.';
        //Sleep(200);//��ʱע�͵������ǵüӻ���
    }
    std::cout << std::endl;
}
int testTemplateMethod()
{
    Group* m1 = new Group("С����");
    SemiFinals* m2 = new SemiFinals("�����");
    Finals* m3 = new Finals("����");
    cout << "���籭�����������£�" << endl << endl;
    m1->templateMethod();
    m2->templateMethod();
    m3->templateMethod();


    delete m1, m2, m3;
    return 0;
}

