// Simple BFS Traversal
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        // Adjacency list
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            // as it is an undirected graph
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        // we will create a dist vector storing all the nodes and their probabilities to reach them
        // ans will be in dist[end] 
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto x : adj[curr]) {
                int node = x.first;
                double prob = x.second;
                double newProb = dist[curr] * prob; // new probability
                // if older probability is lesser than the new one, then simply update it
                if (newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }
        
        return dist[end];
    }
};