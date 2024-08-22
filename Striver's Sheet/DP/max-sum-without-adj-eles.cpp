//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    
	  vector<int>dp(n+1,0);
	  
	  dp[0]=arr[0];
	  for(int i=1;i<=n;i++){
	      
	      int pick=arr[i];
	      
	      if(i>1){
	         pick+=dp[i-2] ;
	      }
	      int notpick=0+dp[i-1];
	      
	      dp[i]=max(pick,notpick);
	      
	      
	  }
	  
	  return dp[n-1];
	  
	}
	
	int f(vector<int>&arr, int n, vector<int>&dp){
	    
	    if(n==0) return arr[n];
	    if(n<0) return 0; 
	    
	    if(dp[n] !=-1) return dp[n];
	    
	    int pick=arr[n]+f(arr,n-2,dp);
	    int notpick=0 + f(arr,n-1,dp);
	    
	    return dp[n]=max(pick,notpick);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends