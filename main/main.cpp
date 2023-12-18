#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (1) {
        Parcer exp(equation_enter());
        exp.brackets_check();
        exp.syntax_check();
        std::cerr << std::endl;
        system("pause");
    }
}
