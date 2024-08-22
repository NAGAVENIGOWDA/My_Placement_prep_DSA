//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*There are n stones and an array of heights and Geek is standing at stone 1 and can jump
 to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number 
 of steps that can be jumped and cost will be [hi-hj] is incurred, where j is the stone to land on.
  Find the minimum possible total cost incurred before the Geek reaches Stone n.*/

  //standing at 1 need to reach n --[0,n-1] intstead [1,n]
// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        
        vector<int>dp(n+1,-1);
        return f(height,n-1,k,dp);
    }
    
    int f(vector<int>& height, int n, int k,vector<int>&dp){
        
        if(n==0) return 0;
        
        if(dp[n] !=-1) return dp[n];
        
        int minjumps=INT_MAX;
        for(int i=1;i<=k;i++){
            
            if(n-i >=0){
                
               int jumps= f(height,n-i,k,dp) + abs(height[n] - height[n-i]);
               minjumps=min(minjumps,jumps);
            }
        }
        
    return dp[n] = minjumps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends