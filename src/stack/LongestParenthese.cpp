#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include <cstring>  // memset这个方法
#include <stack>

using namespace std;
/**
 * 最长括号匹配
 * 给定字符串 仅包含左括号和右括号，可能不是括号匹配的，设计算法
 * 找出最长匹配的括号子串，返回该子串长度
 * 分析：
 * 记起始匹配位置start=-1 最大匹配长度ml=0
 * 考察第i位字符c
 * 如果c为左括号，压栈
 * 如果c为右括号，它一定与栈顶左括号匹配，
 *      如果栈为空，表示没有匹配的左括号，start=i，为下一次可能的匹配做准备
 *      如果栈不空，出栈（匹配上了）
 *          如果栈为空，i-start即为当前找到的匹配长度，检查i-start是否比ml更大，使得ml得以更新
 *          如果栈不空，则当前栈顶元素t是上次匹配的最后位置，检查i-t是否比ml大，使得ml得以更新
 *
 * 因为入栈的一定是左括号，不需要把括号入栈，入栈字符串索引就好了

 */

//    声明函数
int GetLongestParenthese(const char *p);
int GetLongestParenthese2(const char *p);

int _tmain(int argc, _TCHAR *argv[]) {
    const char *wang = "()()()";
    std::cout << GetLongestParenthese(wang) << std::endl;
    return 0;
}

// 空间复杂度为O(N) 时间复杂度为O(N)
int GetLongestParenthese(const char *p) {
    int size = (int) strlen(p);
    stack<int> s;
    int answer = 0; // 最终结果
    int start = -1; // 左括号的前一个位置

    for (int i = 0; i < size;i++) {
        if (p[i] == '(') {
            s.push(i);
        } else { // p[i] == ')'
            if (s.empty()) {
                start = i;
            } else {
                s.pop();
                if (s.empty()) {
                    answer = max(answer, i - start);
                } else {
                    answer = max(answer, i - s.top());
                }
            }
        }
    }
        return answer;
}

 // 空间复杂度O(1) 时间复杂度为O(N)
int GetLongestParenthese2(const char *p) {
    int size = (int) strlen(p);
    int answer = 0; // 最终结果
    int deep = 0; // 遇到了多少左括号
    int start = -1; // 最深的deep==0时左括号的位置
    // 其实为了方便计算长度，该变量是最深左括号的前一个位置
    int i;
    for (int i = 0; i < size; i++) {
        if (p[i] == '(') {
            deep++;
        } else { // p[i] == ')'
            deep--;
            if (deep == 0) {
                answer = max(answer, i - start);
            } else if (deep < 0) { // 说明右括号数目大于左括号，初始化为for循环前
                deep = 0;
                start = i;
            }
        }
    }
    deep = 0; // 遇到了多少右括号
    start = size; // 最深的（deep==0时）右括号的位置
    // 为了方便计算长度，该变量是最深右括号的后一个位置
    for (i = size - 1; i >= 0; i--) {
        if (p[i] == ')') {
            deep++;
        } else { // p[i] == ')'
            deep--;
            if (deep == 0) {
                answer = max(answer, i - start);
            } else if (deep < 0) { // 说明右括号数目大于左括号，初始化为for循环前
                deep = 0;
                start = i;
            }
        }
    }
    return answer;
}
