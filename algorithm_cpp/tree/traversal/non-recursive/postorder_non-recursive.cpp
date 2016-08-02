#include "../traversal.h"

// 后序遍历可以看作是下面遍历的逆过程：即先遍历某个结点，然后遍历其右孩子，然后遍历其左孩子。
void postorder_nontreserval(TreeNode *root) {
    // 先遍历某个结点，然后遍历其右孩子，最后遍历其左孩子
    if (!root)  return ;
    stack<TreeNode *> stk1, stk2;
    stk1.push(root);
    TreeNode *cur = nullptr;
    while (!stk1.empty()) {
        cur = stk1.top();
        stk1.pop();
        stk2.push(cur);
        if (cur->left)  stk1.push(cur->left);
        if (cur->right) stk1.push(cur->right);
    }

    // 逆序输出
    while (!stk2.empty()) {
        cout << stk2.top()->data << endl;
        stk2.pop();
    }
}
