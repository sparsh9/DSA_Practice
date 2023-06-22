// Here we are simultaneously checking the left and right of the tree in (left,right) and (right,left)
// as according to the mirror, the left and right will be mirrored into right and left
class Solution {
public:
    bool f(TreeNode *root1, TreeNode* root2) {
        // if either of them is null, check if both right and left is equal or not
        if(!root1 || !root2) return root1 == root2;
        // check if both right and left values are equal
        if (root1->val != root2->val) return false;
        // check if (left,right)  and (right,left) are equal or not
        return f(root1->left, root2->right) && f(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return f(root->left, root->right);
    }
};