#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <utility>
using namespace std;

// Abstract class Robot
class Robot 
{
protected:
    string name;
    int robotPosX;
    int robotPosY;

public:
    virtual void move(int x, int y) = 0;
    virtual ~Robot() {}
    void setName(const string& name) {
        this->name = name;
    }
    string getName() const {
        return name;
    }
    void setPos(int x, int y) {
        robotPosX = x;
        robotPosY = y;
    }
    pair<int, int> getPos() const {
        return make_pair(robotPosX, robotPosY);
    }
};

// Abstract subclasses
class MovingRobot : public Robot {
public:
    MovingRobot(const string& name, int x, int y) {
        this->setName(name);
        this->setPos(x, y);
    }
    void move(int x, int y) override {
        this->setPos(x, y);
    }
};

// Concrete Robot classes
class RC : public MovingRobot
{
public:
    RC(const string& name, int x, int y) : MovingRobot(name, x, y) {}
};

class TM : public MovingRobot
{
public:
    TM(const string& name, int x, int y) : MovingRobot(name, x, y) {}
};

class RT : public MovingRobot
{
public:
    RT(const string& name, int x, int y) : MovingRobot(name, x, y) {}
};

// Abstract mixin classes
class ShootingRobot : public virtual Robot {
public:
    virtual void fire() = 0;
};

class SeeingRobot : public virtual Robot {
public:
    virtual void look() = 0;
};

class SteppingRobot : public virtual Robot {
public:
    virtual void step() = 0;
};

#endif