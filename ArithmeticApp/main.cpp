// Copyright 2023 Anikin Maskim

#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

int main() {
    // Settings
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Vars
    // Code
    while (1) {
        int menuswitch = 0;
        std::cin >> menuswitch;
        switch (menuswitch) {
        case(5): {
            system("cls");
            exit(0);
            break;
        } 
        default: {
            system("cls");
            continue;
        }
        }
    }
}
