#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 最长递增子序列

 */

//    声明函数
void GetLIS(const int *array, const int *pre,int nIndex,vector<int>& lis);
void Print(int*p ,int size);
int LIS(const int* p,int length,int*pre,int& nIndex);
//
int _tmain(int argc, _TCHAR *argv[]) {
    int array[] ={1,4,5,6,2,3,8,9,10,11,12,12,1};
    int size = sizeof(array)/ sizeof(int);
    int* pre=new int[size];
    int nIndex;
    int max = LIS(array,size,pre,nIndex);
    vector<int> lis;
    GetLIS(array,pre,nIndex,lis);
    delete [] pre;
    std:cout << max << std::endl;
    Print(&lis.front(),(int)lis.size());
    return 0;
}
void GetLIS(const int *array, const int *pre,int nIndex,vector<int>& lis){
    while(nIndex>=0){
        lis.push_back(array[nIndex]);
        nIndex = pre[nIndex];
    }
    reverse(lis.begin(),lis.end());
}
int LIS(const int* p,int length,int*pre,int& nIndex){
int* longest = new int[length];
    int i,j;
    for (i = 0; i <length ; i++) {
        longest[i]=1;
        pre[i]=-1;
    }
    int nLis =1;
    nIndex = 0;
    for (i = 1; i<length ; i++) {
    for (j = 0; j <i ; j++) {
        if(p[j]<=p[i]){
            if(longest[i]<longest[j]+1){
                longest[i]=longest[j]+1;
                pre[i]=j;
            }
        }
    }
        if(nLis<longest[i]){
            nLis=longest[i];
            nIndex =i;
        }
    }
    delete[] longest;
    return  nLis;
}

void Print(int*p ,int size){
    for (int i = 0; i <size ; i++) {
        std::cout<< p[i]<<'\t';
    }
        std::cout<<'\n';
}