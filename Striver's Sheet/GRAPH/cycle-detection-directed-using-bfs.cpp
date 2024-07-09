//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		//KAHN'S algo
	    
	    
	    queue<int>q;
	    vector<int>topo;
	    //find indegree
	    
	    int indeg[V]={0};
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indeg[it]++;
	        }
	    }
	    
	    
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
	        
	        for(auto it : adj[node]){
	            
	            indeg[it]--;
	            
	            if(indeg[it]==0){
	                q.push(it);
	                
	            }
	        }
	    }
	//if topo size is same as number of nodes -means no cycle
	
     return (topo.size()==V)?false:true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends