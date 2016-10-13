#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  排序划分
 *  给定一个链表和一个值x，将链表划分成两部分，使得划分后小于x的结点在前，
 *  大于等于x的结点在右，在这两部分中要保持原链表中的出现顺序。
 *  分析：
 *  申请两个指针p1和p2，小于x的添加到p1，其他的添加到p2，最后将p2链接到p的末端即可。
 *
 *  时间复杂度是O(N),空间复杂度是O(1)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    声明函数
void Partition(SNode *pHead,int pivotKey);
void Print(SNode *pHead);
void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead = new SNode(0);
//    pHead->pNext=NULL;
    for (int i = 0; i < 10; i++) {
        SNode *p = new SNode(rand()%100);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    Partition(pHead,50);
    Print(pHead);
    Destroy(pHead);
    return 0;
}

//
void Partition(SNode *pHead,int pivotKey) {
    // 两个链表的头指针
    SNode *pLeftHead = new SNode(0);
    SNode *pRightHead = new SNode(0);

    // 两个链表的当前最后一个元素(就是尾结点)
    SNode* left = pLeftHead;
    SNode* right = pRightHead;
    SNode* p = pHead->pNext;
    while (p) { // 遍历原链表
        if (p->value < pivotKey) {
            left->pNext = p;
            left = p;
        } else {
            right->pNext = p;
            right = p;
        }
        p = p->pNext;
    }
    // 将right链接到left尾部
    left->pNext=pRightHead->pNext;
    right->pNext=NULL;

        // 将整理好的链表赋值给当前链表头部
        pHead->pNext=pLeftHead->pNext;

        delete pLeftHead;
        delete pRightHead;
}

// 打印链表
void Print(SNode *pHead) {
    if (NULL == pHead) {
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

void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
