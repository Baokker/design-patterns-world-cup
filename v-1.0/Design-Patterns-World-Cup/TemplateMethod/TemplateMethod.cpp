#include "TemplateMethod.h"
#include "iostream"
#include "../RAII/RAII.h"
#include <windows.h>

void Group::holdMatch() {
    Prepare* prepare = new Prepare("场地1","阿根廷vs波兰");
    cout << this->getName() << "即将开始" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void SemiFinals::holdMatch() {
    Prepare* prepare = new Prepare("场地2", "荷兰vs卡塔尔");
    cout << this->getName() << "即将开始" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void Finals::holdMatch() {
    Prepare* prepare = new Prepare("场地1", "葡萄牙vs阿根廷");
    cout << this->getName() << "即将开始" << endl;
    prepare->startMatch();
    prepare->~Prepare();
}
void delay_time()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << '.';
        //Sleep(200);//暂时注释掉，最后记得加回来
    }
    std::cout << std::endl;
}
int testTemplateMethod()
{
    Group* m1 = new Group("小组赛");
    SemiFinals* m2 = new SemiFinals("半决赛");
    Finals* m3 = new Finals("决赛");
    cout << "世界杯比赛流程如下：" << endl << endl;
    m1->templateMethod();
    m2->templateMethod();
    m3->templateMethod();


    delete m1, m2, m3;
    return 0;
}

