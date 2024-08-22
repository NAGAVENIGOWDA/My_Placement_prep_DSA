//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
       
        int n=arr.size();
         /*
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        
        
        for(int idx=0;idx<n;idx++){
            dp[idx][0]=true;
        }
        if(arr[0] <= sum) dp[0][arr[0]]=true;
        
        
        for(int ind=1;ind<n;ind++){
            for(int tgt=1;tgt<=sum;tgt++){
                
                bool notTake=dp[ind-1][tgt];
                bool take=false;
                if(arr[ind]<=tgt) 
                {
                    
                take= dp[ind-1][tgt-arr[ind]];
                    
                    
                }
                
                dp[ind][tgt]=take || notTake;
                
            }
        }
        
        // f(n-1,sum,arr,dp);
        
        return dp[n-1][sum];
        
        */
        
        return isSubsetSumUtil(n,sum,arr);
        
        
    }
    
    
    bool isSubsetSumUtil(int n,int k,vector<int>arr){
        
       
    vector<bool> prev(k + 1, false);
    prev[0] = true;

    
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    
    for (int ind = 1; ind < n; ind++) {
       
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
         
            bool notTaken = prev[target];
            bool taken = false;
            
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            
            cur[target] = notTaken || taken;
        }

        
        prev = cur;
    }

  
    return prev[k];
    }
    
    
    bool f(int ind,int tgt,vector<int>arr,vector<vector<int>>&dp){
        
        if(tgt==0) return true;
        
        if(ind==0){
            //check if ele at indx is eqaul to target 
            //target -arr[0] =0 -may be
            
            return (tgt==arr[ind] );
        }
        if(dp[ind][tgt] !=-1) return dp[ind][tgt];
        
        bool notTake=f(ind-1,tgt,arr,dp);
        bool take=false;
        if(arr[ind]<=tgt) {
           take= f(ind-1,tgt-arr[ind],arr,dp);
        }
        
        
      return dp[ind][tgt]=take || notTake;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends