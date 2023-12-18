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

struct Var {
    char name;
    double val;
};

class Parcer {
    std::string expression;

 public:
    explicit Parcer(std::string exp) : expression(exp) { }
    void delete_spaces() {
        expression.erase(remove(expression.begin(), expression.end(), ' '),
            expression.end());
    }
    int brackets_check() {
        TStack<char> brackets(expression.length());
        std::string brackets_str = "(){}[]";
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
                else if (c == ']') {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket";
                        return throw_location;
                    }
                }
                else if (c == '}') {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket";
                        return throw_location;
                    }
                }
                else brackets.push(c);
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
    int syntax_check() {
        int throw_location = 15;
        std::string letornum = "qwertyuiopasdfghjklzxcvbnm1234567890.";
        std::string nums = "0123456789.";
        std::string letts = "qwertyuiopasdfghjklzxcvbnm";
        std::string arithop = "+-*/^";
        std::string state2 = letornum + "(){}[]";
        int state = 0;
        char c;
        for (int i = 0; i < expression.length(); i++) {
            c = expression[i];
            if (i == expression.length() - 1) {
                state = 2;
            }
            switch (state) {
            case 0: {
                if (c == '(' || c == '[' || c == '{') {
                    state = 0;
                    continue;
                }
                else if (letornum.find(c) != std::string::npos) {
                    if (letts.find(c) != std::string::npos) {
                        while (letts.find(expression[i]) != std::string::npos) {
                            i++;
                        }
                        if (nums.find(expression[i]) != std::string::npos) {
                            std::cerr << std::string(throw_location + i, ' ')
                                << " ^ - unexpected symbol";
                            return throw_location + i;
                        }
                    }
                    if (nums.find(c) != std::string::npos) {
                        while (nums.find(expression[i]) != std::string::npos) {
                            i++;
                        }
                        if (letts.find(expression[i]) != std::string::npos) {
                            std::cerr << std::string(throw_location + i, ' ')
                                << " ^ - unexpected symbol";
                            return throw_location + i;
                        }
                    }
                    i--;
                    state = 1;
                }
                else {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol";
                    return throw_location + i;
                }
                break;
            }
            case 1: {
                if (c == ')' || c == ']' || c == '}') {
                    state = 1;
                    continue;
                }
                else if (arithop.find(c) != std::string::npos) {
                    state = 0;
                    continue;
                }
                else {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol";
                    return throw_location + i;
                }
                break;
            }
            case 2: {
                if (state2.find(c) == std::string::npos || c == '.') {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol";
                    return throw_location + i;
                }
                else {
                    return 0;
                }
                break;
            }
            }
        }
    }
    int varcon_check() {
        std::string nums = "0123456789.";
        std::string letts = "qwertyuiopasdfghjklzxcvbnm";
        // consts check ===========================
        //      . in first pos  ->   throw
        //  0 in [0]; . !in [1] ->   throw
        //                 any  ->   to end or dot
        //       . in last pos  ->   throw
        // 
        // vars check =============================
        // push all symbols to string::S;
        //      len S > 1:
        //          sin cos tg ctg exp ln <- check
        //                 else throw;
        //      len S == 1:
        //          save var
        //      else:
        //          throw
    }
    // const check, trigonomety check func
    Expression parce() {
        delete_spaces();
        brackets_check();
        syntax_check();
        // const check, trigonomety check func
        // reverse poland;
    }
};

class Expression {
    std::string expression;
    std::string reverse_poland;
    Var* vars;
    double* consts;
 public:
    Expression() {
        expression  = "";
        reverse_poland = "";
        vars = new Var[26];
        consts = new double[50];
        vars = nullptr;
        consts = nullptr;
    }
    explicit Expression(Expression& exp) {
        expression = exp.expression;
        reverse_poland = exp.reverse_poland;
        for (int i = 0; i < 26; i++) {
            vars[i] = exp.vars[i];
        }
        for (int i = 0; i < 50; i++) {
            consts[i] = exp.consts[i];
        }
    }
    void init_vars() {
        ;
    }
    void calculate() {
        ; // need reverse poland
    }
};

std::string equation_enter() {
    std::string exp;
    std::cout << "Ваше выражение: ";
    std::getline(std::cin,exp);
    return exp;
}

#endif ARITHMETIC_ARITHMETIC_H_
