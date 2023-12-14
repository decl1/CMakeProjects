// Copyright 2023 Anikin Maksim

#ifndef MYMATH_MYMATH_H_
#define MYMATH_MYMATH_H_

#include <iostream>

#define PI 3.141592653589793 // max double

int factorial(int val) {
    int ret = 1;
    for (int i = 2; i <= val; i++) {
        ret *= i;
    }
    return ret;
}

double msin(double rad, int calcdepth = 3) {
    double ret = rad;
    for (int n = 1; n < calcdepth; n++) {
        ret += (pow(-1,n) / factorial(2*n+1)) * pow(rad, 2 * n + 1);
    }
    return ret;
}

double mcos(double rad, int calcdepth = 3) {
    double ret = rad;
    for (int n = 1; n < calcdepth; n++) {
        ret += (pow(-1, n) / factorial(2 * n)) * pow(rad, 2 * n);
    }
    return ret;
}

double mtan(double rad, int calcdepth = 3) {
    if (abs(rad) >= PI / 2) 
        throw std::invalid_argument{ "invalid tan argument" };
    return (msin(rad, calcdepth) / mcos(rad,calcdepth));
}

double mctan(double rad, int calcdepth = 3) {
    if (abs(rad) >= PI)
        throw std::invalid_argument{ "invalid ctan argument" };
    return (mcos(rad, calcdepth) / msin(rad, calcdepth));
}

double mexp(double x, int calcdepth = 4) {
    double ret = 0;
    for (int n = 0; n < calcdepth; n++) {
        ret += pow(x, n) / factorial(n);
    }
    return ret;
}

double mln(double x, int calcdept = 3) {
    ;
}

#endif
