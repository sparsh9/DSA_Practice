class Solution {
public:
    #define ll long long
    // Here we are checking that from the source node given, to how many nodes/bombs we can reach to
    void dfs(int src,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;
        for(int x:adj[src]){
            if(vis[x]==0){
                dfs(x,vis,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {    
          int n=bombs.size();
          vector<int> adj[n];

        // Here we are creating an adjancency matrix
        // This matrix tells from which node/bomb can detonate other bombs in its blast radius,
        // Hence it is a undirected edge.
        for(int i=0;i<n;i++){
            ll r1=bombs[i][2];
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];

            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x2=bombs[j][0];
                    ll y2=bombs[j][1];
                    ll r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);;
                    if(dsq<=r1*r1){
                        adj[i].push_back(j); 
                    }
                }
            }
        }

        // Now for every node, we are doing a dfs to get the maximum value of detonated bombs
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            dfs(i,vis,adj); 
            int cnt=0;

            for(int j=0;j<n;j++) 
              if(vis[j]==1) cnt++;

            ans=max(ans,cnt);
        }
        return ans;
    }
};


