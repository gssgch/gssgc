#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include <stack>
#include<vector>

using namespace std;
/**
 * 直方图矩形面试
 * 给定n个非负整数，表示直方图的方柱的高度，同时，每个方柱的宽度假定都为1，
 * 试找出直方图中最大的矩形面积。
 *
 * 分析：
 * 暴力求解
 * 时间复杂度为O(N^2)
 * 如果a[i+1]>= a[i] 则以a[i]为右边界的矩形，总可以添加a[i+1]带来的矩形，使得面积增大
 * 只有a[i+1]<a[i]时，才计算a[i]为右边界的矩形面积
 *     为了算法一致性，在最后，添加a[size]=0,保证a[size-1]为右边界的矩形得到计算
 *
 */

//    声明函数
int LargestRectangleArea(vector<int>& height);

// 这个测试的结果不对，错误原因未知，
int _tmain(int argc, _TCHAR *argv[]) {
    vector<int> ivec(5); //2,7,5,6,4
    ivec.push_back(2);
    ivec.push_back(7);
    ivec.push_back(5);
    ivec.push_back(6);
    ivec.push_back(4);
    int value =LargestRectangleArea(ivec);
    std::cout << value << std::endl;
    return 0;
}

int LargestRectangleArea(vector<int>& height){
    height.push_back(0);// 确保原数组height的最后一位能够得到计算

    stack<int> s;
    int answer=0;
    int temp;
    for (int  i = 0;  i < (int)height.size();) {
        printf("\n=%d",(int)height.size());
        if(s.empty()||height[i]>height[s.top()]){
            s.push(i);
            i++;
        }else{
            temp=s.top();
            s.pop();
            answer=max(answer,height[temp]*(s.empty()?i:i-s.top()-1));
        }
    }
    return answer;
}
