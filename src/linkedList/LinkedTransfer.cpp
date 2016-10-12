#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  链表部分翻转
 *  给定一个链表，翻转该链表从m到n的位置，要求直接翻转而非申请新空间。
 *   时间复杂度 O(n)  空间复杂度 O(1)
 *   分析：
 *   空转m-1次，找到第m-1个结点，即开始翻转的第一个结点的前驱，记住head
 *   以head为起始结点遍历n-m次，第i次时，将找到的结点插入到head的next中即可。 即头插法
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;
    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

// 声明函数
void Reverse(SNode *pHead, int a, int b);

void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    SNode *pHead = new SNode(0);
    int i;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(rand() % 100);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    Reverse(pHead, 4, 7); //两边都包含
    Print(pHead);
    Destroy(pHead);
    return 0;
}

/**
 * 翻转链表
 * @param pHead
 * @param from
 * @param to
 * @return
 */
void Reverse(SNode *pHead, int from, int to) {
    SNode *pCur = pHead->pNext;
    int i;
    for (i = 0; i < from - 1; i++) { // 空转 m-1次
        pHead = pCur;
        pCur = pCur->pNext;
    }
    // 空转结束后，pCur在m的位置
    // pHead的位置在m-1的位置，即m的前一位

    SNode *pPre = pCur;
    SNode *pNext;
    printf("\n000,pHead=%d,pPre=%d,pCur=%d,pNext=%d",  pHead->value,pPre->value,pCur->value,pNext->value);
    // 循环前，pPre和pCur都在m处，即替换的第一位，
    pCur = pCur->pNext; // pCur先走一步，因为需要从m的下一位出开始往前换
    to--; // n-m-1次替换次数

    /** 这里会替换n-m-1次，就是说翻转三个数，会循环替换两次
     *  所以to要先-- ，以保证循环的次数正确
     */

    for (; i < to; i++) {
        pNext = pCur->pNext;  // pNext指向下一位， 第一次时，pPre在m处,pCur在m+1处,pNext在m+2处，把pCur翻转到pPre的前面
        printf("\n111,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pCur->pNext = pHead->pNext; // 把pCur的指针指向pHead
        printf("\n222,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pHead->pNext = pCur; // 赋值
        printf("\n333,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pPre->pNext = pNext; // pPre的指针指向pNext
        printf("\n444,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pCur = pNext; // pNext的值给pCur
        printf("\n555,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
    }
}

// 打印链表
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList函数执行，链表为空\n");
    } else {
        pHead = pHead->pNext; // 去掉了头结点
        while (NULL != pHead) {
            printf("%d ", pHead->value);
            pHead = pHead->pNext;
            if (pHead != NULL) {
                printf("%s ", "->");
            }
        }
        printf("\n");
    }
}

// 老师版destroy
void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}