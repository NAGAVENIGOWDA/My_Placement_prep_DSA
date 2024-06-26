//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        stack<pair<int, int>> s1, s2;
        
        vector<int> left(N), right(N);
        
        // Calculate left count
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            while (!s1.empty() && arr[i] < s1.top().first) {
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], cnt});
            left[i] = cnt;
        }
        
        // Calculate right count
        for (int i = N - 1; i >= 0; i--) {
            int cnt = 1;
            while (!s2.empty() && arr[i] <= s2.top().first) {
                
                //to handle the case of duplicates -<=---include it in eithe left or right loop
                //to avoid counting 2 times
                cnt += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], cnt});
            right[i] = cnt;
        }
        
        // Calculate the sum of subarray minimums
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < N; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        
        return ans;
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends