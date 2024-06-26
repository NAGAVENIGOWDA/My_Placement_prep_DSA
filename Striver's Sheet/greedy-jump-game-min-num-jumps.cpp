//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        //O(N) solution
        
         // If there is only one element, no jumps are needed
        if (n == 1) return 0;

        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, arr[i] + i);
            }
            if (farthest <= r) {
                // If farthest is not increasing, then we are stuck
                return -1;
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends