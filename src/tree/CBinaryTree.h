#include <tchar.h>
#include<stdlib.h>

#ifndef GSSGC_CBINARYTREE_H
#define GSSGC_CBINARYTREE_H

typedef struct tagSTreeNode {
    int value;
    tagSTreeNode *pLeft;
    tagSTreeNode *pRight;

    tagSTreeNode(int v) : value(v), pLeft(NULL), pRight(NULL) {};
} STreeNode;

typedef void (*VISIT)(int value);

class CBinaryTree {
private:
    STreeNode *m_pRoot;
private:
    void Destroy();

    bool _Insert(STreeNode *&pRoot, int value); // µÝ¹é
    bool _Insert2(int value); // ·ÇµÝ¹é
    bool _PreOrder(STreeNode *pRoot, VISIT visit) const; // µÝ¹é
    void _PreOrder2(VISIT visit) const; // ·ÇµÝ¹é
    bool _InOrder(STreeNode *pRoot, VISIT visit) const; // µÝ¹é
    void _InOrder2(VISIT visit) const; // ·ÇµÝ¹é
    void _InOrder3(VISIT visit) const; // ·ÇµÝ¹é
    bool _PostOrder(STreeNode *pRoot, VISIT visit) const; // µÝ¹é
    void _PostOrder2(VISIT visit) const; // ·ÇµÝ¹é
    bool _DeleteChindIess(STreeNode *pParent, STreeNode *pNode) const; // pNodeÎÞ×Ó
    bool _DeleteSingleSon(STreeNode *pParent, STreeNode *pNode) const; // pNodeÊÇpParentÎ¨Ò»½áµã


public:
    CBinaryTree();

    ~CBinaryTree();

    bool Insert(int value);

    bool Delete(int value);

    STreeNode* Find(int value) const;

    void PreOrder(VISIT visit) const;

    void InOrder(VISIT visit) const;

    void PostOrder(VISIT visit) const;

};

#endif //GSSGC_CBINARYTREE_H
