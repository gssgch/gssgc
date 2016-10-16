#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include <cstring>  // memset这个方法
#include <stack>

using namespace std;
/**
 * 计算逆波兰表达式
 * 分析：
 *  如果当前字符是操作数，则压栈
 *  如果当前字符是操作符，则弹出栈中的两个操作数，计算后仍然压入栈
 *      若某次操作，栈内无法弹出两个操作数，表达式有误
 */

//    声明函数
int ReversePolishNotation(const char *str[],int size);
bool IsOperator(const char* token);

int _tmain(int argc, _TCHAR *argv[]) {
    const char *str[] ={"2","1","+","3","*"};
    int value =ReversePolishNotation(str, sizeof(str)/ sizeof(const char*));
    std::cout << value << std::endl;
    return 0;
}

int ReversePolishNotation(const char *str[],int size){
stack<int> s;
    int a,b;
    const char* token;
    for (int i = 0; i <size ; i++) {
        token=str[i];
        if(!IsOperator(token)){
            s.push(atoi(token));
        }else{
            b=s.top();
            s.pop();
            a=s.top();
            s.pop();
            if(token[0]=='+'){
                s.push(a+b);
            }else if(token[0]=='-'){
                s.push(a-b);
            }else if(token[0]=='*'){
                s.push(a*b);
            }else{ //  if(token[0]=='-')
                s.push(a/b);
            }
        }
    }
    return s.top();
}
// 判断是否操作符
bool IsOperator(const char* token){
    return ((token[0]=='+')||(token[0]=='-')||(token[0]=='*')||(token[0]=='/'));
}
