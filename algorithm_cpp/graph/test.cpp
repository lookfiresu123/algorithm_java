#include "BaseGraph/BaseGraph.h"
#include "DepthFirstPaths/DepthFirstPaths.h"
#include "BreadthFirstPaths/BreadthFirstPaths.h"

int main() {
    map<pair<int, int>, int> mymap;
    int point_num;
    cin >> point_num;
    int x, y, len;
    while (cin >> x >> y >> len) {
        mymap[pair<int, int>(x, y)] = len;
    }
    BaseGraph bg(point_num, mymap);
    cout << "------------------------------------" << endl;
    cout << "The graph layout is below : " << endl;
    bg.print();
    cout << "------------------------------------" << endl;
    cout << "The DepthFirstPaths layout is below : " << endl;
    DepthFirstPaths dfp(bg, 0);
    dfp.printPaths();
    cout << "------------------------------------" << endl;
    cout << "The BreadthFirstPaths layout is below : " << endl;
    BreadthFirstPaths bfs(bg, 0);
    bfs.printPaths();
    return 0;
}
