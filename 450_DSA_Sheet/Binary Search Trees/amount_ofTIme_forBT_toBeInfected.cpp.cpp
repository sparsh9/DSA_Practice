// we will move in 3 directions in iterative form: parent, left child, right child
// for parent we will use map to store parent of each node
// for left and right child we will use queue

class Solution {
    // stores the parent of each nodes in the hash map
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        // base case
        if(!root) return;

        // for left and right child, current root will be the parent
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        // recursively for all the nodes as parents
        markParent(root->left, parent);
        markParent(root->right, parent);
    }

    // This function will the node from root which has it's value as key
    TreeNode* findNode(TreeNode* root, int key){
        if(root){
            if(root->val ==key)
                return root;
            else{
                TreeNode* foundNode = findNode(root->left, key);
                if(!foundNode)
                    foundNode = findNode(root->right, key);
                return foundNode;
            }
            
        }
        else
            return NULL;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        // find the node with the given value as its value
        TreeNode* target = findNode(root, start);

        // now we have target node and also parents to do bfs in all 3 directions
        // now using queue, we will do bfs in all 3 directions iteratively

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;

        int time =0;

        q.push(target);
        vis[target] = true;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                q.pop();
                vis[node] = true;

                // towards left node
                if(node->left and !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                // towards right node
                if(node->right and !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                // towards parent node
                if(parent[node] and !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            time++;
        }
        return time-1; // here we counted number of nodes, but want the edges, hence -1
    }
};
