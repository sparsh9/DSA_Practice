// Here we are doing the inorder traversal but in a partial manner,
// as each time only height nodes will be added to the stack, until unless
// any node in the left subtree has a right node
class BSTIterator {
private:
    stack<TreeNode*> s; // Stack to store nodes

public:
    // Constructor to initialize the BSTIterator with the given root
    BSTIterator(TreeNode* root) {
        pushAllLeftNodes(root); // Push all left nodes onto the stack
    }

    // Helper function to push all left nodes onto the stack
    void pushAllLeftNodes(TreeNode* root) {
        while (root != NULL) {
            s.push(root); // Push the current node onto the stack
            root = root->left; // Move to the left child
        }
    }

    // Returns the value of the next smallest element in the BST
    int next() {
        TreeNode* top = s.top(); // Get the top node from the stack
        s.pop(); // Pop the top node

        pushAllLeftNodes(top->right); // Push all left nodes of the right subtree onto the stack

        return top->val; // Return the value of the top node
    }

    // Checks whether there are any more elements to iterate
    bool hasNext() {
        return !s.empty(); // Return true if the stack is not empty, indicating there are more elements to iterate
    }
};
