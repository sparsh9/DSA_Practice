// Approach 1 (Using recursion)
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > allPaths;
        vector<int> path;
        findPaths(root, sum, path, allPaths);
        return allPaths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& allPaths) {
        if (!node) return;
        // push the node into the path as it from where we come here
        path.push_back(node -> val);
        // if it is a leaf node, then push the path from which it has come
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            allPaths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, allPaths);
        findPaths(node -> right, sum - node -> val, path, allPaths);
        // if it comes till here and if its not target sum, pop that node from the path, as it is a dead end
        path.pop_back();
    }
};