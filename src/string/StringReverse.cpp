#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<cstring>
using namespace std;
/** 字符串循环左移
 * 如把abcdef 前的ab移动到字符串尾部，即得到cdefab
 * 循环左移n+k位和k位的效果相同
 * 循环左移k位等价于循环右移n-k位
 *
 * 分析：
 * 暴力移位法
 * 每次循环左移1位，调用k次即可，时间复杂度为O(kN) 空间复杂度为O(1)
 *
 * 三次拷贝：
 *时间复杂度为O(N) 空间复杂度为O(k)
 *
 * 三次翻转：
 * （x'y'）'=yx
 *  时间复杂度O(N) 空间复杂度O(1)

 */

//    声明函数
void ReverseString(char *s, int from, int to);
void LeftRotateString(char *s, int n, int m);
// 实际运行结果不对
int _tmain(int argc, _TCHAR *argv[]) {
    char str[] = "abcde";
//    char *str = "abcde";
    printf("before:%s",str);
    LeftRotateString(str, sizeof(str) / sizeof(char), 2);
//    cout << str.c_str() << std::endl;
    printf(str);
    return 0;
}

void ReverseString(char *s, int from, int to) {
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}
void LeftRotateString(char *s, int n, int m) {
    m %= n;
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n - 1);
}
