//
// Created by ch on 2016/12/29.
//
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cmath>

// 平方根算法
float CalcSqrt(float i) {
    if (i < 1e-6) { // 负数或者0，直接返回0
        return 0;
    }
    float x = i / 2;
    float t = i;
    while (fabs(x - t) > 1e-6) {
        t = x;
        x = (x + i / x) / 2;
    }
    return x;
}

// 求倒数
Reciprocal(double a) {
    double x = 1;
    while (a * x >= 2) {
        if (a > 1) { x /= 10; }
        else x *= 10;
    }
    double t = a;
    while (fabs(x - t) > 1e-6) {
        t = x;
        x = x * (2 - a * x);
    }
    return x;
}

// 没有除法的平方根求法
double CalcSqrt2(double i) {
    if (i < 1e-6) { // 负数或者0，直接返回0
        return 0;
    }
    double x = 1;
    while (i * x * x >= 3) {
        x *= 0.1;
    }
    double t = i;
    while (fabs(x - t) > 1e-6) {
        t = x;
        x = (3 - i * t * t) * t / 2;
    }
    return Reciprocal(x);
}


int _tmain(int argc, _TCHAR *argv[]) {
    for (int i = 0; i <= 10; ++i) {
//        std::cout << CalcSqrt((float) i) << std::endl;
        std::cout << CalcSqrt2((double) i) << std::endl;
    }
    return 0;
}

