// Here we simply maintain 2 variables for length and sum which we maximise using our old technique
// we traverse till the bottom of tree (leaf node) and first compare len, if currlen > maxlen, 
// then update it and similarly maximise the maxsum using the currSum
class Solution {
public:
    void solve(Node* root, int len, int &maxlen, int currsum, int &maxsum) {
        // base case
        if (root == nullptr) {
            if (len > maxlen) {
                maxlen = len;
                maxsum = currsum;
            }
            else if (len == maxlen) {
                maxsum = max(currsum, maxsum);
            }
            return;
        }

        currsum = currsum + root->data;
        solve(root->left, len + 1, maxlen, currsum, maxsum);
        solve(root->right, len + 1, maxlen, currsum, maxsum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxlen = 0;
        int currsum = 0;
        int maxsum = 0;
        solve(root, len, maxlen, currsum, maxsum);

        return maxsum;
    }
};
