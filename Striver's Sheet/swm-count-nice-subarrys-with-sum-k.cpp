//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

/*
You are given array nums of n elements and integer k, count the number of subarrays that has k odd numbers.

Example1:

Input:
n = 5
nums = [1,1,2,1,1]
k = 3
Output:
2
Explanation:
There are 2 subarrays with k odds [1,1,2,1] and [1,2,1,1]*/
  
  int subarraysWithAtmostK(vector<int>& a, int t){
      
      int N=a.size();
       
       int l=0;
       int r=0;
       int count=0;
       int sum=0;
       while(r<N){
           
           sum=sum+(a[r] %2);
           
           while(sum>t){
               sum=sum-(a[l] %2);
               l++;
           }
           
           if(sum<=t){
               count+=(r-l+1);
           }
           
           
          r++;
          
           
           
       }
       
     return count;
   }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return subarraysWithAtmostK(nums,k)-subarraysWithAtmostK(nums,k-1);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends