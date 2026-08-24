class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = 1;

        for(int neigh : adj[node]) {

            // Skip the edge going back to parent
            if(neigh == parent) {
                continue;
            }

            // Cycle found
            if(visited[neigh]) {
                return false;
            }

            // Visit unvisited neighbor
            if(!dfs(neigh, node, adj, visited)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if(edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        // Build adjacency list
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        // Check for cycle
        if(!dfs(0, -1, adj, visited)) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                return false;
            }
        }

        return true;
    }
};