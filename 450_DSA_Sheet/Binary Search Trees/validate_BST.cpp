// Solution : Use the very basic property of BST which seperates it from a BT
// that is that the left subtree's elements are smaller than the node value and vice versa for right subtree as well

// Passing NULL to int will cast NULL to 0 in integer.
// So, It will give wrong result for [0, null, -1].
// If someone will pass INT_MIN as default value, then It'll fail for case - [-2147483648] and vice-versa.
// That's why pointers are used here.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode* root, int* lower, int* upper){
        if(!root)
            return true;

        if(upper && root -> val >= *upper)
            return false;
        if(lower && root -> val <= *lower)
            return false;
        
        return isValid(root -> left, lower, &(root -> val)) && isValid(root -> right, &(root -> val), upper);
    }
};