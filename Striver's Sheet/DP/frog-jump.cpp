//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*Geek wants to climb from the 0th stair to the (n-1)th stair. 
At a time the Geek can climb either one or two steps. 
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed 
in the jump is abs(height[i]- height[j]), where abs() means the absolute difference.
 return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.*/
// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        
        
    vector<int>dp(n+1,-1);
    return solve(n-1,height,dp); //why n-1 ?? from 0th to n-1 stair
    }
    
    int solve(int ind,vector<int>& height,vector<int>&dp){
        
    if(ind==0) return 0;//0 energy lost
    
    if(dp[ind]!=-1) return dp[ind];
    
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    
    if(ind>1) jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends