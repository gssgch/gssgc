#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  排序链表去重
 *  给定排序后的链表，删除重复元素，只保留重复元素第一次出现的结点。
 *
 *  完全未排序的链表，最快的去重时间复杂度是O(N*logN)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    声明函数
void DeleteDuplicateNode(SNode *pHead);

void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead = new SNode(0);
    int data[] = {2, 3, 3, 4, 5, 5, 7, 8, 8, 8, 9, 9, 100};
    int size = sizeof(data) / sizeof(int);
    for (int i = size - 1; i >= 0; i--) {
        SNode *p = new SNode(data[i]);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    DeleteDuplicateNode(pHead);
    Print(pHead);
    Destroy(pHead);
    return 0;
}

// 重复元素去重 保留第一个重复的数据
void DeleteDuplicateNode(SNode *pHead) {
    SNode *pPre = pHead->pNext;
    SNode *pCur;
    while (pPre) {
        pCur = pPre->pNext;
        if (pCur && pCur->value == pPre->value) {
            pPre->pNext = pCur->pNext;
            delete pCur;
        } else {
            pPre = pCur;
        }
    }
}

// 重复元素去重 保留最后一个重复的数据
void DeleteDuplicateNode2(SNode *pHead) {
    SNode *pPre = pHead->pNext;
    SNode *pCur;
    SNode *pNext;
    while (pCur) {
        pNext = pCur->pNext;
        while (pNext && (pCur->value == pNext->value)) {
            pPre->pNext = pNext;
            delete pCur;
            pCur = pNext;
            pNext = pCur->pNext;
        }
        pPre = pCur;
        pCur = pNext;
    }
}
// 重复元素去重 删除所有重复的元素
void DeleteDuplicateNode3(SNode *pHead) {
    SNode *pPre = pHead;
    SNode *pCur = pPre->pNext;
    SNode *pNext;
    bool  bDup;
    while (pCur) {
        pNext = pCur->pNext;
        bDup= false;
        while (pNext && (pCur->value == pNext->value)) {
            pPre->pNext = pNext;
            delete pCur;
            pCur = pNext;
            pNext = pCur->pNext;
            bDup= true;
        }
        if(bDup){// 此时pCur与原数据重复，删除
            pPre->pNext=pNext;
            delete pCur;
        }else{ // pCur未发现重复，则pPre后移
            pPre=pCur;
        }
        pPre = pCur;
        pCur = pNext;
    }
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
