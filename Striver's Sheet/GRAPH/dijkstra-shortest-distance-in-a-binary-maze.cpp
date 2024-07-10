//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source,
                     pair<int, int> destination) {
        // Code here

        if (grid[source.first][source.second] == 0 ||
            grid[destination.first][destination.second] == 0) {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {

            auto top = q.front();
            q.pop();

            int step = top.first;

            int row = top.second.first;
            int col = top.second.second;

            if (row == destination.first && col == destination.second) {
                return step;
            }

            // Move in 4 directions
            for (int i = 0; i < 4; i++) {

                int newr = row + dx[i];
                int newc = col + dy[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1
                    && step + 1 < dist[newr][newc]) {

                    dist[newr][newc] = step + 1;
                    q.push({step + 1, {newr, newc}});
                }
            }
        }

        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends