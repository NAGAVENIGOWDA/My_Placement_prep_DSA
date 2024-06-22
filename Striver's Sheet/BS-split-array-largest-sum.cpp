//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //as same as painters partition and pages allocation to students
  //max sum allocated is minimum
  
  int isPossible(long long  mid,int arr[],int n ,int k){
      
      
        int arrays = 1; 
        int sum = 0; 

        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
               
                sum += arr[i];
            } else {
               
                arrays++;
                sum = arr[i];

            }
        }

        return arrays;
  }
  
    int splitArray(int arr[] ,int n, int k) {
        // code here
        
        int low = *max_element(arr, arr + n); 
        int high = accumulate(arr, arr + n, 0LL); 
        
        while (low <= high) {
           int mid = (low + high) / 2;
            
            if (isPossible(mid, arr, n, k) > k) {
                
                low = mid + 1;
            } else {
               
                high = mid - 1;
            }
        }
        
        return low;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends