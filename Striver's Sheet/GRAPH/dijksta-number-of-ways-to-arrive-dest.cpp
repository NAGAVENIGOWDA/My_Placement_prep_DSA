//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<pair<int,int>>adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>q;
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        int mod = (int)(1e9+7);
        q.push({0,0});
        
        while(!q.empty()) {
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it: adj[node]) {
                long long edw = it.second;
                int adjnode = it.first;
                
                if(dis+edw < dist[adjnode]) {
                    dist[adjnode] =dis+edw;
                    q.push({dis+edw,adjnode});
                    ways[adjnode] = ways[node] % mod;
                }
                else if(dis+edw == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends