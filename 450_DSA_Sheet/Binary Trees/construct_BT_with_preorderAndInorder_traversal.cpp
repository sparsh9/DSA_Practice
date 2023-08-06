// We Break our problem into subtree problems, wherein we first see the preorder (root left right)
// where the first node will be the root of our tree, then we check this root in the inorder traversal(left root right)
// which means all elements to left of this root will be part of left tree and vice-versa for right part
// then similarly, we will recursively solve for left and right subtrees, wherein
// for left subtree, inorder will be all elements to the left of the root as new inorder for this left tree and similarly for the right subtree
// also, for the preorder, which is the number of elements = total elements in the new inorder to right of the root will be the new preorder and all the remaining elements will be new preorder for right subtree
// we will continue this until we are left out with preorder or inorder arrays and at this time we will return null, 
// which will be means that we are returing null in either of the side
// at the time of backtracking, we will join this subtree with its root(parent) node
class Solution {
public:
    TreeNode * constructTree(vector < int > & preorder, int preStart, int preEnd, vector< int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
      if (preStart > preEnd || inStart > inEnd) return NULL;

      TreeNode * root = new TreeNode(preorder[preStart]);
      int elem = mp[root -> val];
      int nElem = elem - inStart;

      root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
      inStart, elem - 1, mp);
      root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
      elem + 1, inEnd, mp);

      return root;
    }

    TreeNode * buildTree(vector < int > & preorder, vector < int > & inorder) {
      int preStart = 0, preEnd = preorder.size() - 1;
      int inStart = 0, inEnd = inorder.size() - 1;

      map < int, int > mp;
      for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
      }

      return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }
};