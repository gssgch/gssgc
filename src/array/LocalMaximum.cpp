#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 求不重复数组的局部最大值   找到一个即可
 * 如果找到所有的，则需要遍历

 */

//    声明函数
int LocalMaximum(const int* p,int size);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int p[]={1,3,4,5,2,112,3,5,6,79,2,4};
    printf("maxvalue:\n");
    std::cout <<LocalMaximum(p, sizeof(p)/ sizeof(int))
              << std::endl;
    return 0;
}
// 时间复杂度O(logN)
int LocalMaximum(const int* A,int size){
    int left =0;
    int right=size-1;
    int mid;
    while(left<right){
        mid = (left+right)/2;
//        printf("mid:\n");
//        std::cout<<mid<<std::endl;
        if(A[mid]>A[mid+1]){ // 这里mid一定是小于size-1的
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return A[left];
}
