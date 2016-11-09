#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>
#include "CBinaryTree.h"

using namespace std;


/**
 * 树的基本操作
 */

// 二叉查找树的查找
STreeNode *CBinaryTree::Find(int value) const {
    if (!m_pRoot) {
        return NULL;
    }
    STreeNode *pNode = m_pRoot;
    while (pNode) {
        if (value < pNode->value) {
            pNode = pNode->pLeft;
        } else if (value > pNode->value) {
            pNode = pNode->pRight;
        } else {
            return pNode;
        }
    }
    return NULL;
}

// 二叉查找树插入  递归
bool CBinaryTree::Insert(int value) {
    return _Insert(m_pRoot, value);
}

bool CBinaryTree::_Insert(STreeNode *&pRoot, int value) {
    if (!pRoot) {
        pRoot = new STreeNode(value);
        return true;
    }
    STreeNode *pNode = m_pRoot;
    if (value < pNode->value) {
        return _Insert(pRoot->pLeft, value);
    }
    if (value > pNode->value) {
        return _Insert(pRoot->pRight, value);
    }
    return false;
}


//    声明函数
STreeNode *CBinaryTree::Find(int value) const;

bool CBinaryTree::Insert(int value);

//
int _tmain(int argc, _TCHAR *argv[]) {

    STreeNode *a;
    CBinaryTree tr;
//    for (int i = 0; i < 10 ; ++i) {
//    tr.Find(2);
//    tr.Insert(rand() % 10);
//    }
//    std::cout << tree.Find(15) << std::endl;

//    std::cout <<  << std::endl;
    return 0;
}
