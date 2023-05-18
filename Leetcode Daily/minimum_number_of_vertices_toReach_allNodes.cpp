// Approach 1 : find all the Source nodes as all the other nodes can be reached by any other nodes
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans,visited(n);
        // marking all the nodes which can be reached from any other node
        for(auto edge:edges){
            visited[edge[1]] = 1;
        }
        // Finding all the nodes which cannot be reached by any other node aka Source Nodes
        for(int i=0;i<n;i++){
            if(!visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};