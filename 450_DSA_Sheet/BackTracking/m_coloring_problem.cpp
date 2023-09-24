
class Solution{
public:
    bool isSafe(bool adj[101][101],int i,int c,int n,vector<int> &vis){
        for(int j=0;j<n;j++) 
            if(i!=j and adj[i][j] and vis[j] == c) 
                return false;
        return true;
    }
    
    bool dfs(bool adj[101][101],int n,vector<int> &vis,int m,int i){
        // when we reached last node
        if(i == n) 
            return true;
        for(int c=1;c<=m;c++){
            vis[i]=c;
            // har iteration mein ye saare m ke iterations lagake check karega if it is possible to paint.
            if(isSafe(adj,i,c,n,vis) and dfs(adj,n,vis,m,i+1))
                return true;
        }
        vis[i] = 0; // backtracking
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n,0);
        return dfs(graph,n,vis,m,0);
    }
};




    