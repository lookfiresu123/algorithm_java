// get LiSubsequenceOne with sort and LCS

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> LISubsequenceOne(vector<int> &tmp) {
        vector<int> ret;
        if (tmp.empty())
            return ret;
        vector<int> tmp_sorted = quickSort(tmp);
        ret = LCSubsequenceOne(tmp, tmp_sorted);
        return ret;
    }
private:
    vector<int> quickSort(vector<int> tmp_copy);
    void quickSort_helper(vector<int> &data, int lo, int hi);
    void swap(vector<int> &data, int i, int j);
    vector<int> LCSubsequenceOne(vector<int> &tmp1, vector<int> &tmp2);
    void initializeArray(vector<vector<int>> &vec, vector<int> &tmp1, vector<int> &tmp2);
    vector<int> LCSubsequenceOne_helper(vector<vector<int>> &vec, vector<int> &tmp1, vector<int> &tmp2, int i, int j);
};

vector<int> Solution::quickSort(vector<int> tmp_copy) {
    int lo = 0, hi = tmp_copy.size()-1;
    quickSort_helper(tmp_copy, lo, hi);
    return tmp_copy;
}

void Solution::quickSort_helper(vector<int> &data, int lo, int hi) {
    if (lo < hi) {
        int l = lo, r = hi + 1;
        int base = data[lo];
        while (true) {
            while (l < hi && data[++l] < base) ;
            while (r > lo && data[--r] >= base) ;
            if (r <= l)  break;
            swap(data, l, r);
        }
        swap(data, lo, r);
        quickSort_helper(data, lo, r-1);
        quickSort_helper(data, r+1, hi);
    }
}

void Solution::swap(vector<int> &data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

vector<int> Solution::LCSubsequenceOne(vector<int> &tmp1, vector<int> &tmp2) {
    int m = tmp1.size(), n = tmp2.size();
    vector<vector<int>> vec(m+1, vector<int>(n+1, 0));
    initializeArray(vec, tmp1, tmp2);
    vector<int> ret;
    ret = LCSubsequenceOne_helper(vec, tmp1, tmp2, m, n);
    return ret;
}

void Solution::initializeArray(vector<vector<int>> &vec, vector<int> &tmp1, vector<int> &tmp2) {
    int m = tmp1.size(), n = tmp2.size();
    for (int i = 1 ; i < m+1 ; ++i) {
        for (int j = 1 ; j < n+1 ; ++j) {
            if (tmp1[i-1] == tmp2[j-1])
                vec[i][j] = vec[i-1][j-1] + 1;
            else
                vec[i][j] = vec[i-1][j] > vec[i][j-1] ? vec[i-1][j] : vec[i][j-1];
        }
    }
}

vector<int> Solution::LCSubsequenceOne_helper(vector<vector<int>> &vec, vector<int> &tmp1, vector<int> &tmp2, int i, int j) {
    if (i == 0 || j == 0)
        return vector<int>();
    else if (tmp1[i-1] == tmp2[j-1]) {
        vector<int> ret = LCSubsequenceOne_helper(vec, tmp1, tmp2, i-1, j-1);
        ret.push_back(tmp1[i-1]);
        return ret;
    } else {
        if (vec[i][j-1] < vec[i-1][j])
            return LCSubsequenceOne_helper(vec, tmp1, tmp2, i-1, j);
        else
            return LCSubsequenceOne_helper(vec, tmp1, tmp2, i, j-1);
    }
}

void print(vector<int> &one) {
    cout << "reading out a LIS" << endl;
    for (int i = 0 ; i < one.size() ; ++i)
        cout << one[i] << " ";
    cout << endl;
}

int main() {
    vector<int> tmp = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    Solution sol;
    vector<int> one = sol.LISubsequenceOne(tmp);
    print(one);
    return 0;
}
