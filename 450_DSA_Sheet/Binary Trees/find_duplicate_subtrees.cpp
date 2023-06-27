// here we are simply storing all the subtrees of the BT in the form of string in the map
// if it is found, then we store its root, otherwise we simply add it into the map
class Solution {
public:
    string getSubtreeString(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*> &ans){
        if(root == nullptr)
            return "N";
        // making the subtree into the form of a string
        string s = to_string(root->val) + "-" 
                    +getSubtreeString(root->left,mp,ans) + "-"
                    +getSubtreeString(root->right,mp,ans);
        // if that string is found in the map
        if(mp[s] == 1)
            ans.push_back(root);
        // if not found, then simply add it 
        mp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;

        getSubtreeString(root,mp,ans);
        return ans;
    }
};