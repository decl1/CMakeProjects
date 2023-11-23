// Copyright 2023 Anikin Maskim

#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

int main() {
    // Settings
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Vars
    std::string equation = "";
    bool eqflag = 0;
    // Code
    equation_enter(equation);
    while (1) {
        int menuswitch = 0;
        printmenus(equation);
        std::cin >> menuswitch;
        switch (menuswitch) {
            default: {
                system("cls");
                continue;
            }
        }
    }
}
