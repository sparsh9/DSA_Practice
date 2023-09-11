class Solution {
public:

    int sumNumbers(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        sum = sum*10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
            return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};