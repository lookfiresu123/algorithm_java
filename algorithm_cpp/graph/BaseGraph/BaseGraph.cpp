#include "BaseGraph.h"

// 基本图类
BaseGraph::BaseGraph(int x, map<pair<int, int>, int> &mymap) :
    point_num(x), edge_num(mymap.size()),
    edges(x, vector<int>(x, 0)), edges_len(x, vector<int>(x, INT_MAX)) {
    for (auto it = mymap.begin() ; it != mymap.end() ; ++it) {
        edges[it->first.first][it->first.second] = 1;
        edges[it->first.second][it->first.first] = 1;
        edges_len[it->first.first][it->first.second] = it->second;
        edges_len[it->first.second][it->first.first] = it->second;
    }
}

int BaseGraph::getPointNum() {
    return point_num;
}

int BaseGraph::getEdgeNum() {
    return edge_num;
}

void BaseGraph::addEdge(int v, int w, int len) {
    edges[v][w] = 1;
    edges_len[v][w] = len;
    ++edge_num;
}

vector<int> BaseGraph::adj(int v) {
    vector<int> res;
    for (int i = 0 ; i < point_num ; ++i)
        if (i != v && edges[v][i] == 1)
            res.push_back(i);
    return res;
}

int BaseGraph::degree(int v) {
    return adj(v).size();
}

int BaseGraph::maxDegree() {
    int max = 0, t;
    for (int i = 0 ; i < point_num ; ++i) {
        t = adj(i).size();
        max = max < t ? t : max;
    }
    return max;
}

double BaseGraph::avgDegree() {
    return 2.0 * edge_num / point_num;
}

int BaseGraph::numberOfSelfLoops() {
    int count = 0;
    for (int i = 0 ; i < point_num ; ++i)
        if (edges[i][i] == 1)
            ++count;
    return count;
}

void BaseGraph::print() {
    for (int i = 0 ; i < point_num ; ++i) {
        string s = to_string(i);
        for (int j = 0 ; j < point_num ; ++j) {
            if (edges[i][j] == 1)
                s += (" -> " + to_string(j));
        }
        cout << s << endl;
    }
}

// 深度优先搜索类
DepthFirstSearch::DepthFirstSearch(BaseGraph &graph) :
    marked(graph.getPointNum(), false), step_count(0), source_graph(graph) {}

void DepthFirstSearch::dfs(int start) {
    marked[start] = true;
    ++step_count;
    for (int w : source_graph.adj(start))
        if (!marked[w])
            dfs(w);
}

bool DepthFirstSearch::isMarked(int v) {
    return marked[v];
}

int DepthFirstSearch::getStepCount() {
    return step_count;
}

void DepthFirstSearch::clear() {
    int n = marked.size();
    for (int i = 0 ; i < n ; ++i)
        marked[i] = false;
    step_count = 0;
}

bool DepthFirstSearch::isLinkedAll() {
    if (isEmpty())
        return false;
    dfs(0);
    for (auto f : marked)
        if (!f)
            return false;
    return true;
}

bool DepthFirstSearch::isEmpty() {
    return source_graph.getPointNum() == 0;
}
