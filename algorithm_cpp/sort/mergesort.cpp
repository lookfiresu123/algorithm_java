#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Mergesort {
private:
    vector<int> aux;            // 辅助数组
public:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    void merge(vector<int> &vec, int lo, int mid, int hi) {
        aux = vec;
        int i = lo, j = mid+1;
        for (int k = lo ; k <= hi ; ++k) {
            if (i > mid) vec[k] = aux[j++];
            else if (j > hi) vec[k] = aux[i++];
            else if (aux[i] <= aux[j])   vec[k] = aux[i++];
            else    vec[k] = aux[j++];
        }
    }

    void sort_helper(vector<int> &vec, int lo, int hi) {
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            sort_helper(vec, lo, mid);
            sort_helper(vec, mid+1, hi);
            merge(vec, lo, mid, hi);
        }
    }

    void sort(vector<int> &vec) {
        int lo = 0, hi = vec.size()-1;
        sort_helper(vec, lo, hi);
    }
};

int main() {
    vector<int> vec(50,0);
    srand(time(NULL));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    Mergesort sol;
    sol.sort(vec);
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    return 0;
}
