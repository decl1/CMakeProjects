// Copyright 2023 Anikin Maksim

#include <iostream>
#include "../DSU/DSU.h"
#include <time.h>

void main() {
    srand(time(NULL));
    unionmaze maze(10, 10);
    maze.maze_generator();
    maze.printmaze();
    std::cout << std::endl;
    maze.printmaze(true);
}
