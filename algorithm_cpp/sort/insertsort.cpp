#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Insertsort {
public:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    void sort(vector<int> &vec) {
        int N = vec.size();
        for (int i = 1 ; i < N ; ++i)
            for (int j = i ; j > 0 ; --j)
                if (vec[j] < vec[j-1])
                    swap(vec, j, j-1);
    }
};

int main() {
    vector<int> vec(50,0);
    srand(time(NULL));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    Insertsort sol;
    sol.sort(vec);
    for_each(vec.begin(), vec.end(), [](int x){ cout << x << " "; });
    cout << endl;
    return 0;
}
