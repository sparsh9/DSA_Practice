// Approach 1 using DFS traversal
// Consider a -> b as a/b with weight 2.0 and b->a as 1/2.0 So similarly,
// for other nodes, it will be a nodes of a directed cyclic graph
// Now using the dfs traversal we can find other values like a/c which is originally not present
// So here unlike natural method of adding the weights while traversal, we will here multiply it as
// It is problem of division and inverse (aka multiplication)
class Solution {
public:
    double dfs(string a,string&b,unordered_map<string,unordered_map<string,double>>graph,unordered_set<string>&visited){
        // checking if already present
        if(graph[a].find(b)!=graph[a].end()){
            return graph[a][b]; 
        }
        for(auto node :graph[a]){
            // If it is not in the visited node, then insert it  
            if(visited.find(node.first)==visited.end()){
                // here we get the a.next
                visited.insert(node.first);
                // Now traverse further from a.next to b and do the dfs
                double val=dfs(node.first,b,graph,visited);
                // As we get the value, now multiply at as per the logic
                if(val){
                    graph[a][b]=node.second*val;
                    return graph[a][b];
                }
            }
        }
            return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       vector<double>ans;
       unordered_map<string,unordered_map<string,double>>graph;
       // Inserting the weights and making the graph
       for(int i=0;i<equations.size();i++)
       {
           graph[equations[i][0]][equations[i][1]]=values[i];
           graph[equations[i][1]][equations[i][0]]=(double) 1/(values[i]);
       }
       // Solving for every query
       for(int i=0;i<queries.size();i++)
       {
           unordered_set<string>visited;
           double val=dfs(queries[i][0],queries[i][1],graph,visited);
           // If value does not exist or is zero return -1.0
           if(!val)
           {
               ans.push_back(-1.0);
           }
           else
           {
               ans.push_back(val);
           }
       }
        return ans;
    }
};