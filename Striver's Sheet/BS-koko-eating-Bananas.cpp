//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
 
 
    int Solve(int N, vector<int>& piles, int H) {
        //the ans can range from [1,maxele(piles)]
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(sumByD(piles,mid) <=H){
                
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends