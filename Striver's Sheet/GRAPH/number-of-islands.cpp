//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by 
connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.*/
class Solution {
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));  // Initialize visited array
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        
        return count;
    }
    
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        
        // Directions for 8 possible movements (left, right, up, down, and 4 diagonals)
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                int neighrow = r + directions[i][0];
                int neighcol = c + directions[i][1];
                
                if (neighrow >= 0 && neighrow < n && neighcol >= 0 && neighcol < m &&
                    grid[neighrow][neighcol] == '1' && !visited[neighrow][neighcol]) {
                    visited[neighrow][neighcol] = 1;
                    q.push({neighrow, neighcol});
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends