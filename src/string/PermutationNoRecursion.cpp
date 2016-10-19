#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 非递归全排列
 * 使用下排列法  做法：后找，小大，交换，翻转
 */

//    声明函数
void Print(int *p, int size);

void Reverse(int *from, int *to);

bool GetNextPermutation(int *a, int size);

// 整体做法 时间复杂度 O(N*N!)
int _tmain(int argc, char *argv[]) {
    int a[] = {1, 2, 2, 3}; // , 3, 4
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    while (GetNextPermutation(a, size)) {
        Print(a, size);
    }
    return 0;
}

void Reverse(int *from, int *to) {
    int t;
    while (from < to) {
        t = *from;
        *from = *to;
        *to = t;
        from++;
        to--;
    }
}

// O(N)
bool GetNextPermutation(int *a, int size) {
    // 后找  O(N)
    int i = size - 2; // 倒数第二位开始，最早开始比较后两位
    while ((i >= 0) && (a[i] >= a[i + 1])) { // 如果是降序，接着往前找
        i--;
    }
    if (i < 0) { // 找完了，没有找到
        return false;
    }
    // 小大 O(N)
    int j = size - 1;
    while (a[j] <= a[i]) { // 找到一个大的，并且是大的里面最小的
        j--;
    }
    // 交换  O(1)
    swap(a[j], a[i]);

    // 翻转  O(N)
    Reverse(a + i + 1, a + size - 1);
    return true;
}
void Print(int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}