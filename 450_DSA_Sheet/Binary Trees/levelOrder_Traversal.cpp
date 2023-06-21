// Firstly i am taking a queue and pushing the root node to it
// then after that, I am checking if there is a left or right node to it
// and if it is, then pushing that to queue as well
// then for every level, I am running a for level until that level's size and pushing all the nodes of that level into a vector
// after that finally, push that vector to the answer vector<vector>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( root ==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int> level ;
            for(int i=0; i< size; i++){
                TreeNode *node = q.front();
                q.pop();
                if( node-> left != NULL) q.push(node-> left);
                if(node -> right != NULL) q.push(node -> right);
                // push the level nodes into a vector
                level.push_back(node-> val);
            }
            // push all the level nodes into the final ans vector
            ans.push_back(level);
        }
        return ans;
    }
};