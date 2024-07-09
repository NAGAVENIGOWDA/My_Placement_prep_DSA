//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<int>visited(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	 //there are nodes when no outgoing edges -DAG  it is and also for connected components
	            dfs(i,visited,adj,st);
	        }
	    }
	    
	    //whaterver there in the stack is the ans
	    
	    vector<int>topo;
	    
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    
	   return topo;
	}
	
	
	void dfs(int node ,vector<int>&visited,vector<int> adj[],stack<int>&st){
	    
	    visited[node]=1;
	    
	    for(auto adjNode : adj[node]){
	        if(!visited[adjNode]){
	            dfs(adjNode,visited,adj,st);
	        }
	    }
	    
	    
	   //while returning after all adjNodes -push it to stack
	   st.push(node);
	}
	
	
	
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends