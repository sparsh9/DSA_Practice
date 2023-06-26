// Here we are following the level order traversal along the lines
// where we are considering the center root line as line 0 and
// left to center as center - i and lines to right as center + i
// then we are picking only the top element of each line as from top view, only first element from each line will be visible
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            // checking if element of that line doesn't exists in the map, then add it
            // otherwise if it exists, then leave it
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
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