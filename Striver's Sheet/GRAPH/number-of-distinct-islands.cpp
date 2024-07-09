//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n=grid.size();
        int m =grid[0].size();
        
        set<vector<pair<int,int>>>st;
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(i,j,visited,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
    return st.size();
    }
    
    private:
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    void dfs(int row,int col,vector<vector<bool>>&visited,vector<vector<int>>& grid,vector<pair<int,int>>&vec,int row0,int col0)
    {   
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        visited[row][col]=true;
        vec.push_back({row-row0,col-col0});
        
        for(int i=0;i<4;i++){
            int nr=row+dx[i];
            int nc=col+dy[i];
            
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                
                dfs(nr,nc,visited,grid,vec,row0,col0);
                
            }
        }
    }
    
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends