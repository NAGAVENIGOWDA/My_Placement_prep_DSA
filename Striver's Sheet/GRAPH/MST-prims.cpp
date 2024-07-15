//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<vector<int>>MST;
        int sum=0;
        vector<int>visited(V,0);
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        
        q.push({0,0,-1});
        //{wt,node,parent}
      
      
      
        
        while(!q.empty()){
            
            auto it=q.top();
            int wt=it[0];
            int node=it[1];
            int parent=it[2];
            q.pop();
            
            
            if(visited[node]) continue;//already a part of MST
            
            visited[node]=1;
            sum+=wt;
            
            MST.push_back({parent,node});
            
            
            for(auto ele : adj[node]){
                int adjNode=ele[0];
                int ewt=ele[1];
                
                if(!visited[adjNode]) {
                    q.push({ewt,adjNode,node});
                }
            }
        }
        
        
    return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends