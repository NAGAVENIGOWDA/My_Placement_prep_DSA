//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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
    
    private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    
    
   public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
      int n = grid.size();
        disjointSet ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        //case when all elements are 1 -no zero
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends