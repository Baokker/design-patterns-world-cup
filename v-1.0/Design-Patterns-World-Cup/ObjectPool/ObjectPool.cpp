#include<iostream>
using namespace std;
#define ARG 0
#define POR 1
#include <windows.h>

class AbstractFlag {
public:
    virtual ~AbstractFlag() {};
    virtual std::string UsefulFunctionFlag() const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ARGFlag : public AbstractFlag {
public:
    std::string UsefulFunctionFlag() const override {
        return "ʹ�ð���͢����.";
    }
};

class PORFlag : public AbstractFlag {
    std::string UsefulFunctionFlag() const override {
        return "ʹ������������.";
    }
};

/**
 * Here's the the base interface of another product. All products can interact
 * with each other, but proper interaction is possible only between products of
 * the same concrete variant.
 */
class AbstractClothes {
    /**
     * Product B is able to do its own thing...
     */
public:
    virtual ~AbstractClothes() {};
    virtual std::string UsefulFunctionClothes() const = 0;
    /**
     * ...but it also can collaborate with the ProductA.
     *
     * The Abstract Factory makes sure that all products it creates are of the
     * same variant and thus, compatible.
     */
    virtual std::string AnotherUsefulFunctionClothes(const AbstractFlag& collaborator) const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ARGClothes : public AbstractClothes {
public:
    std::string UsefulFunctionClothes() const override {
        return "����ʹ�ð���͢����";
    }
    /**
     * The variant, Product B1, is only able to work correctly with the variant,
     * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionClothes(const AbstractFlag& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionFlag();
        return "����ʹ�ð���͢���� ͬʱ��� " + result;
    }
};

class PORClothes : public AbstractClothes {
public:
    std::string UsefulFunctionClothes() const override {
        return "����ʹ������������";
    }
    /**
     * The variant, Product B2, is only able to work correctly with the variant,
     * Product A2. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionClothes(const AbstractFlag& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionFlag();
        return "����ʹ������������ ͬʱ��� " + result;
    }
};

/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called a family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products of
 * another.
 */
class AbstractFactory {
public:
    virtual AbstractFlag* CreateFlag() const = 0;
    virtual AbstractClothes* CreateClothes() const = 0;
};

/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */
class ARGFactory : public AbstractFactory {
public:
    ARGFlag* CreateFlag() const override {
        return new ARGFlag();
    }
    ARGClothes* CreateClothes() const override {
        return new ARGClothes();
    }
};

/**
 * Each Concrete Factory has a corresponding product variant.
 */
class PORFactory : public AbstractFactory {
public:
    PORFlag* CreateFlag() const override {
        return new PORFlag();
    }
    PORClothes* CreateClothes() const override {
        return new PORClothes();
    }
};

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */

void ClientCode_Pool(const AbstractFactory& factory) {
    const AbstractFlag* flag = factory.CreateFlag();
    const AbstractClothes* clothes = factory.CreateClothes();
    delete flag;
    delete clothes;
}


class ObjectPool {
private:
    int factory_pool[32];//���籭���ж���Ĺ��������,ÿһ֧������������ռ��һλ���ú궨��ֱ������������Ϊ1��ʾ�ö�������б������ѽ�����Ϊ0��ʾ�ö�������δ�����ı�����Ϊ-1��ʾ�ö������״��δ֪
public:
    ObjectPool() {
        for (int i = 0; i < 32; i++) {
            factory_pool[i] = -1;
        }
    }
    void addFactory(int team_num) {
        factory_pool[team_num] = 0;
        cout << "�Ѽ�������\n";
    }
    void delFactory(int team_num) {
        factory_pool[team_num] = 1;
        cout << "�ѴӶ������ɾȥ\n";
    }
};

void testObjectPool() {

    bool ARGOver = false;//��ǰ���͢��������
    bool POROver = false;//�����������������
    ObjectPool factoryPool;

    std::cout << "\n�����ڳ��󹤳�ģʽ�Ļ����ϣ�ʹ�ö����ģʽ������������\n";

    Sleep(1000);
    std::cout << "\n�ͻ��˲���:\n����͢���װ��������������\n����͢���װ����������";
    ARGFactory* f1 = new ARGFactory();
    ClientCode_Pool(*f1);
    factoryPool.addFactory(ARG);//����͢������������
    //delete f1; ������ɾ����ֱ�����еİ���͢��������
    std::cout <<  ::endl;
    std::cout << "����͢������ֱ�ӽ���ɾ����ֱ�����еİ���͢��������\n";

    Sleep(1000);
    std::cout << "\n�ͻ��˲���:\n���������װ��������������\n���������װ����������";
    PORFactory* f2 = new PORFactory();
    ClientCode_Pool(*f2);
    factoryPool.addFactory(POR);//������������������
    //delete f2; ������ɾ����ֱ�����е���������������
    std::cout << ::endl;
    std::cout << "������������ֱ�ӽ���ɾ����ֱ�����е���������������\n";

    Sleep(1000);//�ȴ�1�룬ģ��������̣�֮�󰢸�͢��������
    ARGOver = true;//��ǰ���͢������������������
    if (ARGOver) {
        cout << "\n���еİ���͢��������������͢����";
        factoryPool.delFactory(ARG);
        delete f1;
    }

    Sleep(1000);////�ȴ�1�룬ģ��������̣�֮�󰢸�͢��������
    POROver = true;//���������������������������
    if (POROver) {
        cout << "\n���е���������������������������";
        factoryPool.delFactory(POR);
        delete f2;
    }
}