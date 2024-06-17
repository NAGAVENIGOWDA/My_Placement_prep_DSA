//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       //pick and not pick
       
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       
       return f(n-1,W,wt,val,dp);
    }
    
    int f(int ind,int T,int wt[],int val[], vector<vector<int>>&dp){
        
        if(T==0){
            return 0;
        }
        
        if(ind==0){
            
            if(wt[ind]<=T) {
                return val[ind];
            }
            
            else {
                return 0;
            }
            
        }
        
        if(dp[ind][T]!=-1) return dp[ind][T];
        
        int notPick=0+f(ind-1,T,wt,val,dp);
        int pick=INT_MIN;
        if(wt[ind]<=T) {
            pick=val[ind]+f(ind-1,T-wt[ind],wt,val,dp);
        }
        
        return dp[ind][T]=max(notPick,pick);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends