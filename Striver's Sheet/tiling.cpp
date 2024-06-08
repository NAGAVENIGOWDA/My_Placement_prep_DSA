//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
  
    int numberOfWays(int n) {
        vector<int> dp(n + 1, -1);
        return numberofway(n, dp);
    }
    
    int numberofway(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n == 1 || n == 2) return n;
        
        if (dp[n] != -1) return dp[n];
        
        int x = numberofway(n - 1, dp);
        int y = numberofway(n - 2, dp);
        
        return dp[n] = (x + y) % 1000000007;
    }
        //code here
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.numberOfWays(n) << endl;
    }
    return 0;
}
// } Driver Code Ends