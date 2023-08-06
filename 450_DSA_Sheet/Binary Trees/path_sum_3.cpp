// Approach 1(Using Recursion)
class Solution {
public:
    int ans=0;
    // function to check if there is any path which equals target sum
    void dfs(TreeNode* root, long long int sum){
        if(!root)return;
        if(root->val==sum)ans++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root){
            // checking from this node to others
            dfs(root,sum);
            // checking on from nodes on left side
            pathSum(root->left,sum);
            // checking on from nodes on right side
            pathSum(root->right,sum);
        }
        return ans;
    }
};