// Copyright 2023 Anikin Maksim

#ifndef ARITHMETIC_ARITHMETIC_H_
#define ARITHMETIC_ARITHMETIC_H_

#include <iostream>

void printmenus(const std::string equation) {
    std::cout << "���� ���������: " << equation << std::endl << std::endl;
    std::cout << "����:" << std::endl;
    std::cout << "\t1. ������ �������� ����������" << std::endl;
    std::cout << "\t2. ������� �������� �������� ������" << std::endl;
    std::cout << "\t3. ��������� �������� �������" << std::endl;
    std::cout << "\t4. ��������� � ������� �������" << std::endl;
    std::cout << "\t5. �����" << std::endl << std::endl;
    std::cout << "�����: ";
}
void equation_enter(std::string& equation) {
    std::cout << "���� ���������: ";
    std::cin >> equation; // �������� �� �������
    system("cls");
}
bool eqution_check(const std::string equation) {
    return 0;
}

#endif ARITHMETIC_ARITHMETIC_H_
