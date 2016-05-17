#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // implement strStr by kmp algorithm
    int strStr(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int m = haystack.length(), n = needle.length();
        if (!n)
            return 0;
        for (int i = 0, j = 0 ; i < m ; ) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            if (j == n)
                return i - j;
            if (i < m && haystack[i] != needle[j]) {
                if (j)
                    j = next[j-1];
                else
                    ++i;
            }
        }
        return -1;
    }

private:
    vector<int> getNext(string needle) {
        int n = needle.length();
        vector<int> next(n, 0);
        for (int i = 1, j = 0 ; i < n ; ) {
            if (needle[i] == needle[j])
                next[i++] = ++j;
            else if (j)
                j = next[j-1];
            else
                next[i++] = 0;
        }
        return next;
    }
};

int main() {
    string haystack = "a", needle = "a";
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
