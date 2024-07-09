//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>>adj[N];
        
        vector<int>dist(N,1e9);
        
        for(auto it : edges){
            
            adj[it[0]].push_back({it[1],it[2] });
            
        }
        
        
       
        
        queue<int>q;
        q.push(0);
        dist[0]=0;
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto adjNode : adj[node]){
                int ele=adjNode.first;
                int wt=adjNode.second;
                if(dist[node] + wt < dist[ele]){
                    dist[ele]=dist[node]+wt;
                    q.push(ele);
                }
            }
        }
        
        
    vector<int>ans(N,-1);
    for(int i=0;i<N ;i++){
        if(dist[i]!=1e9){
            ans[i]=dist[i];
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends