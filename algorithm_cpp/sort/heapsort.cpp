#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Heapsort {
public:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    // 将结点k在[k, N]之间下沉
    void sink(vector<int> &vec, int k, int N) {
        while (2*k <= N) {                          // 判断结点k是否有子节点
            int i = 2*k;
            if (i < N && vec[i] < vec[i+1]) ++i;    // 在两个子节点中选择较大的那个
            if (vec[k] >= vec[i])   break;          // 若父结点比较大的子节点还大，则退出循环
            swap(vec, k, i);                        // 交换父子结点的值
            k = i;                                  // 更新父结点
        }
    }

    // 构造堆
    void create_heap(vector<int> &vec) {
        vec.insert(vec.begin(), 0);
        int N = vec.size()-1;
        int k = N / 2;
        while (k >= 1)          // 连续下沉
            sink(vec, k--, N);
    }

    // 堆排序
    void sort_helper(vector<int> &vec, int lo, int hi) {
        if (lo < hi) {
            int N = hi;
            while (lo < N) {
                swap(vec, lo, N--);     // 将最大数交换到尾部，并将尾部减1
                sink(vec, lo, N);       // 下沉根节点
            }
        }
    }


    void sort(vector<int> &vec) {
        create_heap(vec);               // 构造堆
        int lo = 1, hi = vec.size()-1;
        sort_helper(vec, lo, hi);       // 堆排序
        vec.erase(vec.begin());
    }
};

int main() {
    vector<int> vec(50,0);
    srand(time(NULL));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    Heapsort sol;
    sol.sort(vec);
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    return 0;
}
