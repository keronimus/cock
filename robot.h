#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <utility>
using namespace std;

//Abstract class robot
class Robot 
{
protected:
    string name;
    int robotPosX;
    int robotPosY;

public:

    virtual void move(int x, int y) = 0;



};

class RC : public MovingRobot
{
protected:
    string name;
    int robotPosX;
    int robotPosY;

public:
    // virtual void look() = 0;
    virtual void move (int x, int y) = 0;

};

class TM : public MovingRobot
{

};

class RT : public MovingRobot
{

};

class UR
{ 

};

// Abstract subclasses
class MovingRobot : public virtual Robot {
public:
    virtual void move(int x, int y) = 0;
};

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