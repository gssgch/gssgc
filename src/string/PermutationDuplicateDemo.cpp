#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 有重复的全排列，需要去重

 */

//    声明函数
void Print(const int *p, int size);

void Permutation(int *p, int size, int n);

bool IsDuplicate(const int *a, int n, int t);

//
int _tmain(int argc, _TCHAR *argv[]) {
//    int a[] = {1, 2, 2, 3};
    Permutation(a, sizeof(a) / sizeof(int), 0);

    // 时间换空间
    char str[] = "abbc";
    Permutation(str, sizeof(str) / sizeof(char), 0);
    return 0;
}
// 重复字符的全排列递归算法时间复杂度 O((n+1)!)
void Permutation(int *a, int size, int n) {
    if (n == size - 1) {
        Print(a, size);
        return;
    }
    for (int i = n; i < size; i++) {
        if (!IsDuplicate(a, n, i)) {// a[i]是否与[n,i) 重复
            continue;
        }
        swap(a[i], a[n]);
        Permutation(a, size, n + 1);
        swap(a[i], a[n]);
    }
}

// 时间换空间  判断重复的时间为O(1)
void Permutation2(char *a, int size, int n) {
    if (n == size - 1) {
        Print(a, size);
        return;
    }
    int dup[256] = {0};
    for (int i = n; i < size; i++) {
        if (dup[a[i]]==1) {
            continue;
        }
        dup[a[i]]=1;
        swap(a[i], a[n]);
        Permutation(a, size, n + 1);
        swap(a[i], a[n]);
    }
}
// 是否重复出现过
bool IsDuplicate(const int *a, int n, int t) {
    while (n < t) {
        if (a[n] == a[t]) {
            return false;
        }
        n++;
    }
        return true;
}

void Print(const int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}