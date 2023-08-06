// Approach 1 (Recursive)
// Here we are following a recursive approach wherein we are constantly checking for max heights from left and right side
class Solution {
public:
    // Function to calculate the maximum depth of the binary tree
    int maxDepth(TreeNode* root) {
        // Base case: If the current node is NULL, it represents an empty tree, so the depth is 0
        if (root == NULL) return 0;

        // Recursive calls to find the maximum depth of the left and right subtrees
        int lh = maxDepth(root->left); // Depth of the left subtree
        int rh = maxDepth(root->right); // Depth of the right subtree

        // The depth of the binary tree is the maximum depth among its left and right subtrees plus 1 (for the current node)
        return 1 + max(lh, rh);
    }
};

// Approach 2 (Level order Traversal)
int maxDepth(TreeNode* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
        }
        return depth;
}