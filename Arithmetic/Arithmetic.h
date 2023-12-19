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
                            << " ^ - unexpected bracket" << std::endl;
                        return throw_location;
                    }
                }
                else if (c == ']') {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket" << std::endl;
                        return throw_location;
                    }
                }
                else if (c == '}') {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    }
                    else {
                        std::cerr << std::string(throw_location, ' ')
                            << " ^ - unexpected bracket" << std::endl;
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
            std::cerr << "error: close the bracket!" << std::endl;
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
                                << " ^ - unexpected symbol" << std::endl;
                            return throw_location + i;
                        }
                    }
                    if (nums.find(c) != std::string::npos) {
                        while (nums.find(expression[i]) != std::string::npos) {
                            i++;
                        }
                        if (letts.find(expression[i]) != std::string::npos) {
                            std::cerr << std::string(throw_location + i, ' ')
                                << " ^ - unexpected symbol" << std::endl;
                            return throw_location + i;
                        }
                    }
                    i--;
                    state = 1;
                }
                else {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol" << std::endl;
                    return throw_location + i;
                }
                break;
            }
            case 1: {
                if (c == ')' || c == ']' || c == '}') {
                    state = 1;
                    continue;
                }
                else if (c == '(' || c == '[' || c == '{') {
                    state = 0;
                    continue;
                }
                else if (arithop.find(c) != std::string::npos) {
                    state = 0;
                    continue;
                }
                else {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol" << std::endl;
                    return throw_location + i;
                }
                break;
            }
            case 2: {
                if (state2.find(c) == std::string::npos || c == '.') {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected symbol" << std::endl;
                    return throw_location + i;
                }
                else {
                    return 0;
                }
                break;
            }
            }
        }
        return 0;
    }
    int varcon_check() {
        std::string nums = "0123456789.";
        std::string letts = "qwertyuiopasdfghjklzxcvbnm";
        int throw_location = 15;
        int incase = 0;
        std::string temp = "";
        char c;
        int tmpdot = 0;
        for (int i = 0; i < expression.length(); i++) {
            c = expression[i];
            if (nums.find(c) != std::string::npos) {
                incase++;
            }
            else {
                incase = 0;
            }
            if (incase > 0) {
                if (c == '.' && incase == 1) {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - '.' on first position" << std::endl;
                    return throw_location + i;
                }
                if (i != expression.length() - 1 && c == '0'&& incase == 1 
                    && expression[i + 1] != '.') {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected zero" << std::endl;
                    return throw_location + i;
                }
                if (c == '.') {
                    tmpdot++;
                    if (tmpdot > 1) {
                        std::cerr << std::string(throw_location + i, ' ')
                            << " ^ - unexpected dot" << std::endl;
                        return throw_location + i;
                    }
                }
                if (i == expression.length() - 1 && c == '.' ||
                    i != expression.length() - 1 && c == '.' &&
                    nums.find(expression[i + 1]) == std::string::npos) {
                    std::cerr << std::string(throw_location + i, ' ')
                        << " ^ - unexpected dot" << std::endl;
                    return throw_location + i;
                }
            }
        }
        incase = 0;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (i == expression.length() - 1 && incase > 1) {
                std::cerr << std::string(throw_location + i - 1, ' ')
                    << " ^ - unkown name or missed '(arg)'" << std::endl;
                return throw_location + i;
            }
            if (letts.find(c) != std::string::npos) {
                incase++;
                temp += c;
            }
            else {
                if (incase == 0) {
                    continue;
                }
                if (incase == 2) {
                    if (temp != "ln") {
                        std::cerr << std::string(throw_location + i-1, ' ')
                            << " ^ - unkown name2" << std::endl;
                        return throw_location + i;
                    }
                }
                if (incase == 3) {
                    if (temp != "sin" && temp != "cos" &&
                        temp != "tan" && temp != "exp") {
                        std::cerr << std::string(throw_location + i-1, ' ')
                            << " ^ - unkown name3" << std::endl;
                        return throw_location + i;
                    }
                }
                if (incase == 4) {
                    if (temp != "ctan") {
                        std::cerr << std::string(throw_location + i -1, ' ')
                            << " ^ - unkown name4" << std::endl;
                        return throw_location + i;
                    }
                }
                if (incase > 4) {
                    std::cerr << std::string(throw_location + i-1, ' ')
                        << " ^ - unkown name5" << std::endl;
                    return throw_location + i;
                }
                incase = 0;
                temp = "";
            }
        }
        return 0;
    }
    bool parce() {
        delete_spaces();
        int check = 0;
        check += brackets_check();
        check += syntax_check();
        check += varcon_check();
        if (check) return 1;
        return 0;
    }
    std::string getexp() {
        return expression;
    }
};

class Expression {
    friend class Parcer;
    std::string expression;
    std::string reverse_poland;
    size_t varscnt;
    Var vars[26];
 public:
    explicit Expression(Parcer& par) {
        if(par.parce()) throw std::logic_error("parce err");
        expression = par.getexp();
        reverse_poland = "";
        varscnt = 0;
        for (int i = 0; i < 26; i++) {
            vars[i].name = '.';
            vars[i].val = 0;
        }
    }
    void init_vars() {
        std::string letts = "qwertyuiopasdfghjklzxcvbnm";
        char c;
        int varscnt = 0;
        int inrow = 0;
        std::string vars_inited = "";
        Var var;
        var.name = NULL;
        var.val = NULL;
        for (int i = 0; i < expression.length(); i++) {
            c = expression[i];
            if (letts.find(c) != std::string::npos) {
                inrow++;
            }
            else if (i == expression.length() - 1 &&
                letts.find(c) != std::string::npos) {
                var.name = expression[i - 1];
                vars_inited += var.name;
                vars[varscnt] = var;
                varscnt++;
            }
            else {
                if (inrow == 1 &&
                    vars_inited.find(expression[i - 1]) == std::string::npos) {
                    var.name = expression[i - 1];
                    vars_inited += var.name;
                    vars[varscnt] = var;
                    varscnt++;
                }
                inrow = 0;
            }
        }
    }
    void calculate() {
        ; // need reverse poland
    }
    void get_Vars() {
        init_vars();
        for (int i = 0; i < varscnt; i++) {
            std::cout << i << vars[i].name << " - " << vars[i].val
                << std::endl;
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
