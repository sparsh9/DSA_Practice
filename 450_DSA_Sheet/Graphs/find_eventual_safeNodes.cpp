// Approach (Using Dfs)
// some observations
// 1.any node part of a cycle cant be a safe node
// 2.any node leading to cycle node also cant be a safe node

class Solution {
public:
    
    bool DFSRec(int s, vector<bool>&visited, vector<bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        // We will mark all the source nodes "s" which leads to cycle as true as we don't want
        // these types of nodes
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[s] = true; // bcz this source leads to the cycle
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[s] = true; // bcz this source leads to the cycle
            }
        }
        
        dfsVisited[s] = false; // retracing back
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        vector<bool>visited(n, false), dfsVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};