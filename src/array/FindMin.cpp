#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 查找旋转数组的最小值
 */

//    声明函数
int FindMin(int *p, int size);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {3, 5, 1, 2,7, 4, 8};
    int m = FindMin(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}

int FindMin(int *num, int size) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low < high) {
        mid = (high + low) / 2;
        if (num[mid] < num[high]) { // 最小值在左半部分
            high = mid;
        } else if (num[mid] > num[high]) {// 最小值在右半部分
            low = mid + 1;
        }
    }
    return num[low];
}
