//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int>& A, vector<int>& B) {
        // Priority queue to store the sums along with their indices
        priority_queue<pair<int, pair<int, int>>> pq;
        // Set to keep track of the visited index pairs
        set<pair<int, int>> st;
        
        vector<int> ans;
        
        // Sort arrays A and B in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        // Initial pair (0, 0)
        pq.push({A[0] + B[0], {0, 0}});
        st.insert({0, 0});
        
        for (int k = 0; k < K; k++) {
            if (pq.empty()) break;
            
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            // Add the next pair (i + 1, j) to the priority queue if not already present
            if (i + 1 < N && st.find({i + 1, j}) == st.end()) {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            
            // Add the next pair (i, j + 1) to the priority queue if not already present
            if (j + 1 < N && st.find({i, j + 1}) == st.end()) {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends