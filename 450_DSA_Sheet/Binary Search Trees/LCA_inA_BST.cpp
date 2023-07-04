// Using recursion and property of BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        int curr = root->val;

        // if values are greater than root, move towards right
        if(curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right,p,q);
        // if values are lesser than root, move towards left
        if(curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left,p,q);
        
        // In this case or all other cases than above, if the root is the point from where it gets split and that's out lca
        // or if both p and q are on same side,then the root is our lca
        return root;
    }
};