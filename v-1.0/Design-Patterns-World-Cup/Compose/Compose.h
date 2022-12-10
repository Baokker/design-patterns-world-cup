#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>

// �����࣬�ܹ����������������нڵ㣨Ҷ�ڵ���ڲ��ڵ㣩
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
    
    // ��������
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

// ����࣬ͨ������������ݹ�������������յĽ��
class Composite : public Component {
    
protected:
    std::list<Component*> children_;

public:
    // �Դ���Ϊ���ڵ�ȥ����ӽڵ�
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    // ɾ�����ڵ�
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

// �ͻ��˴���ͨ�������Ľӿ�ȥ���þ�������ĺ���
void composeClientCode(Component* component);

int testCompose();