#include "DepthFirstPaths.h"

// 深度优先搜索类
DepthFirstSearch::DepthFirstSearch(BaseGraph &graph) :
    marked(graph.getPointNum(), false), step_count(0), source_graph(graph) {}

void DepthFirstSearch::dfs(int v) {
    marked[v] = true;
    ++step_count;
    for (int w : source_graph.adj(v))
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

void DepthFirstSearch::setMarked(int v) {
    marked[v] = true;
}

void DepthFirstSearch::unsetMarked(int v) {
    marked[v] = false;
}

bool DepthFirstSearch::isEmpty() {
    return source_graph.getPointNum() == 0;
}

BaseGraph &DepthFirstSearch::retGraph() {
    return source_graph;
}

// 图的路径查找类 —— 使用深度优先遍历
DepthFirstPaths::DepthFirstPaths(BaseGraph &graph, int v) :
    DepthFirstSearch(graph), prev(graph.getPointNum(), -1), start(v) {}

// @v: the private data member - start
void DepthFirstPaths::dfs(int v) {
    setMarked(v);
    for (int w : retGraph().adj(v)) {
        if (!isMarked(w)) {
            prev[w] = v;
            dfs(w);
        }
    }
}

bool DepthFirstPaths::hasPathTo(int v) {
    return isMarked(v);
}

// 先调用dfs(start)，再调用pathTo(v)
vector<int> DepthFirstPaths::pathTo(int v) {
    vector<int> path;
    if (!hasPathTo(v))
        return path;
    for (int i = v ; i != start ; i = prev[i])
        path.push_back(i);
    path.push_back(start);
    reverse(path);
    return path;
}

vector<vector<int>> DepthFirstPaths::pathToAll() {
    dfs(start);
    vector<vector<int>> paths;
    for (int i = 0 ; i < retGraph().getPointNum() ; ++i)
        paths.push_back(pathTo(i));
    return paths;
}

void DepthFirstPaths::printPath(int v) {
    vector<int> path = pathTo(v);
    int n = path.size();
    for (int i = 0 ; i < n-1 ; ++i)
        cout << path[i] << " -> ";
    cout << path[n-1] << endl;
}

void DepthFirstPaths::printPaths() {
    vector<vector<int>> paths = pathToAll();
    int n = paths.size();
    for (int i = 0 ; i < n ; ++i)
        printPath(i);
}

void DepthFirstPaths::reverse(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0, j = n-1 ; i < j ; ++i, --j)
        swap(vec, i, j);
}

void DepthFirstPaths::swap(vector<int> &vec, int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}
