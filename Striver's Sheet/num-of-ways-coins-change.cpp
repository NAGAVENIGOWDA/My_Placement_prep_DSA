//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, 0));

        // Base case initialization
        for (int s = 0; s <= sum; s++) {
            dp[0][s] = (s % coins[0] == 0);
        }

        // Fill dp table
        for (int ind = 1; ind < N; ind++) {
            for (int T = 0; T <= sum; T++) {
                long long int Notake = dp[ind - 1][T];
                long long int take = 0;
                
                if (coins[ind] <= T) {
                    take = dp[ind][T - coins[ind]];
                }
                
                dp[ind][T] = Notake + take;
            }
        }

        return dp[N - 1][sum];
        

    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends