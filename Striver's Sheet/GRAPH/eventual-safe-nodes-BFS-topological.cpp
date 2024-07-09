//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int>adjrev[V];
        vector<int>indeg(V,0);
        
        //reverse the graph
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }
        
        
        queue<int>q;
	    vector<int>topo;
	   
	    
	    
	    
	    //find the nodes which have indeg=0 and push it to the queue
	    
	    for(int i=0;i<V;i++){
	        
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    
	    while(!q.empty()){
	        
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        //traverse through adj nodes and reduce their indeg
	        
	        for(auto it : adjrev[node]){
	            
	            indeg[it]--;
	            
	            if(indeg[it]==0){
	                q.push(it);
	                
	            }
	        }
	    }
	
	sort(topo.begin(),topo.end());
	return topo;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends