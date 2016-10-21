#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  零子数组
 *  求连续子数组的和最接近0的值
 */

//    声明函数
int MinSubarray(const int *p, int size);
//
int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int m = MinSubarray(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}
// 时间复杂度O(N*logN) 空间复杂度O(N)
int MinSubarray(const int *a, int size) {
    int* sum=new int[size+1]; // sum[i]:a[0...i-1]的和
    sum[0]=0;
    int i;
    // 求前i子数组的和
    for (i = 0; i <size ; i++) {
        sum[i+1]=sum[i]+a[i];
    }
    // 排序  如果不排序，时间是O(N^2),排序后免去计算
    sort(sum,sum+size+1);
    int difference = abs(sum[1]-sum[0]); // 初始化
    int result = difference;
    for (i = 0;  i< size; i++) {
        difference=abs(sum[i+1]-sum[i]);
        result=min(difference,result);
    }
    delete[] sum;
    return result;
}
