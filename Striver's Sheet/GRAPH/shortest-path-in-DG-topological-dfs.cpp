//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void topologicalDfs(int node, vector<pair<int,int>>adj[],stack<int>&st,vector<int>&visited){
         
         visited[node]=1;
         
         for(auto it : adj[node]){
             if(!visited[it.first]){
                 topologicalDfs(it.first,adj,st,visited);
             }
         }
         
         
        st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        //using topological sorting 
        //1.get the topological order
        //2.construct distance
        
        vector<pair<int,int>>adj[N];
        
        vector<int>dist(N,1e9);
        dist[0]=0;
        
        for(auto it : edges){
            
            adj[it[0]].push_back({it[1],it[2] });
            
        }
        
        
        stack <int> st;
        vector<int>visited(N,0);
        
        for(int i=0;i<N;i++){
            
            if(!visited[i]){
                topologicalDfs(i,adj,st,visited);
            }
        }
        
        
        while(!st.empty()){
            
            //src will be at the top
            
            int u=st.top();
            st.pop();
            
            for(auto it : adj[u]){
                
                int v=it.first;
                int wt=it.second;
                
                if(dist[u] + wt < dist[v]){
                    dist[v]=dist[u]+wt;
                    
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