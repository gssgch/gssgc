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

 */

//    声明函数
void Print(const int *p, int size);
void Reverse(int* from,int* to);
bool GetNextPermutation(int*a,int*size);
//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {1, 2,2,3}; // , 3, 4
    int size= sizeof(a)/ sizeof(int);
    Print(a,size);
    while (GetNextPermutation(a,size)){
        Print(a,size);
    }
    return 0;
}

void Reverse(int* from,int* to){
    int t;
    while(from <to){
        t=*from;
        *from = *to;
        *to=t;
        from++;
        to--;
    }
}
bool GetNextPermutation(int*a,int*size){
    // 后找
    int i = size-2;
    while((i>=0)&&(a[i]>=a[i+1])){
        i--;
    }
    if(i<0){
        return false;
    }
    // 大小
    int j=size-1;
    while(a[j]<=a[i]){
        j--;
    }
    // 交换
    swap(a[j],a[i]);

    // 翻转
    Reverse(a+i+1,a+size+1);
    return true;
}