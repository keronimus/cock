#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib> // Include this for rand() and srand()
#include <ctime>   // Include this for time()

using namespace std;

class Grid
{
public:
    int rows;
    int cols;
    string grid[100][100]; // Add this member variable

    Grid(int r, int c) : rows(r), cols(c) {
        // Initialize the grid with empty values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = "--";
            }
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

class insertRobot
{
public:
    void insert(Grid& grid, int& row, int& col) {
        srand(time(0)); // Initialize random number generator

        do {
            row = rand() % grid.rows;
            col = rand() % grid.cols;
        } while (grid.grid[row][col] != "--");

        grid.grid[row][col] = "T";
    }
};

#endif
