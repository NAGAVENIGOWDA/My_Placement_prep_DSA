//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
   private:
        int timer=0;
        void dfs(int n,int parent, int disc[], int low[], 
        vector<int> &vis,vector<int> adj[], int &res , int c ,int d){
            vis[n]=1;
            disc[n]=low[n]=timer;
            timer++;
            for(auto i: adj[n]){
                if(i==parent)continue;
                if(!vis[i]){
                  dfs(i,n,disc,low,vis,adj,res,c,d);
                  low[n]=min(low[n],low[i]);
                  if(low[i]>disc[n]){
                      if((n==c && i==d) || (n==d && i==c )){
                          res=1;
                      }
                  }
                }
                else {
                    low[n]=min(low[n],disc[i]);
                }
            }
        }
    public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int disc[V];
        int low[V];
        int parent[V];
        int res=0;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,disc,low,vis,adj,res,c,d);
            }
        }
        return res;
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends