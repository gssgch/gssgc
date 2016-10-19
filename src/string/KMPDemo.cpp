#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * KMP

 */

//    声明函数
void Print(const int *p, int size);


//
int _tmain(int argc, _TCHAR *argv[]) {
    return 0;
}

void GetNext(char *p, int next[]) {
    int nLen = (int) strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < nLen - 1) {
        // 此刻，k即next[j-1]，且p[k]表示前缀，p[j]表示后缀
        // 注：k==-1表示未找到k前缀与k后缀相等，首次分析可先忽略
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else { // p[j]与p[k]失配，则继续递归计算前缀p[next[k]]
            k = next[k];
        }
    }
}

// 升级后的方法  变种的KMP
void GetNext2(char *p, int next[]) {
    int nLen = (int) strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < nLen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            // 如果还相等，进一步赋值
            if (p[j] == p[k]) {
                next[j] = next[k];
            } else {
                next[j] = k;
            }
        } else {
            k = next[k];
        }
    }
}

int KMP(int k) {
    int ans = -1;
    int i = 0;
    int j = 0;
    int pattern_len = strlen(g_pattern);
    while (i < n) {
        if (j == -1 || g_s[i] == g_pattern[j]) {
            ++i;
            ++j;
        } else {
            j = g_next[j];
        }
        if (j == pattern_len) {
            ans = i - pattern_len;
            break;
        }
    }
    return ans;
}

// 暴力求解
int BruteForceSearch(const char *s, const char *p) {
    int i = 0; // 当前匹配到的原始串首位
    int j = 0; // 模式串的匹配位置
    int size = (int) strlen(p);
    int nLast = (int) strlen(s) - size;
    while ((i < nLast) && (j < size)) {
        if (s[i + j] == p[j]) {// 匹配，则模式串匹配位置后移
            j++;
        } else {// 不匹配，则比对下一个位置，模式串回溯到首位
            i++;
            j = 0;
        }
    }
    if (j >= size) {
        return i;
    }
    return -1;
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