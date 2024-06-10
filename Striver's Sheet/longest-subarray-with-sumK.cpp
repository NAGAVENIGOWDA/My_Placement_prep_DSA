//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        unordered_map<int, int> mpp; 
        int maxi = 0;
        int sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += A[i]; 
            if (sum == k) {
                maxi = max(maxi,i+1) ;
            }
            if (mpp.find(sum - k) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum - k]);
            }
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }
        return maxi; 
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends