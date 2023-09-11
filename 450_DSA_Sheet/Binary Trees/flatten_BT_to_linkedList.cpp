// Approach 1 (Recursive)
// Here we are traversing in the (right left root) fashion. we start with the right most big element of the BT
// and similar to the linkedlist, we are marking its right as null and then while returning, making it as our prev node
// while backtracking, we are making the backtracked node pointing towards prev, hence making a chain
class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
       if(root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;

    }
};


// Approach 2 (Iterative)
class Solution {
  TreeNode * prev = NULL;
  public:
   void flatten(TreeNode * root) {
        if (root == NULL) return;
        stack <TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode * cur = st.top();
            st.pop();

            if (cur -> right != NULL) {
                st.push(cur -> right);
            }
            if (cur -> left != NULL) {
                st.push(cur -> left);
            }
            if (!st.empty()) {
                cur -> right = st.top();
            }
            cur -> left = NULL;
        }
    }
};