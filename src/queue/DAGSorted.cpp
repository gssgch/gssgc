#include <stdio.h>
#include <tchar.h>
#include<queue>

/**
 *  对有向无环图进行拓扑排序  将图中所有顶点排序成线性序列
 *  分析：
 *  选择一个没有前驱（入度为0）的顶点并且输出它
 *  从网中删去该顶点，并且删去从该顶点发出的全部有向边
 *  重复上述两步，直到剩余的网中不再存在没有前驱的顶点为止
 *
 *  可用于垃圾回收
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    声明函数


int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}
// 结点数为n，用领结矩阵gragh[n][n] 存储边权，
// 用indegree[n]存储每个结点的入度
void topologic(int* toposort){
    int cnt =0; // 当前拓扑排序列表中有多少结点
    queue<int> q;  // 保存入度为0的结点，还可以用栈甚至随机取
    int i;
    for (i = 0;  i<n ; i++) {
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cur; // 当前入度为0的结点
    while (!q.empty()){
        cur =q.front();
        q.pop();
        toposort[cnt++] = cur;
        for (i = 0;  i< n; i++) {
            if(gragh[cur][i]!=0){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
}
