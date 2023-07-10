class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // +1 because it counts edge but we want nodes(which is twice the edge) so we add 1
        if(root->left && root->right){
            return min(left+1, right+1);
        }
        return max(left+1, right+1);
    }
};