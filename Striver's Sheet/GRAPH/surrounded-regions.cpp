//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
     public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int j = 0; j < m; j++) {
            // first and last row
            if (mat[0][j] == 'O' && !visited[0][j]) {
                dfs(0, j, visited, mat);
            }
            if (mat[n-1][j] == 'O' && !visited[n-1][j]) {
                dfs(n-1, j, visited, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            // 1st col and last col
            if (mat[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, mat);
            }
            if (mat[i][m-1] == 'O' && !visited[i][m-1]) {
                dfs(i, m-1, visited, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' && !visited[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }

private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& mat) {
        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];

            if (nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && 
                mat[nr][nc] == 'O' && !visited[nr][nc]) {
                dfs(nr, nc, visited, mat);
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends