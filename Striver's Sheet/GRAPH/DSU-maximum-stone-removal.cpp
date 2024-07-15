//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet{
  public:
  vector<int> parent, rank;
  DisjointSet(int n){
      parent.resize(n+1);
      rank.resize(n+1);
      
      for(int i=0; i<=n; i++){
          parent[i]=i;
          rank[i]=0;
      }
  }
  
  int findParent(int node){
      if(parent[node]==node)    return node;
      
      return parent[node]=findParent(parent[node]);
  }
  
  void unionByRank(int node1, int node2){
      node1=findParent(node1);
      node2=findParent(node2);
      if(rank[node1]>rank[node2]){
          parent[node2]=node1;
      }
      else if(rank[node2]>rank[node1]){
          parent[node1]=node2;
      }
      else{
          parent[node2]=node1;
          rank[node1]++;
      }
  }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow=0, maxCol=0;             
        for(int i=0; i<stones.size(); i++){
            maxRow=max(maxRow, stones[i][0]);
            maxCol=max(maxCol, stones[i][1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);        
        unordered_map<int, int> stoneNodes;
        for(int i=0; i<stones.size(); i++){
            int row=stones[i][0];
            int col=stones[i][1]+maxRow+1;
            ds.unionByRank(row, col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }
        
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findParent(it.first)==it.first){
                cnt++;      // no of components
            }
        }

        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends