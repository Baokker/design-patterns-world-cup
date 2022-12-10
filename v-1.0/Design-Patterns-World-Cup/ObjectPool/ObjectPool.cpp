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
        return "使用阿根廷国旗.";
    }
};

class PORFlag : public AbstractFlag {
    std::string UsefulFunctionFlag() const override {
        return "使用葡萄牙国旗.";
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
        return "生产使用阿根廷球衣";
    }
    /**
     * The variant, Product B1, is only able to work correctly with the variant,
     * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionClothes(const AbstractFlag& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionFlag();
        return "生产使用阿根廷球衣 同时配合 " + result;
    }
};

class PORClothes : public AbstractClothes {
public:
    std::string UsefulFunctionClothes() const override {
        return "生产使用葡萄牙球衣";
    }
    /**
     * The variant, Product B2, is only able to work correctly with the variant,
     * Product A2. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionClothes(const AbstractFlag& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionFlag();
        return "生产使用葡萄牙球衣 同时配合 " + result;
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
    int factory_pool[32];//世界杯所有队伍的工厂对象池,每一支队伍在数组中占据一位，用宏定义直接索引，数字为1表示该队伍的所有比赛均已结束，为0表示该队伍仍有未结束的比赛，为-1表示该队伍参赛状况未知
public:
    ObjectPool() {
        for (int i = 0; i < 32; i++) {
            factory_pool[i] = -1;
        }
    }
    void addFactory(int team_num) {
        factory_pool[team_num] = 0;
        cout << "已加入对象池\n";
    }
    void delFactory(int team_num) {
        factory_pool[team_num] = 1;
        cout << "已从对象池中删去\n";
    }
};

void testObjectPool() {

    bool ARGOver = false;//标记阿根廷比赛结束
    bool POROver = false;//标记葡萄牙比赛结束
    ObjectPool factoryPool;

    std::cout << "\n现在在抽象工厂模式的基础上，使用对象池模式管理生产工厂\n";

    Sleep(1000);
    std::cout << "\n客户端测试:\n阿根廷风格装备生产工厂建立\n阿根廷风格装备生产工厂";
    ARGFactory* f1 = new ARGFactory();
    ClientCode_Pool(*f1);
    factoryPool.addFactory(ARG);//阿根廷工厂加入对象池
    //delete f1; 不进行删除，直到所有的阿根廷比赛结束
    std::cout <<  ::endl;
    std::cout << "阿根廷工厂不直接进行删除，直到所有的阿根廷比赛结束\n";

    Sleep(1000);
    std::cout << "\n客户端测试:\n葡萄牙风格装备生产工厂建立\n葡萄牙风格装备生产工厂";
    PORFactory* f2 = new PORFactory();
    ClientCode_Pool(*f2);
    factoryPool.addFactory(POR);//葡萄牙工厂加入对象池
    //delete f2; 不进行删除，直到所有的葡萄牙比赛结束
    std::cout << ::endl;
    std::cout << "葡萄牙工厂不直接进行删除，直到所有的葡萄牙比赛结束\n";

    Sleep(1000);//等待1秒，模拟比赛进程，之后阿根廷比赛结束
    ARGOver = true;//标记阿根廷比赛结束，对象池清除
    if (ARGOver) {
        cout << "\n所有的阿根廷比赛结束，阿根廷工厂";
        factoryPool.delFactory(ARG);
        delete f1;
    }

    Sleep(1000);////等待1秒，模拟比赛进程，之后阿根廷比赛结束
    POROver = true;//标记葡萄牙比赛结束，对象池清除
    if (POROver) {
        cout << "\n所有的葡萄牙比赛结束，葡萄牙工厂";
        factoryPool.delFactory(POR);
        delete f2;
    }
}