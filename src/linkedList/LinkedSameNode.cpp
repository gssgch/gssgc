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
 *
 *  单链公共结点问题中，如果链表存在环，则需要使用快慢指针的方式计算公共结点
 *      两个指针，每次分布移动一个/两个结点
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
void swap(void *a,void *b);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead1 = new SNode(0);
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }
    SNode *pHead2 = new SNode(0);
    for (i = 0; i < 9; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }

    Print(pHead1);
    Print(pHead2);
    FindFirstSameNode(pHead1,pHead2);
    Print(pHead1);
    Print(pHead2);
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
SNode *FindFirstSameNode(SNode *pA,SNode *pB) {
    // 因为有头指针，所以指向第一个有效结点
    pA=pA->pNext;
    pB=pB->pNext;

    // 计算两个链表的长度
    int nA = CalcLength(pA);
    int nB = CalcLength(pB);
     // 这下面的转换只是为了 确保B比A长， 好写代码，没有实质意义， 但 swap的代码有问题
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
    }
        return NULL;
}
// 不知道这个swap函数怎么写
void swap(void *a,void *b,size_t size)
{
    unsigned char *p1=(unsigned char *)a;          //强制类型转换
    unsigned char *p2=(unsigned char *)b;
    Unsigned char temp;                         //字节型的嫁衣
    while(size--)
    {
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2++;
    }
}
//void swap(int &a, int &b) {
//    //方法一：
//    int tmp = 0;
//    tmp = b;
//    b = a;
//    a = tmp;
//    //方法二：
//    //a = a+b;
//    //b = a-b;
//    //a = a -b;
//    //方法三：
//    //a ^= b ^= a ^= b;
//    //方法四：
//    //a = a+b-(b=a);
//}


void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
