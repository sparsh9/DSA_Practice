// Approach 1 (Using Recursive)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
    }
};

// Approach 2 (Iterative using 2 stacks)

vector < int > postOrderTrav(node * curr) {

  vector < int > postOrder;
  if (curr == NULL) return postOrder;

  stack < node * > s1;
  stack < node * > s2;
  s1.push(curr);
  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr -> left != NULL)
      s1.push(curr -> left);
    if (curr -> right != NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
  }
  return postOrder;
}

// Approach 3 (Iterative using 1 stack)

class Solution {
public:
    vector < int > postorderTraversal(TreeNode* cur) {
        vector < int > postOrder;
        if (cur == NULL) return postOrder;

        stack < TreeNode* > st;
        while (cur != NULL || !st.empty()) {
            // Goes to left till possible
            if (cur != NULL) {
                st.push(cur);
                cur = cur -> left;
            } 
            // when all left nodes are over, then moves to right
            else {
                TreeNode* temp = st.top() -> right;
                // when there are no more right nodes possible
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp -> val);
                    // checks if there is any left upward node there in the stack
                    // or if the current node is right node to any other node in the stack
                    while (!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp -> val);
                    }
                } 
                // goes to right till possible
                else 
                    cur = temp;
            }
        }
        return postOrder;
    }
};