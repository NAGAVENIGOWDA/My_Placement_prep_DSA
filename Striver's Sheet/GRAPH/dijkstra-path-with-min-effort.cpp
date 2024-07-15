//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
public:
    int MinimumEffort(int rows, int cols, vector<vector<int>> &heights) {
        // Priority queue to store {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
       
       
       //{diff,{row,col}}
        // Distance matrix to store minimum effort to reach each cell
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));

        // Starting with the top-left cell
        q.push({0, {0, 0}});
        dist[0][0] = 0;

        // Direction vectors for moving up, down, left, right
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto top = q.top();
            int diff = top.first;
            int row = top.second.first;
            int col = top.second.second;

            q.pop();

            // If reached the bottom-right cell, return the effort
            if (row == rows - 1 && col == cols - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols) {
                    int newdiff = abs(heights[row][col] - heights[nrow][ncol]);
                    int neweffort = max(diff, newdiff);
                    if (neweffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = neweffort;
                        q.push({neweffort, {nrow, ncol}});
                    }
                }
            }
        }

        return -1; // This should never be reached if input is valid
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends