//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
         // Your code here
        stack<int> st1, st2;
        int left[n + 1], right[n + 1];
        
        // Initialize left and right
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }
        
        // Find left smaller for each element
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] >= arr[i]) {
                st1.pop();
            }
            if (!st1.empty()) {
                left[i] = st1.top();
            }
            st1.push(i);
        }
        
        // Find right smaller for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }
            if (!st2.empty()) {
                right[i] = st2.top();
            }
            st2.push(i);
        }
        
        // Initialize answer array to 0
        vector<int> ans(n + 1, 0);
        
        // Calculate length and update the answer array
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            // Means till window length 'len', arr[i] can be minimum
            ans[len] = max(ans[len], arr[i]);
        }
        
        // Fill the remaining entries
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        
        // Create the final answer vector
        vector<int> finalAns(ans.begin() + 1, ans.end());
        
        return finalAns;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends