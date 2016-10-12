#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  链表插入，头插法和尾插法
 */

typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

// 声明函数
void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    // 头插法
    SNode *pHead;
    int i;
    pHead = NULL;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(i);
        if (pHead == NULL) {
            pHead = p;
        } else {
            p->pNext = pHead->pNext;
            pHead->pNext = p;
        }
    }
    printf("头插法：\n");
    Print(pHead);

    // 如果是简单的测试，可以倒序循环，使用头插法，得到与尾插法一样的结果。
/*    SNode *pHead = new SNode(0);
    for (i = 10; i >0; i--) {
    SNode *p = new SNode(i);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);*/

    // 尾插法
    pHead = NULL;
    SNode *end;
    end = NULL; // 尾指针置为空
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(i);
        if (pHead == NULL) {
            pHead = p;
        } else {
            end->pNext = p;
        }
        end = p;
    }
    if (end != NULL)
        end->pNext = NULL;

    Print(pHead);


    return 0;
}

// 打印链表
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList函数执行，链表为空\n");
    } else {
        pHead = pHead->pNext; // 去掉了头结点0
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