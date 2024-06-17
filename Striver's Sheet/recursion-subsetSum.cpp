//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
  
    vector<int>ans;
    f(0,arr,ans,0);
    
    return ans;
    }
    
    void f(int ind,vector<int> arr,vector<int>&ans,int sum){
        
        
    if(ind==arr.size()){
        ans.push_back(sum);
        return ;
    }
        
   //pick and not pick
    f(ind+1,arr,ans,sum+arr[ind]);
    f(ind+1,arr,ans,sum);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends