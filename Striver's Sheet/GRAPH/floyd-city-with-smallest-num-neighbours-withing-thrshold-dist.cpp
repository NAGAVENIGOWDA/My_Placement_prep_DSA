//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        vector<vector<int>>grid(n,vector<int>(n,1e9));
        
        for(auto it : edges){
            
            //bidrectional
            grid[it[0]][it[1]]=it[2];
            grid[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++) grid[i][i]=0;
        
        floydWarshall(grid,n);
        
        int countCity=n;
        int cityNum=-1;
        
        for(int city=0;city<n;city++){
            int count=0;
            
            for(int adjCity=0;adjCity<n;adjCity++){
                if(grid[city][adjCity] <= distanceThreshold) count++;
            }
            
            if(count<=countCity) {
                countCity=count;
                cityNum=city;
            }
        }
        
    return cityNum;
        
    }
    
    void floydWarshall(vector<vector<int>>&grid,int n){
        
        
    
     
     for(int k=0;k<n;k++){
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 
                 grid[i][j]=min(grid[i][j],grid[i][k] +  grid[k][j]);
             }
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends