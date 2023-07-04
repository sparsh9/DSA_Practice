// Approach 1
// Suppose we are given the preorder traversal,
// then we know that in BST, the inorder traversal is always sorted
// so the sort the preorder and we will have our inorder
// now we have our preorder and inorder, therefore we can get out BT
// using the construct BT using preorder and inorder problem
// and this BT will be a BST

// Approach 2 (Using upper bound and property of BST on left and right subtrees)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0; // global pointer of index we are at
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int upperbound) {
        if (i == A.size() || A[i] > upperbound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        // it will initially go to both left and right side, and in the recursion
        // automatically, one of the side returns null, so the other remaining side is where it gets attached


        // if the curr pointer val is lesser than the root, then it goes to left and the upper bound will be root->val,
        // if it is not, then it will return null
        root->left = build(A, i, root->val);


        // if curr pointer val is greater than the root value, it goes to right and the upper bound remains same as original
        // that is INT_MAX, if it is not, then it returns null
        root->right = build(A, i, upperbound);

        // when both side returns null or is completed
        return root;
    }
};