//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code 
        
        queue<pair<int,int>>q;
       
        int n=grid.size();
        int m =grid[0].size();
        
        vector<vector<int>>gridCopy=grid;
         vector<vector<bool>>visited(n,vector<bool>(m,false));
         
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    gridCopy[i][j]=0;
                    visited[i][j]=true;
                    
                }
            }
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int dist=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            dist++;
            
            
            while(sz--){
                
                auto top=q.front();
                int row=top.first;
                int col=top.second;
            
                q.pop();
                
                for(int i=0;i<4;i++){
                    
                    int nr=row+dx[i];
                    int nc=col+dy[i];
                    
                    if(nr >=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                        
                        gridCopy[nr][nc]=dist;
                        visited[nr][nc]=true;
                        q.push({nr,nc});
                    }
                    
            
                    
                }
                
            }
            
            
            
            
            
            
        }
        
    return gridCopy;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends