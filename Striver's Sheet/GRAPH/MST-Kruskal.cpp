//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class disjointSet{
     public:
     vector<int>parent;
     vector<int>size;
     disjointSet(int n){
         
         parent.resize(n);
         size.resize(n);
         
         for(int i=0;i<n;i++){
             parent[i]=i;
             size[i]=1;
         }
         
     }
     
     
     int findParent(int node){
         
         if(node==parent[node])  return node;
         
         return parent[node]=findParent(parent[node]);
     }
     
     void unionBySize(int u ,int v){
         
         int pu=findParent(u);
         int pv=findParent(v);
         
         
         if(pu==pv) return ;
         
         if(size[pu] < size[pv]){
             
             parent[pu]=pv;
             size[pv]+=size[pu];
         }
         else{
             parent[pv]=pu;
             size[pu]+=size[pv];
         }
     }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
      //as adjaceny list given -need to construct and sort edges according to weights
      
      vector<pair<int,pair<int,int>>>edges;
      
      for(int i=0;i<V;i++){
          
          for(auto it:adj[i]){
              
              int node=i;
              int adjNode=it[0];
              int wt=it[1];
              
              edges.push_back({ wt,{node,adjNode}});
          }
      }
      
      
      //sort 
      sort(edges.begin(),edges.end());
      int sum=0;
      disjointSet ds(V);//creating obj of class
      for(auto edge : edges){
          
          int u=edge.second.first;
          int v=edge.second.second;
          int ewt=edge.first;
          
          if(ds.findParent(u)  != ds.findParent(v)){
              //they are not in the same component
              sum+=ewt;
              ds.unionBySize(u,v);
              
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