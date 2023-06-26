// Similar to Top View Traversal
// Just here instead of first come first fill in the map,
// we will simply overwrite the elements of the same line as it is a level order traversal
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            // moving to next left line
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            // moving to next right line
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        // as it is a ordered map with lowest (leftmost) line at top, we will be pushing it to answer
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};