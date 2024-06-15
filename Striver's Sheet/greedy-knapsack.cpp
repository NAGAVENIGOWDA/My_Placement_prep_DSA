//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
       // Vector to store value/weight ratio and index
        vector<pair<double, int>> vw;
        double ans = 0.0;

        // Calculate value/weight ratio and store in vector
        for (int i = 0; i < n; i++) {
            double ratio = (double)arr[i].value / arr[i].weight;
            vw.push_back({ratio, i});
        }

        // Sort items based on value/weight ratio in descending order
        sort(vw.begin(), vw.end(), greater<pair<double, int>>());

        // Iterate through items
        for (int i = 0; i < n; i++) {
            // If the knapsack is full, break the loop
            if (W == 0) break;

            int idx = vw[i].second;
            // Take as much of the item as possible
            if (arr[idx].weight <= W) {
                W -= arr[idx].weight;
                ans += arr[idx].value;
            } else {
                // Take the fraction of the remaining weight
                ans += vw[i].first * W;
                W = 0; // Knapsack is full
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends