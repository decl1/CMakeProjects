// Copyright 2023 Anikin Maskim

#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (1) {
        int menuswitch = 0;
        printmenus();
        std::cin >> menuswitch;
        switch (menuswitch) {
            default: {
                system("cls");
                continue;
            }
        }
    }
}
