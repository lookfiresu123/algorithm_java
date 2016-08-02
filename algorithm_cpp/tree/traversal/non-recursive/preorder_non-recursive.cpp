#include "../traversal.h"

// 方法1：先将当前结点压入栈，然后当前结点出栈并访问之，而后依次将该结点的右孩子、左孩子入栈，直到栈为空为止。
void preorder_nontraveral1(struct TreeNode *root) {
    if (!root)  return ;
    stack<TreeNode *> stk;
    stk.push(root);
    TreeNode *cur = nullptr;
    while (!stk.empty()) {
        cur = stk.top();
        stk.pop();
        cout << cur->data << endl;
        if (cur->right) stk.push(cur->right);
        if (cur->left)  stk.push(cur->right);
    }
}

// 方法2：先访问当前节点并将其入栈，之后访问其左孩子结点，若左孩子结点为空则回溯至父结点并出栈，之后访问右孩子结点
void preorder_nontraveral2(struct TreeNode *root) {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (!cur || !stk.empty()) {
        if (!cur) {             // 若当前结点不为空，则访问之并将其入栈
            cout << cur->data << endl;
            stk.push(cur);
            cur = cur->left;    // 之后访问左孩子结点
        } else {                // 若当前结点为空，则回溯到它的父结点，将父结点出栈并访问父结点的右孩子结点
            cur = stk.top();    // 回溯到父结点
            stk.pop();          // 将父结点出栈
            cur = cur->right;   // 之后访问右孩子结点
        }
    }
}
