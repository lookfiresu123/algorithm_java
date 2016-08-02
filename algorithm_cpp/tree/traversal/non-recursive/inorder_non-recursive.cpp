#include "../traversal.h"

// 方法2：先将当前节点入栈，之后访问左孩子结点，若左孩子结点为空则回溯至父结点访问并出栈，之后访问右孩子结点
void inorder_nontraversal(struct TreeNode *root) {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (!cur || !stk.empty()) {
        if (!cur) {     // 若当前结点不为空，则将其入栈并访问左孩子结点
            stk.push(cur);
            cur = cur->left;
        } else {        // 若当前结点为空，则回溯到它的父结点并访问之，之后将其出栈并访问父结点的右孩子结点
            cur = stk.top();
            stk.pop();
            cout << cur->data << endl;
            cur = cur->right;
        }
    }
}
