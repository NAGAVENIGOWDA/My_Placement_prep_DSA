//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
//for every component 

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycledfs(i, -1, visited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycledfs(int node, int parent, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (isCycledfs(adjNode, node, visited, adj)) {
                    return true;
                }
            } else if (adjNode != parent) {
                return true;
            }
        }

        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends