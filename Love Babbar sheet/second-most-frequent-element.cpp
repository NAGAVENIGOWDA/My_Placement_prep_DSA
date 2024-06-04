//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string, int> mp;
        // Storing the frequency of each string in the map.
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        // Vector to store the frequency and corresponding string.
        vector<pair<int, string>> ans;
        for (const auto& it : mp) {
            ans.push_back({it.second, it.first});
        }

        // Sorting the vector based on frequencies in descending order.
        sort(ans.begin(), ans.end(), greater<pair<int, string>>());

        // Returning the second most frequent string.
        return ans[1].second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends