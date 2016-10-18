#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  最长公共子序列(Subsequence)   不要求连续，但要求顺序
 *
 *  区别最长公共子串：（Longest Common SubString）
 *  最长公共子串要求连续
 */

//    声明函数
void LCS(const char *s1, const char *s2, string &str);

//
int _tmain(int argc, _TCHAR *argv[]) {
    const char *str1 = "TCGGATCGACTT";
    const char *str2 = "AGCCTACGTA";
    string str;
    LCS(str1, str2, str);
    std:
    cout << str.c_str() << std::endl;
    return 0;
}

void LCS(const char *str1, const char *str2, string &str) {
    int size1 = (int) strlen(str1);
    int size2 = (int) strlen(str2);
    const char *s1 = str1 - 1; // 从1 开始数，方便后面的代码编写
    const char *s2 = str2 - 1;
    vector<vector<int>> chess(size1 + 1, vector<int>(size2 + 1));
    int i, j;
    for (i = 0; i < size1; i++) { // 第0列
        chess[i][0] = 0;
    }
    for (j = 0; j < size2; j++) { // 第0行
        chess[0][j] = 0;
    }
    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            if (s1[i] == s2[j]) { // 相等  左上角+1
                chess[i][j] = chess[i - 1][j - 1] + 1;
            } else {  // 不相等  // 取左边和上边较大者
                chess[i][j] = max(chess[i][j - 1], chess[i - 1][j]);
            }
        }
    }
    i = size1;
    j = size2;
    while ((i != 0) && (j != 0)) {  // 回溯，一直到第0行或者第0列
        if (s1[i] == s2[j]) {
            str.push_back(s1[i]);
            i--;
            j--;
        } else {
            if (chess[i][j - 1] > chess[i - 1][j]) { // 左边大于上边，列减
                j--;
            } else {
                i--;
            }
        }
    }
    // 翻转回溯结果即可
    reverse(str.begin(), str.end());
}