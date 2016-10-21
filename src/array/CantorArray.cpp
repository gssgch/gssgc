#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * cantor数组
 */


//    声明函数
void CantorExpansion(const int *a,int* b,int size);
void Print(const int* a,int size);

int _tmain(int argc, _TCHAR *argv[]) {
    const int p[] = {2,6,4,5,3,1};
    int size =sizeof(p) / sizeof(int);
    int* a=new int[size];
    CantorExpansion(p,a,size);
    Print(a,size);
    delete [] a;
    return 0;
}

void CantorExpansion(const int *a,int* b,int size){
    int i,j;
    for (i = 0; i < size; ++i) {
        b[i]=0;
        for (j = i+1; j < size; ++j) {
            if(a[j]<a[i]){
                b[i]++;
            }
        }
    }
}
int CantorExpansionR(const int *a,int* result,int size){
    int i;
    vector<int> v(size);
    for (i = 0; i < size; i++) {
        v[i] = i + 1;
    }
    for (i = 0; i < size; i++) {
        result[i]=v[a[i]];
        v.erase(v.begin()+a[i]);
    }
}
int CantorExpansionR2(int *a,int* result,int size){
memset(result,0, sizeof(int)*size);
    int i,j;
    for (i = 0; i < size; i++) {
            for (j = 0; j < size; ++j) {
                if(result[j]!=0){
                    continue;
                }
                if(a[j]==0){
                    break;
                }
                a[j]--;
            }
        result[j]=i+1;
        }
}
void Print(const int* a,int size){
    for (int i = 0; i <size ; ++i) {
        std::cout<< a[i]<<'  ';
    }
    std::cout<<std::endl;
}