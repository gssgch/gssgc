#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 利用循环不等式，查找第一个缺失的正整数
 */

//    声明函数
int FirstMissNumber(int *p, int size);
//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {3,5,1,2,-3,7,4,8};
    int m =FirstMissNumber(a, sizeof(a)/ sizeof(int));
    std::cout << m << std::endl;
    return 0;
}

int FirstMissNumber(int *a, int size) {
    a--; // 从1开始数
    int i = 1;
    while (i <= size) {
        if (a[i] == i) {
            i++;
        } else if ((a[i] < i) || (a[i] > size) || (a[i] == a[a[i]])) {
            a[i]=a[size];
            size--;
        }else{ // if (a[i]>i)
            swap(a[a[i]],a[i]);
        }
    }
    return i;
}
