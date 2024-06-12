#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "robot.h"
#include "grid.h"

using namespace std;

int main()
{
    int rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;
    

    Grid myGrid(rows, cols);

    // Populate the grid with "--"
    for (int i = 0; i < myGrid.rows; i++) {
        for (int j = 0; j < myGrid.cols; j++) {
            myGrid.grid[i][j] = "--"; // Initialize with "--"
        }
    }

    // Insert robot
    insertRobot robotInserter;
    int robotRow, robotCol;
    robotInserter.insert(myGrid, robotRow, robotCol);

    // Create a robot and set its position
    RC myRobot("Robot1", robotRow, robotCol);
    myRobot.move(robotRow, robotCol);

    // Display the grid
    cout << myGrid.showgrid() << endl;

    return 0;
}