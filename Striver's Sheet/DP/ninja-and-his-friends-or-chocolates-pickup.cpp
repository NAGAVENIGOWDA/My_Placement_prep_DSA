//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        //3d dp
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                
                if(j1==j2){
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2]=grid[n-1][j1] + grid[n-1][j2];
                }
                
            }
            
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    
                    
                    
            int maxi=INT_MIN;
        
            for(int dj1=-1 ;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                
                int ans;

                if (j1 == j2)
                    ans = grid[i][j1];
                else
                    ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                if ((j1 + dj1 < 0 || j1 + dj1 >= m) || (j2 + dj1 < 0 || j2 + dj2 >= m))
                    ans += -1e9; 
                
                else
                    ans += dp[i + 1][j1 + dj1][j2 + dj2]; 

                maxi = max(ans, maxi); // Update the maximum result
            }
        }
        
        
        dp[i][j1][j2]=maxi;
        
                    
                }
            }
        }
        
        //return f(0,0,m-1,grid,dp);
        
        return dp[0][0][m-1];
    }
    
    int f(int i ,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        if(j1<0 || j1>=m || j2<0 || j2>=m){
            
            return -1e9;//that path will never get considered
        }
        
        if(i==n-1){
            
            if(j1==j2){
                return grid[i][j1]; //both are in same grid-collect once
            }
            
            else{
                return grid[i][j1] + grid[i][j2];//dif grid -collect both of chocos
            }
        }
        
        
        if(dp[i][j1][j2] !=-1) return dp[i][j1][j2];
        
        int maxi=INT_MIN;
        
        for(int dj1=-1 ;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                //3 * 3 diff options to move and collect the max value
                int value=0;
                if(j1==j2){
                    
                    value+=grid[i][j1] + f(i+1,j1+dj1,j2+dj2,grid,dp);
                }
                else{
                    value+=grid[i][j1]+grid[i][j2] + f(i+1,j1+dj1,j2+dj2,grid,dp);
                }
                
                maxi=max(maxi,value);
                
                
            }
        }
        
        
    return dp[i][j1][j2]=maxi;
        
        
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends