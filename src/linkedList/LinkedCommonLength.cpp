#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  单链公共结点问题
 *  给定两个单向链表，计算两个链表的第一个公共结点，若没有公共结点，返回空。
 *  分析：
 *  链表m和n,m>=n  前面m-n个结点一定是没有公共结点的
 *
 *  算法：先分别遍历两个链表得到长度，长链表空转|m-n|次，同步遍历两链表，直到找到相同结点或到链表结束。
 *
 *  时间复杂度是O(m+n)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    声明函数
int CalcLength(SNode *p);
SNode* FindFirstSameNode(SNode *p1,SNode *p2);
void Print(SNode *pHead);
void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}

int CalcLength(SNode *p) {
int nLen =0;
    while(p){
        p=p->pNext;
        nLen++;
    }
    return nLen;
}
// 打印链表
SNode FindFirstSameNode(SNode *pA,SNode *pB) {
    // 因为有头指针，所以指向第一个有效结点
    pA=pA->pNext;
    pB=pB->pNext;

    // 计算两个链表的长度
    int nA = CalcLength(pA);
    int nB = CalcLength(pB);
    if(nA>nB){
        swap(pA,pB);
        swap(nA,nB);
    }

    // 空转nB-nA次
    for(int i =0;i<nB-nA;i++){
        pB=pB->pNext;
    }

    // 齐头并进
    while(pA){
        if(pA==pB){
            return pA;
        }
        pA=pA->pNext;
        pB=pB->pNext;
        return NULL;
    }

}

void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
