// Approach : (Recursion)

class Solution {
public:
    vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = helper(start,i-1); // getting all the possible left trees with their roots
            vector<TreeNode*> right = helper(i+1,end); // getting all the possible right trees with their roots
            // all tree combinations = all left trees combinations * all right tree combinations
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i); // creating all the possible trees with their left and right tree roots given
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }


    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};



// Approach : (Recursion + Memoization)

class Solution {
public:
    vector<TreeNode*> helper(int start,int end,vector<vector<vector<TreeNode*>>>& dp){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        if(dp[start][end].size()!=0){
            return dp[start][end];
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = helper(start,i-1,dp);
            vector<TreeNode*> right = helper(i+1,end,dp);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[start][end] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        // its a 3d dp array as
        // dp[start][end] = vector<TreeNode*> which stores all the possible trees with their roots in the range start to end
        vector<vector<vector<TreeNode*>>> dp(n+1,vector<vector<TreeNode*>>(n+1));
        return helper(1,n,dp);
    }

};