class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
   
    //making parents
    unordered_map<TreeNode*,TreeNode*>mp;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* parent=q.front();
        q.pop();
        if(parent->left){
            mp[parent->left]=parent;
            q.push(parent->left);
        }
        if(parent->right){
            mp[parent->right]=parent;
            q.push(parent->right);
        }
    } 
    
    //traverse upto distance k
    unordered_map<TreeNode*,bool>vis;
    q.push(target);
    vis[target]=1;
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
        if(count++==k) break;
        for(int i=0; i<size; i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=1;
            }
            if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=1;
            }
            if(mp[curr] && !vis[mp[curr]]){
                q.push(mp[curr]);
                vis[mp[curr]]=1;
            }
        }
    }
    
    //traverse queue to store in ans
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
};