//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        disjointSet ds(n*m);
        
        vector<vector<int>>visited(n ,vector<int>(m,0));
        
        int count=0;
        vector<int>ans;
        
        for(auto it : operators){
            
            int row=it[0];
            int col=it[1];
            
            if(visited[row][col]==1){
                //dont make any changes
                ans.push_back(count);
                continue;
                
            }
            
            visited[row][col]=1;
            count++;
            
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            
            for(int idx=0;idx<4;idx++){
                int adjr=row+dx[idx];
                int adjc=col+dy[idx];
                
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && visited[adjr][adjc]){
                    
                    int nodeNo=row * m + col;
                    
                    int adjNodeNo=adjr*m+adjc;
                    
                    if(ds.findParent(nodeNo) !=ds.findParent(adjNodeNo)){
                        count--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                    
                }
            }
            
            ans.push_back(count);
        }
        
        
    return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends