// Approach (Using the post order travesal)
// Here we are using the post order traversal techniques
class Solution {
public:
    void swap(TreeNode* curr){
        // if current is pointing to null
        if(!curr)
            return;

        // go to left until possible
        swap(curr->left);
        // now to go to right until possible
        swap(curr->right);

        // if left and right is done, then simply swap the left and right nodes
        TreeNode* temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};