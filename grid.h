    #ifndef GRID_H
    #define GRID_H

    #include <iostream>
    #include <sstream>
    #include <utility>
    #include <string>
    #include <iomanip>
    #include "robot.h"

    using namespace std;

    class Grid
    {
    public:
        int rows;
        int cols;
        string grid[100][100]; // Grid size is fixed at 100x100
        MovingRobot* robots[100]; // Fixed-size array for robots
        int robotCount; // Counter for robots

        Grid(int r, int c) : rows(r), cols(c), robotCount(0) {
            // Initialize the grid with empty values
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    grid[i][j] = "--";
                }
            }
            // Initialize robot array
            for (int i = 0; i < 100; i++) {
                robots[i] = nullptr;
            }
        }

        void addRobot(MovingRobot* robot) {
        if (robotCount < 100) {
            robots[robotCount++] = robot;
            pair<int, int> pos = robot->getPos();
            grid[pos.first][pos.second] = robot->getName(); // Set grid cell with robot's name
        }
    }


        void moveRobotTurnBased(int robotIndex) {
            MovingRobot* robot = robots[robotIndex];
            if (robot) {
                pair<int, int> oldPos = robot->getPos();
                grid[oldPos.first][oldPos.second] = "--";
                robot->randomMove(rows, cols);
                pair<int, int> newPos = robot->getPos();
                grid[newPos.first][newPos.second] = robot->getName();
            }
        }

        string showgrid() {
            stringstream ss;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    ss << setw(2) << grid[i][j] << ' ';
                }
                ss << '\n';
            }
            return ss.str();
        }
    };

    #endif
