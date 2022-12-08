#pragma once
#include <string>
#include <iostream>

// basic component
class Player {
protected:
    std::string name;
public:
    std::string getName() { return name; }
    virtual ~Player() {}
    virtual std::string Operation() const = 0;
};

// concrete component
class ConcretePlayer : public Player {
public:
    ConcretePlayer(std::string name) {
        this->name = name;
    }
    std::string Operation() const override {
        return this->name;
    }
};

// Base Decorator
class Decorator : public Player {
    // component
protected:
    Player* component_;

public:
    Decorator(Player* component) :
        component_(component) {
    }

    // The Decorator distribute all work to the wrapped component.
    std::string Operation() const override {
        return this->component_->Operation();
    }
};


class YellowHair : public Decorator {
    
public:
    YellowHair(Player* component) 
        : Decorator(component) {
    }
    std::string Operation() const override {
        return "YellowHair (" + Decorator::Operation() + ")";
    }
};


class BlackHair : public Decorator {
public:
    BlackHair(Player* component) 
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "BlackHair (" + Decorator::Operation() + ")";
    }
};

class StraightHair : public Decorator {
public:
    StraightHair(Player* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "StraightHair (" + Decorator::Operation() + ")";
    }
};

class CurlyHair : public Decorator {
public:
    CurlyHair(Player* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "CurlyHair (" + Decorator::Operation() + ")";
    }
};


class YellowSkin : public Decorator {
public:
    YellowSkin(Player* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "YellowSkin (" + Decorator::Operation() + ")";
    }
};

class BlackSkin : public Decorator {
public:
    BlackSkin(Player* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "BlackSkin (" + Decorator::Operation() + ")";
    }
};

class WhiteSkin : public Decorator {
public:
    WhiteSkin(Player* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "WhiteSkin (" + Decorator::Operation() + ")";
    }
};

void testDecorate();