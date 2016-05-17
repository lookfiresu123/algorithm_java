#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> LCSubstr(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> vec(m+1, vector<int>(n+1, 0));
        vector<string> ret;
        int maxlen = 0;
        for (int i = 1 ; i < m+1 ; ++i) {
            for (int j = 1 ; j < n+1 ; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    vec[i][j] = vec[i-1][j-1] + 1;
                    if (vec[i][j] > maxlen) {
                        maxlen = vec[i][j];
                        ret.clear();
                        ret.push_back(string(s1.begin()+i-maxlen, s1.begin()+i));
                    } else if (vec[i][j] == maxlen)
                        ret.push_back(string(s1.begin()+i-maxlen, s1.begin()+i));
                } else
                    vec[i][j] = 0;
            }
        }
        return ret;
    }
};

void print(vector<string> &ret) {
    for (int i = 0 ; i < ret.size() ; ++i)
        cout << ret[i] << endl;
}

int main() {
    string s1 = "abcdehijkl", s2 = "abchij";
    Solution sol;
    vector<string> ret = sol.LCSubstr(s1, s2);
    print(ret);
    return 0;
}
