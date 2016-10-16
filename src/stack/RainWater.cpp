#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include <stack>
#include<vector>

using namespace std;
/**
 * 直方图矩形面试
 * 给定n个非负整数，表示直方图的方柱的高度，同时，每个方柱的宽度假定都为1，
 * 若使用这样形状的容器收集雨水，可以盛多少水量
 * 如输入 0 1 0 2 1 0 1 3 2 1 2 1 返回6
 */

//    声明函数
int TrappingRainWater(int A[],int n);

int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}

int TrappingRainWater(int A[],int n){
    int secHight = 0; // 当前找到的第二大的数
    int left=0;
    int right = n-1;
    int trap=0; // 依次遍历每个方柱能装水的容量
    while(left<right){
        if(A[left]<A[right]){
            secHight=max(A[left],secHight);
            trap +=(secHight-A[left]);
            left++;
        }else{
            secHight=max(A[right],secHight);
            trap += (secHight-A[right]);
            right--;
        }
    }
    return  trap;
}
