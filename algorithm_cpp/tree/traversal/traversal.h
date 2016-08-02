#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

