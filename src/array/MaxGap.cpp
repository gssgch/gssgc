#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * 数组的最大间隔
 */

typedef struct tagSBucket{
    bool bValid; // 是否有效桶
    int nMin;
    int nMax;
    tagSBucket():bValid(false){}
    // 将数n加入到桶中
    void Add(int n){
        if(!bValid){
            nMax=nMin=n;
            bValid=true;
        }else{
            if(n>nMax){
                nMax=n;
            }else if(n<nMin){
                nMin=n;
            }
        }
    }
}SBucket;
//    声明函数
int CalcMaxGap(const int *p, int size);

int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int m = CalcMaxGap(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}

int CalcMaxGap(const int *A, int size){
    // 求最值 遍历得到数组的最大值和最小值
    SBucket* pBucket = new SBucket[size];
    int nMax=A[0];
    int nMin=A[0];
    int i;
    for (i = 0; i < size; i++) {
        if(nMax<A[i]){
            nMax=A[i];
        }else if(nMin>A[i]){
            nMin=A[i];
        }
    }
    // 依次将数据放入桶中
    int delta=nMax-nMin;
    int nBucket; // 某数应该在哪个桶中
    for (i = 0; i < size; ++i) {
        // 这里利用了对等相乘，因为 (A[i]-nMin)/桶号 = (nMax-nMin) / size(这个size是最大的桶号)
        nBucket=(A[i]-nMin)*size/delta;
        if(nBucket>=size){
            nBucket=size-1;
        }
        pBucket[nBucket].Add(A[i]);
    }

    // 计算有效桶的间隔
    i=0; // 首个桶一定是有效的
    int nGap=delta/size; // 最小间隔
    int gap;
    for (int j = 1; j < size; ++j) {// i是前一个桶，j是后一个桶
        if(pBucket[j].bValid){
            gap=pBucket[j].nMin-pBucket[i].nMax;
            if(nGap<gap){
                nGap=gap;
            }
            i=j;
        }
    }
    return nGap;
}