#include "BreadthFirstPaths.h"

// 广度优先搜索类
BreadthFirstSearch::BreadthFirstSearch(BaseGraph &graph) :
    marked(graph.getPointNum(), false), step_count(0), source_graph(graph) {}

void BreadthFirstSearch::bfs(int v) {
    queue<int> q;
    marked[v] = true;
    q.push(v);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int w : source_graph.adj(t)) {
            if (!marked[w]) {
                q.push(w);
                marked[w] = true;
            }
        }
    }
}

bool BreadthFirstSearch::isMarked(int v) {
    return marked[v];
}

int BreadthFirstSearch::getStepCount() {
    return step_count;
}

void BreadthFirstSearch::clear() {
    int n = marked.size();
    for (int i = 0 ; i < n ; ++i)
        marked[i] = false;
    step_count = 0;
}

bool BreadthFirstSearch::isLinkedAll() {
    if (isEmpty())
        return false;
    bfs(0);
    for (auto f : marked)
        if (!f)
            return false;
    return true;
}

void BreadthFirstSearch::setMarked(int v) {
    marked[v] = true;
}

void BreadthFirstSearch::unsetMarked(int v) {
    marked[v] = false;
}

bool BreadthFirstSearch::isEmpty() {
    return source_graph.getPointNum() == 0;
}

BaseGraph &BreadthFirstSearch::retGraph() {
    return source_graph;
}

// 图的路径查找类 —— 使用深度优先遍历
BreadthFirstPaths::BreadthFirstPaths(BaseGraph &graph, int v) :
    BreadthFirstSearch(graph), prev(graph.getPointNum(), -1), start(v) {}

// @v: the private data member - start
void BreadthFirstPaths::bfs(int v) {
    queue<int> q;
    setMarked(v);
    q.push(v);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int w : retGraph().adj(t)) {
            if (!isMarked(w)) {
                prev[w] = t;
                q.push(w);
                setMarked(w);
            }
        }
    }
}

bool BreadthFirstPaths::hasPathTo(int v) {
    return isMarked(v);
}

// 先调用bfs(start)，再调用pathTo(v)
vector<int> BreadthFirstPaths::pathTo(int v) {
    vector<int> path;
    if (!hasPathTo(v))
        return path;
    for (int i = v ; i != start ; i = prev[i])
        path.push_back(i);
    path.push_back(start);
    reverse(path);
    return path;
}

vector<vector<int>> BreadthFirstPaths::pathToAll() {
    bfs(start);
    vector<vector<int>> paths;
    for (int i = 0 ; i < retGraph().getPointNum() ; ++i)
        paths.push_back(pathTo(i));
    return paths;
}

void BreadthFirstPaths::printPath(int v) {
    vector<int> path = pathTo(v);
    int n = path.size();
    for (int i = 0 ; i < n-1 ; ++i)
        cout << path[i] << " -> ";
    cout << path[n-1] << endl;
}

void BreadthFirstPaths::printPaths() {
    vector<vector<int>> paths = pathToAll();
    int n = paths.size();
    for (int i = 0 ; i < n ; ++i)
        printPath(i);
}

void BreadthFirstPaths::reverse(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0, j = n-1 ; i < j ; ++i, --j)
        swap(vec, i, j);
}

void BreadthFirstPaths::swap(vector<int> &vec, int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}
