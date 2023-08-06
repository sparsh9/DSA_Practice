// Approach 1 (Recursive)
class Solution {
public:
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }
};

// Approach 2 (Iterative)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; // To store the preorder traversal result
        stack<TreeNode*> stack; // Stack to help with the iterative traversal

        if (root == NULL)
            return preorder; // If the root is NULL, return an empty vector

        stack.push(root); // Push the root node onto the stack

        while (!stack.empty()) {
            TreeNode* curr = stack.top(); // Get the top node from the stack
            stack.pop(); // Pop the top node

            preorder.push_back(curr->val); // Add the value of the current node to the preorder vector

            if (curr->right != NULL)
                stack.push(curr->right); // Push the right child onto the stack (if it exists)

            if (curr->left != NULL)
                stack.push(curr->left); // Push the left child onto the stack (if it exists)
        }

        return preorder; // Return the preorder traversal result
    }
};
