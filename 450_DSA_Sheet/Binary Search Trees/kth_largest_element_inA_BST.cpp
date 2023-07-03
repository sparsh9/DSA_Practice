// Here simply we will be using the same logic of the 
// kth smallest element in the BST
// just we know that :
// kth largest = (n-k)th smallest element
// therefore we will do the same process

class Solution {
public:
    int ans;
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(root->right, k);
    }  
};