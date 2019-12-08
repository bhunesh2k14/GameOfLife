# Conway's Game Of Life
Originally conceived by the British mathematician J.H. Conway in 1970 and popularized by Martin Gardner in his Scientific American column. The game is a simulation that models the life cycle of bacteria. 
Given aninitial pattern, the game simulates the birth and death of future generations using simple rules.

## Rules
The simulation starts with an initial pattern of cells on the grid and computes successive generations of cells according to the following rules:
1. A location that has zero or one neighbor will be empty in the next generation. If a cell was in that location, it dies of loneliness.
2. A location with two neighbors is stable—that is, if it contained a cell, it still contains a cell. If it was empty, it's still empty.
3. A location with three neighbors will contain a cell in the next generation. If it was unoccupied before, a new cell is born. If it currently contains a cell, the cell remains. Good times.
4. A location with four or more neighbors will be empty in the next generation. If there was a cell in that location, it dies of overcrowding.

## Solution
- **GameOfLife.cpp** contains the C++ Source file for the solution of Conway's Game of Life.
- **GameOfLife.exe** is the compiled exe of the source cpp.

## Testing
- Run **GameOfLife.exe**.
- Enter Rows and Column.
- Choose Random or Custom Input, for the start state of the colony.
  - If Custom input is choosen provide the input sequence as space-separated integers for each cell going from left-right top-bottom manner.
- Simulation runs showing each generation and stops if stable state is reached.
  *delay can be set in source code between each generations with 50ms being the default set.*

