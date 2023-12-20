#include <iostream>
#include <Windows.h>
#include "../Arithmetic/Arithmetic.h"

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (1) {
        Parcer pexp(equation_enter());
        try {
            pexp.parce();
        }
        catch(std::logic_error) {
            std::cerr << "PARCE ERROR" << std::endl;
            continue;
        }
        Expression exp(pexp);
    }
}
