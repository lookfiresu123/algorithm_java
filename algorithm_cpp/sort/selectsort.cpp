#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// 冒泡排序
class Selectsort {
public:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    void sort(vector<int> &vec) {
        int N = vec.size();
        while (N > 1) {
            for (int i = 0 ; i < N-1 ; ++i)
                if (vec[i] > vec[i+1])
                    swap(vec, i, i+1);
            N--;
        }
    }
};

int main() {
    vector<int> vec(50,0);
    srand(time(NULL));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    Selectsort sol;
    sol.sort(vec);
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    return 0;
}
