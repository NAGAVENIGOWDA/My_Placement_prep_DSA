//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  int isPossible(long long  mid,int arr[],int n ,int k){
      
      // Calculate number of painters required
        int painter = 1; // Start with one painter
        long long sum = 0; // Sum of partitions for the current painter

        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
                // Add current partition to the current painter's work
                sum += arr[i];
            } else {
                // Assign current partition to a new painter
                painter++;
                sum = arr[i];

            }
        }

        return painter;
  }
  
  
    long long minTime(int arr[], int n, int k)
    {
        // Return minimum time to paint all partitions
        long long low = *max_element(arr, arr + n); // Max partition time
        long long high = accumulate(arr, arr + n, 0LL); // Total time for all partitions
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            
            if (isPossible(mid, arr, n, k) > k) {
                // If more painters are required, increase the minimum time
                low = mid + 1;
            } else {
                // Otherwise, try for a smaller maximum time
                high = mid - 1;
            }
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends