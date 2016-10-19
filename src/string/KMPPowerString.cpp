#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * KMP应用：PowerString问题
 * 计算字符串S的最小周期

 */

//    声明函数
void Print(const int *p, int size);
int MinPeriod(char* p);

//
int _tmain(int argc, _TCHAR *argv[]) {
    char p[]="abcabcabcabc";
    std::cout << MinPeriod(p)<< std::endl;
    return 0;
}

// 最短周期
int MinPeriod(char* p){
    int nLen=(int)strlen(p);
    if(nLen==0){
        return -1;
    }
    int* next = new int[nLen]; // 仿照KMP求“伪next”
    next[0]=-1;// 哨兵：串首标志
    int k=-1;
    int j=0;
    while(j<nLen-1){
        if((k==-1)||(p[j+1]==p[k])){
            ++k;
            ++j;
            next[j]=k;
        } else{
            k=next[k];
        }
    }
    next[0]=0; // 恢复成逻辑上的0
    int nLast=next[nLen-1];
    delete[] next;
    if(nLast==0){
        return -1;
    }
    if(nLen %(nLen-nLast)==0){
        return nLen-nLast;
    }
    return -1;
}
void Print(const int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}