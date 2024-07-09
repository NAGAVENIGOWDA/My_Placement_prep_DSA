//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    /*There are a total of n tasks you have to pick, labelled from 0 to n-1. 
    Some tasks may have prerequisite tasks, for example to pick task 0 you have to first 
    finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a
 ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. 
If it is impossible to finish all tasks, return an empty array.
 Driver code will print "No Ordering Possible", on returning an empty array. 
 Returning any correct order will give the output as 1, whereas any invalid order 
 will give the output 0. */
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> pre) 
    {
        // Code here
	    vector<int>adj[V];
	    
	    for(auto it : pre){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    
	    
	    
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
	
     if(topo.size()==V){
         return topo;
     }
     return {} ;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends