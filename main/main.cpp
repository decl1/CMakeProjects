#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Parcer exp(equation_enter());
    exp.brackets_check();
}
