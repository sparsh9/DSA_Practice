// Approach 1(Using the inorder traversal and 2 Sum in sorted array problem solution)
// we know that the inorder traversal of  BST is always sorted so after getting the array of sorted numbers
// we will use the logic of the 2 Sum in sorted array problem which uses the binary search logic
// T.C = O(n) + O(n)  and O.C = O(n)



// Approach 2(Using the concept of BST Iterator and the binary search)
// as in the BST operator problem, we had a next() function, here we will also have a before() function
// in the before, instead of pushing all the left nodes(like next operator), we will instead push all the right nodes first and the things will be exactly opposite to the next operator 
// the ith operator will be at the lowest and jth will be at highest just like binary search
// now instead of increasing the i or j values as in the binary search, we will use the next() and before() functions

class BSTIterator {
    stack<TreeNode*> myStack; // Stack to store tree nodes
    bool reverse = true; // Indicates the traversal direction
    
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse; // Set the traversal direction
        pushAll(root); // Push all the nodes in the specified direction onto the stack
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty(); // Check if the stack is not empty, indicating if there's more elements to traverse
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmpNode = myStack.top(); // Get the topmost node from the stack
        myStack.pop(); // Pop the topmost node from the stack
        
        // Push the appropriate child nodes onto the stack based on the traversal direction
        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        
        return tmpNode->val; // Return the value of the current node
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;) {
            myStack.push(node); // Push the current node onto the stack
            
            if (reverse == true) {
                node = node->right; // Traverse to the right child node if the traversal direction is reverse
            } else {
                node = node->left; // Traverse to the left child node if the traversal direction is not reverse
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        
        BSTIterator l(root, false); // Create a BSTIterator object with normal (non-reverse) traversal
        BSTIterator r(root, true); // Create a BSTIterator object with reverse traversal
        
        int i = l.next(); // Get the next smallest element from the normal traversal
        int j = r.next(); // it's similar to r.before(), but just to code less, next is only used
        
        while (i < j) {
            if (i + j == k)
                return true; // If the sum of the two elements is equal to 'k', return true
            
            else if (i + j < k)
                i = l.next(); // If the sum is less than 'k', move to the next smallest element from the normal traversal
            
            else
                j = r.next(); // If the sum is greater than 'k', move to the next smallest element from the reverse traversal
        }
        
        return false; // If no pair sums up to 'k', return false
    }
};
