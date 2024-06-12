#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <utility>
#include <cstdlib> // For rand()

using namespace std;

// Abstract class Robot
class Robot 
{
protected:
    string name;
    int robotPosX;
    int robotPosY;

public:
    Robot(const string& name, int x, int y) : name(name), robotPosX(x), robotPosY(y) {}

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

// MovingRobot class inherits from Robot
class MovingRobot : public Robot
{
public:
    MovingRobot(const string& name, int x, int y) : Robot(name, x, y) {}

    void move(int x, int y) override {
        setPos(x, y);
    }

    virtual void randomMove(int maxX, int maxY) = 0;
        
};

// RC class inherits from MovingRobot
class RC : public MovingRobot
{
public:
    RC(const string& name, int x, int y) : MovingRobot(name, x, y) {}

    void randomMove(int maxX, int maxY) override {
        int direction = rand() % 4;
        switch(direction) {
            case 0: // move up
                if (robotPosX > 0) robotPosX--;
                break;
            case 1: // move down
                if (robotPosX < maxX - 1) robotPosX++;
                break;
            case 2: // move left
                if (robotPosY > 0) robotPosY--;
                break;
            case 3: // move right
                if (robotPosY < maxY - 1) robotPosY++;
                break;
        }
    }
};

// TM class inherits from MovingRobot
class TM : public MovingRobot
{
public:
    TM(const string& name, int x, int y) : MovingRobot(name, x, y) {}

    void randomMove(int maxX, int maxY) override {
        int direction = rand() % 4;
        switch(direction) {
            case 0: // move up
                if (robotPosX > 0) robotPosX--;
                break;
            case 1: // move down
                if (robotPosX < maxX - 1) robotPosX++;
                break;
            case 2: // move left
                if (robotPosY > 0) robotPosY--;
                break;
            case 3: // move right
                if (robotPosY < maxY - 1) robotPosY++;
                break;
        }
    }
};

#endif
