#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>

// 基础类，能够派生出组合类的所有节点（叶节点和内部节点）
class Component {

protected:
    Component* parent_ = nullptr;
    std::string name;

public:
    virtual ~Component() {}
    
    void SetParent(Component* parent) {
        this->parent_ = parent;
    }
    Component* GetParent() const {
        if (this->parent_ == nullptr)
        {
            std::cout << "parent is null";
        }
        return this->parent_;
    }
    std::string getName() const { return this->name; }
    
    virtual void Add(Component* component) {}
    virtual void Remove(Component* component) {}
    
    virtual bool IsComposite() const {
        return false;
    }
    
    // 基础操作
    virtual std::string Operation() const = 0;
};

class Item : public Component {
public:
    Item(std::string name) {
        this->name = name;
    }
    std::string Operation() const override {
        return this->name;
    }
};

// 组合类，通过对所有子类递归求和来返回最终的结果
class Composite : public Component {
    
protected:
    std::list<Component*> children_;

public:
    // 以此类为父节点去添加子节点
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    // 删除父节点
    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override {
        return true;
    }
    

    std::string Operation() const override {
        std::string result;
        for (const Component* c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + " + ";
            }
        }
        return "(" + result + ")";
    }
};

// 客户端代码通过公共的接口去调用具体子类的函数
void composeClientCode(Component* component);

int testCompose();