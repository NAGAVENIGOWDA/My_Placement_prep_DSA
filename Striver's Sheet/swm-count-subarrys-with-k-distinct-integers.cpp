//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int subarrayswithsumK(vector<int>&arr,int N,int k){
        
        
        unordered_map<int,int>mp;
        
        int l=0;
        int r=0;
        int count=0;
        while(r<N){
            mp[arr[r]]++;
            
            while(mp.size() > k){
                mp[arr[l]]--;
                
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                
                l++;
            }
            
        count+=r-l+1;
        r++;
        }
        
    return count;
    }
    
    
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        
        
    return subarrayswithsumK(arr,N,k)-subarrayswithsumK(arr,N,k-1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends