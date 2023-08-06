// Here in the recursive approach
// we are travelling from the root node to all tree
// if we in any node we find one of the p or q in its left or right 
// then we return that p or q, otherwise we return null
// and atlast, when we take to upwards, till one of the sides return p or q , we return than node instead of p or q
// then till last, that returned node will be our LCA as is ancestor to both p and q
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        // here when either p or q is found, we return that p or q itself
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        // if left node is null, check right
        if(left == NULL) {
            return right;
        }
        // if right node is null, check left
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null or we got some result from both sides of the tree
            return root;
        }
    }
};