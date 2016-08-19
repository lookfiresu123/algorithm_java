#ifndef _H_BASEGRAPH
#define _H_BASEGRAPH 1

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <string>

using namespace std;

class BaseGraph {
public:
    BaseGraph(int x, map<pair<int, int>, int> &mymap);  // 构造一个无向图
    int getPointNum();                              // 返回图的顶点总数
    int getEdgeNum();                               // 返回图的边总数
    void addEdge(int v, int w, int len);            // 在无向图中增加一条边E(v,w)
    vector<int> adj(int v);                         // 返回和v相邻的所有顶点
    int degree(int v);                              // 计算顶点v的度数
    int maxDegree();                                // 计算所有顶点的最大度数
    double avgDegree();                             // 计算所有顶点的平均度数
    int numberOfSelfLoops();                        // 计算自环的个数
    void print();                                   // 打印图

private:
    int point_num;                  // 图中顶点的个数
    int edge_num;                   // 图中边的个数
    vector<vector<int>> edges;      // 边集合，其中每个索引为某个顶点，edges[i][j]等价于E(i,j)是否存在
    vector<vector<int>> edges_len;  // 边长度集合，其中每个索引为某个顶点，edges_len[i][j]等价于E(i,j)的长度
};

class DepthFirstSearch {
public:
    DepthFirstSearch(BaseGraph &graph);     // 图的深度优先搜索遍历
    void dfs(int start);
    bool isMarked(int v);
    int getStepCount();
    void clear();
    bool isLinkedAll();
    bool isEmpty();
private:
    vector<bool> marked;
    int step_count;                         // 深度优先遍历所需的步数
    BaseGraph source_graph;                 // 原图
};


#endif
