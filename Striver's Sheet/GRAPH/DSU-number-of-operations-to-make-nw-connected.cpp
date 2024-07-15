//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
/*ou are given a graph with n vertices (0 to n-1) and m edges. 
You can remove one edge from anywhere and add that edge between any two vertices
 in one operation. Find the minimum number of operations that will be required to 
 connect the graph.
If it is not possible to connect the graph, return -1.*/
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        //find number of components
        //and also find extra edges
        
        disjointSet ds(n);
        int extrEdges=0;
        
        for(auto edg : edge){
            
            int u=edg[0];
            int v=edg[1];
            
            if(ds.findParent(u)==ds.findParent(v)){
                //means they are alredy connected
                extrEdges++;
                continue;
                
            }
            else{
                ds.unionBySize(u,v);
            }
            
            
        }
        
        
        //find out number of compsz
        
        int comps=0;
        
        for(int i=0;i<n;i++){
            
            if(ds.parent[i]==i) comps++;
        }
        
        int ans=comps-1;
        
        if(extrEdges>=ans) return ans;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends