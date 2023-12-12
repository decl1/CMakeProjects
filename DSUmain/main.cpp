// Copyright 2023 Anikin Maksim

#include <iostream>
#include "../DSU/DSU.h"
#include <time.h>

#define ISLAND_

#ifdef MAZE_
void main() {
    srand(time(NULL));
    unionmaze maze(10, 10);
    maze.maze_generator();
    maze.printmaze();
    std::cout << std::endl;
    maze.printmaze(true);
}
#endif // !

#ifdef ISLAND_
void main() {
    int test_arr1[5][5] = {{1,1,0,0,0},
                           {1,0,0,1,1},
                           {0,0,1,1,0},
                           {0,1,0,0,0},
                           {1,1,0,0,1} };
    ///
    int test_arr2[5][5] = {{0,0,0,0,0},
                           {0,0,0,0,0},
                           {0,0,0,0,0},
                           {0,0,0,0,0},
                           {0,0,0,0,0} };
    ///
    int test_arr3[5][5] = {{1,1,1,1,1},
                           {1,1,1,1,1},
                           {1,1,1,1,1},
                           {1,1,1,1,1},
                           {1,1,1,1,1} };
    ///
    islands test1(5, 5, reinterpret_cast<int*>(test_arr1));
    islands test2(5, 5, reinterpret_cast<int*>(test_arr2));
    islands test3(5, 5, reinterpret_cast<int*>(test_arr3));

    test1.constructIslands();
    test1.tozeroset();
    test1.cntislands();
    std::cout << "test 1: " << test1.getcnt() << std::endl;
    test2.constructIslands();
    test2.tozeroset();
    test2.cntislands();
    std::cout << "test 2: " << test2.getcnt() << std::endl;
    test3.constructIslands();
    test3.tozeroset();
    test3.cntislands();
    std::cout << "test 3: " << test3.getcnt() << std::endl;

}
#endif // !


