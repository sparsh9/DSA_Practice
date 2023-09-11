class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levels;
        vector<double> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
            levels.push_back(level);
        }

        for(int i=0; i<levels.size(); i++){
            double sum = 0;
            for(int j=0; j<levels[i].size(); j++){
                sum += levels[i][j];
            }
            ans.push_back(sum/levels[i].size());
        }
        return ans;
    }
};