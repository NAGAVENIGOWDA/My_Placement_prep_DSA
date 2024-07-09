//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int j = 0; j < m; j++) {
            // first and last row
            if (mat[0][j] == 1 && !visited[0][j]) {
                dfs(0, j, visited, mat);
            }
            if (mat[n-1][j] == 1 && !visited[n-1][j]) {
                dfs(n-1, j, visited, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            // 1st col and last col
            if (mat[i][0] == 1 && !visited[i][0]) {
                dfs(i, 0, visited, mat);
            }
            if (mat[i][m-1] == 1 && !visited[i][m-1]) {
                dfs(i, m-1, visited, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && !visited[i][j]) {
                   ans++;
                }
            }
        }

        return ans;
    }
    
    private:
    
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& mat) {
        
        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];

            if (nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && 
                mat[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc, visited, mat);
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends