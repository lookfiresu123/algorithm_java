#ifndef _H_BREADTHFIRSTPATHS
#define _H_BREADTHFIRSTPATHS 1

#include <queue>
#include "../BaseGraph/BaseGraph.h"

// 图的广度优先搜索类
class BreadthFirstSearch {
public:
    BreadthFirstSearch(BaseGraph &graph);   // 图的广度优先搜索遍历
    virtual void bfs(int v);                // 从顶点v开始执行广度优先遍历
    bool isMarked(int v);                   // 判断顶点v是否已被遍历
    int getStepCount();                     // 获得遍历的总步数
    void clear();                           // 清空marked，并把step_count重置为0
    bool isLinkedAll();                     // 判断该图是否为连通图
    bool isEmpty();                         // 判断该图是否为空
    void setMarked(int v);                  // 设置marked[v] = true
    void unsetMarked(int v);                // 设置marked[v] = false
    BaseGraph &retGraph();                  // 返回source_graph
private:
    vector<bool> marked;                    // 若marked[v] = true，则表示顶点v已被遍历；否则，还未被遍历
    int step_count;                         // 广度优先遍历所需的步数
    BaseGraph source_graph;                 // 原图
};

// 图的路径查找类 —— 使用深度优先遍历
class BreadthFirstPaths : public BreadthFirstSearch {
public:
    BreadthFirstPaths(BaseGraph &graph, int v); // 利用广度优先遍历得到结点v到每个结点的路径
    void bfs(int v);                            // 从顶点v开始执行广度优先遍历
    bool hasPathTo(int v);                      // 判断是否有从start到v的路径
    vector<int> pathTo(int v);                  // 返回从start到v的路径
    vector<vector<int>> pathToAll();            // 返回从start到所有顶点的路径
    void printPath(int v);                      // 打印从start到v的路径
    void printPaths();                          // 打印从start到所有顶点的路径
private:
    vector<int> prev;                           // prev[i]=j 表示 j->i为路径的一部分（或j为i的前驱）
    int start;                                  // 路径的起点
    void reverse(vector<int> &vec);
    void swap(vector<int> &vec, int i, int j);
};

#endif
