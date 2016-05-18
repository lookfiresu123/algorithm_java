// get LISubsequenceOne with Dynamic Programming

#include <vector>
#include <iostream>

using namespace std;

// the time is n^2
class Solution1 {
public:
    vector<int> LISubsequenceOne(vector<int> &tmp) {
        int n = tmp.size();
        vector<int> ret;
        vector<int> dp(n, 1);   // dp[i] means the length of LIS which is ending at element with index i
        vector<int> prev(n, -1);// use to find the actual sequence not only its length

        // To compute dp[i], we look at all indices j < i and check both if dp[j]+1 > dp[i] and tmp[j] < tmp[i], if it's true we can update the current optimum for dp[i]. To find the global optimum for the array you can take the maximum value from dp[0 ... n-1]
        int maxlen = 1, best_end = 0;
        for (int i = 1 ; i < n ; ++i) {
            for (int j = i-1 ; j >= 0 ; --j) {
                if (dp[j]+1 > dp[i] && tmp[j] < tmp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxlen) {
                best_end = i;
                maxlen = dp[i];
            }
        }
        int pos = best_end;
        while (pos != -1) {
            ret.push_back(tmp[pos]);
            pos = prev[pos];
        }
        // reverse the ret
        reverse(ret);
        return ret;
    }
private:
    void reverse(vector<int> &vec);
    void swap(vector<int> &vec, int i, int j);
};

void Solution1::reverse(vector<int> &vec) {
    int lo = 0, hi = vec.size()-1;
    int l = lo, r = hi;
    while (l < r)
        swap(vec, l++, r--);
}

void Solution1::swap(vector<int> &vec, int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

void print(vector<int> &ret) {
    for (int i = 0 ; i < ret.size() ; ++i)
        cout << ret[i] << " ";
    cout << endl;
}

int main() {
    vector<int> tmp = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    Solution1 sol;
    vector<int> ret = sol.LISubsequenceOne(tmp);
    print(ret);
    return 0;
}
