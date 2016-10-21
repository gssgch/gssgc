#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  最大子数组和
 */

//    声明函数
int MaxSubarray(const int *p, int size);
int MaxSubarray2(const int *p, int size,int& a,int& b);
//
int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int start,end;
    int m = MaxSubarray(a, sizeof(a) / sizeof(int));
    int m2 = MaxSubarray2(a, sizeof(a) / sizeof(int),start,end);
//    std::cout << m << std::endl;
    std::cout << m2 << std::endl;
    printf("\nstart=%d,end=%d",start,end);
    return 0;
}
// 单独的最大子数组和
// 时间复杂度O(N)  空间复杂度O(1)
int MaxSubarray(const int *a, int size) {
    if(!a || (size<=0)){
        return 0;
    }
    int sum=a[0]; // 当前子串的和
    int result =sum; // 当前找到的最优解
    for (int i = 1; i < size; i++) {
        if(sum>0){
            sum+=a[i];
        }else{ // 小于0舍弃，因为加和后变小
            sum=a[i];
        }
        result= max(sum,result);
    }
    return result;
}

// 输出最大子数组的和，以及最大子数组
int MaxSubarray2(const int *a, int size,int& from,int& to) {
    if(!a || (size<=0)){
        from =to = -1;
        return 0;
    }
    from = to =0;
    int sum=a[0];
    int result =sum;
    int fromNew; // 新的子数组起点
    for (int i = 1; i < size; i++) {
        if(sum>0){
            sum+=a[i];
        }else{
            sum=a[i];
            fromNew=i;
        }
        if(result<sum){
            result=sum;
            from =fromNew;
            to = i;
        }
    }
    return result;
}
