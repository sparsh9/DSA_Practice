// Strongly Connected Components (Kosaraju's Algorithm)
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        // Order the edges on the basis of their finishing times using the dfs
        // and fills in to the stack as order
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // a similar adjacency matrix is created as it is being transposed to adjT
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it (initially)
                // it -> i (finally)
                adjT[it].push_back(i);
            }
        }
        int scc = 0; // count of SCCs
        // taking the element out of stack on the basis of their finishing times
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++; // count is increased for every node which is not visited 
                // as other nodes which are already being of the SCC are visited in the dfs traversal, hence they were already marked as visited
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};