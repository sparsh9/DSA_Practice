class NodeValue{
public:
      int maxNode,minNode,maxSize;

      NodeValue(int maxNode, int minNode, int maxSize){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
      }
};



class Solution {
public:
      NodeValue LargestBSTsubtreeHelper(TreeNode* root){
            // An empty tree is a BST of size 0.
            if (!root) {
                  return NodeValue(INT_MAX, INT_MIN, 0);
            }

            // Get values of left and right subtrees of current node
            auto left = LargestBSTsubtreeHelper(root->left);
            auto right = LargestBSTsubtreeHelper(root->right);

            // current node is greater than max of left subtree and less than min of right subtree
            if(left.maxNode < root->val && right.minNode > root->val){
                  return NodeValue(max(right.maxNode, root->val), min(left.minNode, root->val), left.maxSize + right.maxSize + 1);
            }
            // if current node is not a BST then return the max of left and right subtree
            else{
                  return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
            }
      }

      int largestBST(TreeNode * root){
            return LargestBSTsubtreeHelper(root).maxSize;
      }
}