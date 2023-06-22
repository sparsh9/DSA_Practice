// Here for the right/left side view of the BT, we will be seeing the rightmost or leftmost node respectively of every level
// so for right side view we will follow : root,right,left 
// and for left side view we will follow : root,left,right
// Also as we have to store only the first values from either sides, there we use a trick as below
class Solution {
public:
    void traversal(TreeNode* root, int level, vector<int> res){
        if(root == nullptr) return;

        // to store the first immediate values from either side in a level
        if(level == res.size()) res.push_back(root->val);

        // for the right side view , we follow (root,right left)
        traversal(root->right,level+1,res);
        traversal(root->left,level+1,res);

        // for the left side view , we follow (root,left,right)
        // traversal(root->left,level+1,res);
        // traversal(root->right,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        // Initially the level will be 0
        traversal(root,0,res);
        return res;
    }
};