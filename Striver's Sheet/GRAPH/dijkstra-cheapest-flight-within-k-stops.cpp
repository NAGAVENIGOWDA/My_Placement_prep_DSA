//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<vector<int>> q;
        vector<int>dist(n,1e9);
        
        q.push({0,src,0});
        dist[src]=0;
        
        while(!q.empty()){
            
            auto it =q.front();
            int hops=it[0];
            int node=it[1];
            int dis=it[2];
            
            q.pop();
            
            if(hops > K) continue ; //dont ecplore -stop -u have reached it to the max numbe of hops
            
            for(auto ele : adj[node]){
                
                int adjNode=ele.first;
                int wt=ele.second;
                
                if(dis+wt < dist[adjNode] && hops<=K){
                    
                    dist[adjNode]=dis+wt;
                    q.push({hops+1,adjNode,dist[adjNode]});
                }
                
            }
        }
        
    if(dist[dst]!=1e9)  return dist[dst];
    
    return -1;
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends