//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    void solve(string s, string ds, set<string> &ans, int ind) {
        if (ind >= s.length()) {
            if (isVowel(ds[0]) && !isVowel(ds[ds.length() - 1])) {
                ans.insert(ds);
            }
            return;
        }

        // pick the current character
        solve(s, ds + s[ind], ans, ind + 1);
        
        // do not pick the current character
        solve(s, ds, ans, ind + 1);
    }
    
    set<string> allPossibleSubsequences(string S) {
        string ds = "";
        set<string> ans;
        solve(S, ds, ans, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends