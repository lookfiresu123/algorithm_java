#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Quicksort {
public:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    void sort_helper(vector<int> &vec, int lo, int hi) {
        if (lo < hi) {      // 若子数组有两个以上元素时，才进行排序
            int base = vec[lo];
            int l = lo, r = hi+1;   // l初始化为首迭代器，r初始化为尾后迭代器
            while (true) {
                while (l < hi && vec[++l] < base);      // 从左往右找到第一个不小于base的数
                while (r > lo && vec[--r] >= base);     // 从右往左找到第一个小于base的数
                if (r <= l) break;          // 若r小于或等于l，则不交换并退出循环
                swap(vec, l, r);
            }
            swap(vec, lo, r);       // 将base移至合适的位置
            sort_helper(vec, lo, r-1);
            sort_helper(vec, r+1, hi);
        }
    }

    void sort(vector<int> &vec) {
        int lo = 0;
        int hi = vec.size()-1;
        sort_helper(vec, lo, hi);
    }
};

int main() {
    vector<int> vec(50,0);
    srand(time(NULL));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    Quicksort sol;
    sol.sort(vec);
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    return 0;
}
