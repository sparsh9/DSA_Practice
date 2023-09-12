class Solution {
    int helper(TreeNode *root,int &result)
    {
        if(!root)
            return 0;
        
        // it is possible that left or right subtree can have negative sum, 
        // so we take max of 0 and the sum of left or right subtree
        int left = max(0,helper(root->left,result));
        int right = max(0,helper(root->right,result));

        // this is the maximum sum path that passes through the root and is 
        // changed globally
        result = max(result,left+right+root->val);
        cout<<"result till now:"<<result<<" ";

        // This is the maximum path sum from either of the left or right nodes from including the curr node
        int  maxpathsum = root->val + max(left,right);
        cout<<"Maximum Path sum from this curr node from either sides :"<<maxpathsum<<" ";

        return maxpathsum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        helper(root,result);
        return result; 
    }
};