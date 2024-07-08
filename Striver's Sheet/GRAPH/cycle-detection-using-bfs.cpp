//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclebfs(i, visited, adj)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCyclebfs(int node, vector<bool>& visited, vector<int> adj[]) {
        queue<pair<int, int>> q;
        visited[node] = true;
        q.push({node, -1});
        
        while (!q.empty()) {
            int n = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjNode : adj[n]) {
                
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    q.push({adjNode, n});
                } 
                
                else if (adjNode != parent) {
                    return true;
                }
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