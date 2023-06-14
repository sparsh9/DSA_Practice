// Approach 1(Similar to the approach 2)
// Here instead we would have stored that number in the form of vector and then checked the minDiff
// It would take extra space complexity




// Approach 2 (We know that inOrderTraversal of a BST returns a sorted order numbers)
// So here we are comparing the adjacent numbers (number and its previous) and calculating their difference
// before going to next stage that is right side
// and constantly updating the minDiff variable
// It takes constant space complexity
class Solution {
    int minDiff = INT_MAX;

    void inorderTraversal(TreeNode *root,TreeNode *&prev){
        if(!root)
            return;
        
        inorderTraversal(root->left,prev); //Left

        // Visited
        if(prev != nullptr){
            minDiff = min(minDiff,(root->val - prev->val));
        }
        prev = root;

        inorderTraversal(root->right,prev); //right
    }
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev = nullptr;

        inorderTraversal(root,prev);

        return minDiff;

    }
};