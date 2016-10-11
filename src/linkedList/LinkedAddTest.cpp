#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
/**
 *  链表相加练习
 *  两个链表，表示两个非负整数。数字逆序存储在链表中，每个结点存储一个数字，计算两个数的和，返回和的链表头指针。
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;
//    下面这个相当于构造函数
    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;
// 这里的SNode 相当于struct tagSNode的别名，在声明变量的时候就可：SNode s1;
// 如果没有typedef就必须用 struct tagSNode SNode;

//    声明函数
SNode *Add(SNode *pHead1, SNode *pHead2);
void Print(SNode *pHead1);
void Destroy(SNode *pHead1);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead1 = new SNode(0);
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(rand() % 10);
        /* 下面使用的是头插法   头插法 插入一个节点的时间复杂度是O(1)
         *  假定pHead1已经有若干节点，把p的next指向pHead的next，
         *  然后把phead本来的next断掉，指向p
         *  这样就相当于在前面插入了一个节点p
         *  在java语法里是赋值，在这里是指指针的指向，就是前面指向后面。
         * */
        p->pNext = pHead1->pNext;
        pHead1->pNext = p; // 把新结点p插入到表pHead1中，即pHead指向p节点
    }
    SNode *pHead2 = new SNode(0); // 这里创建的头结点的唯一意义就是拿到pNext指针
    for (i = 0; i < 9; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }
    Print(pHead1);
    Print(pHead2);
    SNode *pSum = Add(pHead1, pHead2);
    Print(pSum);
    Destroy(pHead1);
    Destroy(pHead2);
    Destroy(pSum);
    return 0;
}


SNode *Add(SNode *pHead1, SNode *pHead2) {
    SNode *pSum = new SNode(0);
    SNode *pTail = pSum;// 新结点插入到pTail后面
    SNode *p1 = pHead1->pNext;
    SNode *p2 = pHead2->pNext;
    SNode *pCur;
    int carry = 0; // 进位
    int value;
    while (p1 && p2) {
        value = p1->value + p2->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur; // 新结点链接到pTail后面
        pTail = pCur;

        p1 = p1->pNext;// 处理下一位
        p2 = p2->pNext;

    }

// 处理较长的链
    SNode *p = p1 ? p1 : p2;
    while (p) {
        value = p->value + carry;
        carry = value / 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;
        p = p->pNext;
    }

// 处理可能存在的进位
    if (carry != 0) {
        pTail->pNext = new SNode(carry);
    }
    return pSum;

}

// 打印链表
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList函数执行，链表为空\n");
    } else {
        while (NULL != pHead) {

            printf("%d ", pHead->value);
            pHead = pHead->pNext;
            if (pHead != NULL){
                printf("%s ", "->");
            }
        }
        printf("\n");
    }
}
void Destroy(SNode *head) {
    SNode *p,*q;
    p=head;
    while (p->pNext!=NULL) {
        q=p->pNext;
        p->pNext=q->pNext;
        free(q);
    }
    free(p);
}