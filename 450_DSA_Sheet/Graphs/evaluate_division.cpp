class Solution {
public:
    double dfs(string a,string&b,unordered_map<string,unordered_map<string,double>>graph,unordered_set<string>&visited){
        // agar a se b tak ka edge hai toh wahi return karo
        if(graph[a].find(b)!=graph[a].end()){
            return graph[a][b]; 
        }
        // agar a se b tak ka edge nahi hai toh a se b tak ka edge dhundho
        for(auto node :graph[a]){
                // agar node visited nahi hai toh usko visited mei daal do aur uska dfs call karo
                if(visited.find(node.first)==visited.end()){
                    // visited mei daal do
                    visited.insert(node.first);
                    // check karo iss node se kya humare required node tak ka koi connection hai kya
                    double val=dfs(node.first,b,graph,visited);
                    // agar hai toh uska value return karo
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
       // graph create karo, like agar a se b diya hai toh b se a bhi hoga which will be 1/value of a se b
       for(int i=0;i<equations.size();i++){
           graph[equations[i][0]][equations[i][1]]=values[i];
           graph[equations[i][1]][equations[i][0]]=(double) 1/(values[i]);
       }
       // ab queries pe dfs chala do
       for(int i=0;i<queries.size();i++){
        unordered_set<string>visited; // visited set banaya
        double val=dfs(queries[i][0],queries[i][1],graph,visited);
        // agar val 0 hai toh -1.0 push karo
        if(!val)
            ans.push_back(-1.0);
        else
            ans.push_back(val);

       }
        return ans;
    }
};