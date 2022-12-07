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
        //Sleep(500);//��ʱע�͵������ǵüӻ���
    }
    cout << std::endl;
}
int testIterator()
{
    int size = 8;
    ConcreteAggregate list = ConcreteAggregate(size);//Ԫ������

    list.addDelegation("����", 25, 1);
    list.addDelegation("����͢", 18, 2);
    list.addDelegation("���޵���", 21, 3);
    list.addDelegation("����", 18, 4);
    list.addDelegation("Ӣ����", 23, 5);
    list.addDelegation("����", 19, 6);
    list.addDelegation("Ħ���", 20, 7);
    list.addDelegation("������", 19, 8);

    Iterator* it = list.createIterator();//ΪԪ����������������
    cout << "�����������Ҵ����������ڿ������᳡�Ǽǡ�" << std::endl << std::endl;
    //delayTime();
    for (; !it->isDone(); it->next())//��������
    {
        it->currentItem();
    }
    delayTime();
    cout << std::endl << std::endl;
    delete it;
    return 0;
}