// Approach 1 (Recursive)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};

// Approach 2 (Iterative)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int> res;

        while(true){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty()==true) break;
                root=s.top();
                res.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};