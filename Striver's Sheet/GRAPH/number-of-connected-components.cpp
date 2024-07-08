//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(int u, vector<bool> &vis, vector<vector<int>> &adj){
        
        vis[u] = 1;
        
        for(int v=0; v<adj.size(); v++){
            if(adj[u][v] == 1 && !vis[v]){
                DFS(v, vis, adj);
            }
        }
        
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int ans = 0;
        
        vector<bool> vis(V, 0);
        
        for(int u=0; u<V; u++){
            
            if(!vis[u]){
                DFS(u, vis, adj);
                ans++;
            }
            
        }
        
        return ans;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends