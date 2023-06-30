class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // till we dont reach null root and till that root's val is not equal
        while(root != nullptr && root->val != val){
            // if val is less than root move left otherwise move right
            root = (val < root->val) ? root->left : root->right;
        }
        return root;
    }
};