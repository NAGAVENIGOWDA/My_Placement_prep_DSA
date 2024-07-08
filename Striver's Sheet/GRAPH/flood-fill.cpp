//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting 
pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels 
(also with the same color as the starting pixel), and so on. Replace the color of all of the 
aforementioned pixels with the newColor.*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        // Directions for movement (right, left, down, up)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                // Check boundaries and old color match
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == oldColor) {
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends