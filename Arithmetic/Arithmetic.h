// Copyright 2023 Anikin Maksim

#ifndef ARITHMETIC_ARITHMETIC_H_
#define ARITHMETIC_ARITHMETIC_H_

#include <iostream>

void printmenus(const std::string equation) {
    std::cout << "Ваше выражение: " << equation << std::endl << std::endl;
    std::cout << "Меню:" << std::endl;
    std::cout << "\t1. Задать значение переменной" << std::endl;
    std::cout << "\t2. Увидеть обратную польскую запись" << std::endl;
    std::cout << "\t3. Вычислить значение функции" << std::endl;
    std::cout << "\t4. Вернуться к заданию функции" << std::endl;
    std::cout << "\t5. Выход" << std::endl << std::endl;
    std::cout << "Выбор: ";
}
void equation_enter(std::string& equation) {
    std::cout << "Ваше выражение: ";
    std::cin >> equation;
    system("cls");
}

#endif ARITHMETIC_ARITHMETIC_H_
