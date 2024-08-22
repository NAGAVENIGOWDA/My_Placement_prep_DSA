//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public :
  long long int mod=1e9+7;
   long long int f(int  n ,vector<long long int>&dp){
       if(n<=1) return n;
       
       if(dp[n] !=-1) return dp[n];
       
       return dp[n]=(f(n-1,dp) + f(n-2,dp)) % mod;
   }
    long long int topDown(int n) {
        // code here
        //memorisation 
        
        vector<long long int >dp(n+1,-1);
        return f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        
        long long int prev1=1;
        long long int prev2=0;
        
        for(int i=2;i<=n ;i++){
            
            int curr=(prev2+prev1)%mod;
            prev2=prev1;
            prev1=curr;
        }
        
        
    return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends