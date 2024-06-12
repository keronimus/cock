#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "robot.h"
#include "grid.h"

using namespace std;

int main()
{
    int rows, cols, numRobots, numSteps;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;
    cout << "Number of robots: ";
    cin >> numRobots;
    cout << "Number of steps: ";
    cin >> numSteps;

    Grid myGrid(rows, cols);

    // Insert robots
    for (int i = 0; i < numRobots; i++) {
        int robotRow, robotCol;
        string robotType;
        cout << "Enter the position for robot " << i + 1 << " (row col): ";
        cin >> robotRow >> robotCol;
        cout << "Enter the type of robot (TM or RC): ";
        cin >> robotType;

        // Ensure the position is within the grid bounds
        if (robotRow < 0 || robotRow >= rows || robotCol < 0 || robotCol >= cols) {
            cout << "Invalid position. Please enter a position within the grid bounds." << endl;
            i--; // Ask for the position again
            continue;
        }

        // Ensure the position is not already occupied
        if (myGrid.grid[robotRow][robotCol] != "--") {
            cout << "Position already occupied by another robot. Please choose another position." << endl;
            i--; // Ask for the position again
            continue;
        }

        // Create a robot and set its position
        if (robotType == "TM") {
            TM* myRobot = new TM("TM", robotRow, robotCol);
            myRobot->move(robotRow, robotCol);
            myGrid.addRobot(myRobot);
        } else if (robotType == "RC") {
            RC* myRobot = new RC("RC", robotRow, robotCol);
            myRobot->move(robotRow, robotCol);
            myGrid.addRobot(myRobot);
        } else {
            cout << "Invalid robot type. Please enter either TM or RC." << endl;
            i--; // Ask for the position again
            continue;
        }
    }

    // Display the initial grid
    cout << "Initial grid:\n" << myGrid.showgrid() << endl;

    // Move robots step by step in a turn-based manner
    for (int step = 0; step < numSteps; step++) {
        int currentRobotIndex = step % numRobots;
        myGrid.moveRobotTurnBased(currentRobotIndex);
        cout << "Grid after step " << step + 1 << ":\n" << myGrid.showgrid() << endl;
    }

    return 0;
}
