#include "Iterator.h"

Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}
void delayTime()
{
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        //Sleep(500);//暂时注释掉，最后记得加回来
    }
    cout << std::endl;
}
int testIterator()
{
    int size = 8;
    ConcreteAggregate list = ConcreteAggregate(size);//元素容器

    list.addDelegation("荷兰", 25, 1);
    list.addDelegation("阿根廷", 18, 2);
    list.addDelegation("克罗地亚", 21, 3);
    list.addDelegation("巴西", 18, 4);
    list.addDelegation("英格兰", 23, 5);
    list.addDelegation("法国", 19, 6);
    list.addDelegation("摩洛哥", 20, 7);
    list.addDelegation("葡萄牙", 19, 8);

    Iterator* it = list.createIterator();//为元素容器创建迭代器
    cout << "各个参赛国家代表团依次在卡塔尔会场登记。" << std::endl << std::endl;
    //delayTime();
    for (; !it->isDone(); it->next())//遍历容器
    {
        it->currentItem();
    }
    delayTime();
    cout << std::endl << std::endl;
    delete it;
    return 0;
}