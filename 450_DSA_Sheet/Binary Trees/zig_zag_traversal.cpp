class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            // to store all the nodes of a level
            vector<int> levelNodes(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int index;
                // Position to fill the level nodes whether it is left to right or it is right to left
                if(leftToRight)
                    index = i;
                else
                    index = size-1-i;

                // storing the level's nodes as per their index
                levelNodes[index] = node->val;

                // pushing next level nodes into the queue
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            // Storing all the level nodes as per their directional order
            res.push_back(levelNodes);
            // reversing the storing direction for next level
            leftToRight = !leftToRight;
        }
        return res;
    }
};