#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string LCSubsequenceOne(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> vec(m+1, vector<int>(n+1, 0));
        initializeArray(vec, s1, s2);
        return LCSubsequenceOne_helper(vec, s1, s2, m, n);
    }
    vector<string> LCSubsequenceAll(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> vec(m+1, vector<int>(n+1, 0));
        initializeArray(vec, s1, s2);
        vector<string> ret;
        ret = LCSubsequenceAll_helper(vec, s1, s2, m, n);
        return ret;
    }
private:
    string LCSubsequenceOne_helper(vector<vector<int>> &vec, string &s1, string &s2, int i, int j);
    vector<string> LCSubsequenceAll_helper(vector<vector<int>> &vec, string &s1, string &s2, int i, int j);
    void initializeArray(vector<vector<int>> &vec, string &s1, string &s2);
};

void Solution::initializeArray(vector<vector<int>> &vec, string &s1, string &s2) {
    int m = s1.length(), n = s2.length();
    for (int i = 1 ; i < m+1 ; ++i) {
        for (int j = 1 ; j < n+1 ; ++j) {
            if (s1[i-1] == s2[j-1])
                vec[i][j] = vec[i-1][j-1] + 1;
            else
                vec[i][j] = vec[i-1][j] > vec[i][j-1] ? vec[i-1][j] : vec[i][j-1];
        }
    }
}

string Solution::LCSubsequenceOne_helper(vector<vector<int>> &vec, string &s1, string &s2, int i, int j) {
    if (i == 0 || j == 0)
        return "";
    else if (s1[i-1] == s2[j-1])
        return LCSubsequenceOne_helper(vec, s1, s2, i-1, j-1) + s1[i-1];
    else {
        if (vec[i][j-1] < vec[i-1][j])
            return LCSubsequenceOne_helper(vec, s1, s2, i-1, j);
        else
            return LCSubsequenceOne_helper(vec, s1, s2, i, j-1);
    }
}

vector<string> Solution::LCSubsequenceAll_helper(vector<vector<int>> &vec, string &s1, string &s2, int i, int j) {
    if (i == 0 || j == 0)
        return vector<string>(1, "");
    else if (s1[i-1] == s2[j-1]) {
        vector<string> ret = LCSubsequenceAll_helper(vec, s1, s2, i-1, j-1);
        for (int k = 0 ; k < ret.size() ; ++k)
            ret[k] += s1[i-1];
        return ret;
    } else {
        if (vec[i][j-1] < vec[i-1][j])
            return LCSubsequenceAll_helper(vec, s1, s2, i-1, j);
        else if (vec[i][j-1] > vec[i-1][j])
            return LCSubsequenceAll_helper(vec, s1, s2, i, j-1);
        else {
            vector<string> ret, tmp1, tmp2;
            tmp1 = LCSubsequenceAll_helper(vec, s1, s2, i-1, j);
            tmp2 = LCSubsequenceAll_helper(vec, s1, s2, i, j-1);
            ret.insert(ret.end(), tmp1.begin(), tmp1.end());
            ret.insert(ret.end(), tmp2.begin(), tmp2.end());
            return ret;
        }
    }
}

void print(string &one) {
    cout << "reading out an LCS : " << endl;
    cout << one << endl;
    cout << endl;
}

void print(vector<string> &all) {
    cout << "reading out all LCSs : " << endl;
    for (int i = 0 ; i < all.size() ; ++i)
        cout << all[i] << endl;
    cout << endl;
}

int main() {
    string s1 = "acba", s2 = "abca";
    Solution sol;
    string one = sol.LCSubsequenceOne(s1, s2);
    vector<string> all = sol.LCSubsequenceAll(s1, s2);
    print(one);
    print(all);
    return 0;
}
