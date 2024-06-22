//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of n weights. Find the least weight capacity of a boat to ship all weights within d days.
The ith weight has a weight of arr[i]. Each day, we load the boat with weights given by arr[i].We may not load more weight than the maximum weight capacity of the ship.*/
// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int Days(int arr[],int cap,int n){
      
      
      int days=1;
      int load=0;
      
      for(int i=0;i<n;i++){
          
          if(load+arr[i] > cap){
              days++;
              load=arr[i];
          }
          else{
              load+=arr[i];
          }
          
      }
      
      return days;
      
  }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        
        //capacity ranges from maxele-->
        int ans=INT_MAX;
        int low = *max_element(arr, arr+n);
        int high = accumulate(arr, arr+n, 0);
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int noDays=Days(arr,mid,n);
            
            if(noDays<=d){
                
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends