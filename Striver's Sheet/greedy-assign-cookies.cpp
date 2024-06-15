//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // Sort both arrays
        sort(greed.begin(), greed.end());
        sort(sz.begin(), sz.end());
        
        int l = 0; // Pointer for children's greed
        int r = 0; // Pointer for cookie sizes
        int satisfied = 0; // Count of satisfied children
        
        while (l < N && r < M) {
            if (sz[r] >= greed[l]) {
                // If the current cookie size can satisfy the current child
                satisfied++;
                l++; // Move to the next child
            }
            // Regardless of whether the current cookie can satisfy,
            // move to the next cookie size
            r++;
        }
        
        return satisfied;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends