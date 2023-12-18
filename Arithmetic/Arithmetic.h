// Copyright 2023 Anikin Maksim

#ifndef ARITHMETIC_ARITHMETIC_H_
#define ARITHMETIC_ARITHMETIC_H_

#include <iostream>
#include <string>
#include "../TStack/TStack.h"

void printmenus(const std::string expression) {
    std::cout << "Ваше выражение: " << expression << std::endl << std::endl;
    std::cout << "Меню:" << std::endl;
    std::cout << "\t1. Задать значение переменной" << std::endl;
    std::cout << "\t2. Увидеть обратную польскую запись" << std::endl;
    std::cout << "\t3. Вычислить значение функции" << std::endl;
    std::cout << "\t4. Вернуться к заданию функции" << std::endl;
    std::cout << "\t5. Выход" << std::endl << std::endl;
    std::cout << "Выбор: ";
}

class Var {
 public:
    char name;
    double val;
    Var(char name_, double val_) : name(name_), val(val_) {}
};

class Parcer {
    std::string expression;

 public:
    Parcer(std::string exp) : expression(exp) { }
    void delete_spaces() {
        expression.erase(remove(expression.begin(), expression.end(), ' '),
            expression.end());
    }
    int brackets_check() {
        TStack<char> brackets(expression.length());
        std::string brackets_str = "(){}[]"; '('; ')'; '{'; '}'; '['; ']';
        int throw_location = 15;
        for (char& c : expression) {
            if (brackets_str.find(c) != std::string::npos) {
                if (c == ')') {
                    if (brackets.top() == '(') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket";
                        return throw_location;
                    }
                }
                if (c == ']') {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket";
                        return throw_location;
                    }
                }
                if (c == '}') {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket";
                        return throw_location;
                    }
                }
                brackets.push(c);
            }
            throw_location++;
        }
        if (brackets.isEmpty()) {
            return 0;
        }
        else {
            std::cerr << "error: close the bracket!";
            return throw_location;
        }
    }
    
};

std::string equation_enter() {
    std::string exp;
    std::cout << "Ваше выражение: ";
    std::getline(std::cin,exp);
    return exp;
}

#endif ARITHMETIC_ARITHMETIC_H_
