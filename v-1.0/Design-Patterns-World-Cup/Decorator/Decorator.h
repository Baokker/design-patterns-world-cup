#pragma once
#include <string>
#include <iostream>

// basic component
class PlayerDecorator {
protected:
    std::string name;
public:
    std::string getName() { return name; }
    virtual ~PlayerDecorator() {}
    virtual std::string Operation() const = 0;
};

// concrete component
class ConcretePlayerDecorator : public PlayerDecorator {
public:
    ConcretePlayerDecorator(std::string name) {
        this->name = name;
    }
    std::string Operation() const override {
        return this->name;
    }
};

// Base Decorator
class Decorator : public PlayerDecorator {
    // component
protected:
    PlayerDecorator* component_;

public:
    Decorator(PlayerDecorator* component) :
        component_(component) {
    }

    // The Decorator distribute all work to the wrapped component.
    std::string Operation() const override {
        return this->component_->Operation();
    }
};


class YellowHair : public Decorator {
    
public:
    YellowHair(PlayerDecorator* component) 
        : Decorator(component) {
    }
    std::string Operation() const override {
        return "YellowHair (" + Decorator::Operation() + ")";
    }
};


class BlackHair : public Decorator {
public:
    BlackHair(PlayerDecorator* component) 
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "BlackHair (" + Decorator::Operation() + ")";
    }
};

class StraightHair : public Decorator {
public:
    StraightHair(PlayerDecorator* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "StraightHair (" + Decorator::Operation() + ")";
    }
};

class CurlyHair : public Decorator {
public:
    CurlyHair(PlayerDecorator* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "CurlyHair (" + Decorator::Operation() + ")";
    }
};


class YellowSkin : public Decorator {
public:
    YellowSkin(PlayerDecorator* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "YellowSkin (" + Decorator::Operation() + ")";
    }
};

class BlackSkin : public Decorator {
public:
    BlackSkin(PlayerDecorator* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "BlackSkin (" + Decorator::Operation() + ")";
    }
};

class WhiteSkin : public Decorator {
public:
    WhiteSkin(PlayerDecorator* component)
        : Decorator(component) {
    }

    std::string Operation() const override {
        return "WhiteSkin (" + Decorator::Operation() + ")";
    }
};

void testDecorate();