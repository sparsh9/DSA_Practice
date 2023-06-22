// Approach (using Traversal)
// we simply check if their traversal gives same output or not
// if they are same, then it means they are identical otherwise vice-versa


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if(!p || !q)    return false;
            return (
            p->val == q->val  // root node values are equal
            && isSameTree(p->right, q->right)  // right node traversal is same
            && isSameTree(p->left, q->left)); // left node traversal is same
    }
};