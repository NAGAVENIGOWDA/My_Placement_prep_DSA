//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        
        int n = arr.size();
        
        // Step 1: Create a queue
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        // Step 2: Create a visited array
        vector<bool> vis(mod, 0);
        vis[start] = 1;
        
        // Step 3: BFS
        while(!q.empty()){
            
            int steps = q.front().second;
            int u = q.front().first;
            q.pop();
            
            if(u == end) return steps;
            
            // Traverse in all possible new states
            for(int i=0; i<n; i++){
                int newState = (u * arr[i]) % mod;
                if(!vis[newState]){
                    q.push({newState, steps + 1});
                    vis[newState] = 1;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends