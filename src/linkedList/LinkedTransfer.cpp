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
//    声明函数
SNode *Reverse(pHead,4,8);
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
void Reverse(SNode *pHead,int from ,int to){
    SNode *pCur = pHead->pNext;
    int i;
    for (int j = 0; j <from-1 ; j++) {
        pHead=pCur;
        pCur = pCur->pNext;
    }
    SNode *pPre = pCur;
    pCur = pCur->pNext;
    to --;
    SNode *pNext;
    for (; k <to ; k++) {
        pNext = pCur->pNext;
        pCur-pNext = pHead->pNext;
        pHead->pNext=pCur;
        pPre->pNext=pNext;
        pCur=pNext;

    }

}

    /*SNode *head,*tail,*pnew;
    head->pNext=NULL;  //头节点指针域置NULL
    tail=head;  // 开始时尾指针指向头节点
//    tail=pHead1;  // 开始时尾指针指向头节点
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(i);
        tail->pNext=pnew;  //新节点插入到表尾
        tail=pnew;   //为指针指向当前的尾节点
    }*/



//    Print(pHead1);
//    Print(head);
    return 0;
}
// 打印链表
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList函数执行，链表为空\n");
    } else {
//        pHead= pHead->pNext; // 去掉了头结点
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
        p=next;
    }
}