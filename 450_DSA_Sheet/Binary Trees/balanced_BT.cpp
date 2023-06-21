// Approach (Using the height of BT concept)
// Here in each stage whether it goes to left or right, we are checking the height
// and in that same height function, before returning itself in each stage, we check their absolute difference
// if its greater than 1 then we simply return -1 otherwise we return the height.
// Also there might be case that if either left height and right height is -1 and we are about to take their difference,
// then there we take another condition that if either lh or rh is -1 then also return -1

// atlast we simply check if returned answer is -1 (it means not balanced hence false) or height (which is !(-1) which means the tree is balanced and hence true)

class Solution {

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (TreeNode *root) {

        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        // checks if lh is -1, if it is then terminate
        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);
        // checks if rh is -1, if it is then terminate
        if (rightHeight == -1) 
            return -1;
        // checks if their absolute difference is -1, if it is then terminate
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }
};