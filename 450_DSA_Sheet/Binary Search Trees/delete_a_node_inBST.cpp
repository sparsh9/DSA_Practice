class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        // if the root node itself is the key
        if (root->val == key) {
            return helper(root);
        }
        // finds the key in the root and as soon as it is found, then simply call the helper function
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                // we check if it's left node has value as key
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                // we check if it's right node has value as key
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }


    // 1) stores the right most node of the left subtree
    // 2) stores the right subtree's root node
    // points the right most node of the left subtree to the right subtree's root node
    // returns the left subtree's root node
    TreeNode* helper(TreeNode* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }

    // Finds the right most node of the left subtree
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};