#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countComponents(int totalNodes, const vector<int>& connectionsFrom, const vector<int>& connectionsTo) {
    vector<vector<int>> graph(totalNodes);
    for (int i = 0; i < connectionsFrom.size(); ++i) {
        graph[connectionsFrom[i] - 1].push_back(connectionsTo[i] - 1);
        graph[connectionsTo[i] - 1].push_back(connectionsFrom[i] - 1);
    }

    vector<bool> visited(totalNodes, false);
    int componentCount = 0;

    for (int i = 0; i < totalNodes; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            ++componentCount;
        }
    }
    return componentCount;
}

int main() {
    int totalNodes = 7;
    vector<int> connectionsFrom = {1, 2, 3, 5};
    vector<int> connectionsTo = {2, 3, 4, 6};

    int components = countComponents(totalNodes, connectionsFrom, connectionsTo);
    cout << "Total different components: " << components << endl;

    return 0;
}
