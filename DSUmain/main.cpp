// Copyright 2023 Anikin Maksim

#include <iostream>
#include "../DSU/DSU.h"
#include <time.h>

void main() {
    srand(time(NULL));
    /*DSU set(6);
    while (1) {
        int x = 0;
        int y = 0;
        set.print();
        std::cout << "union: ";
        std::cin >> x >> y;
        set.union_(x, y);
        system("cls");
    }*/
    maze lab(8);
    lab.generate_way_to_finish(1);
}
