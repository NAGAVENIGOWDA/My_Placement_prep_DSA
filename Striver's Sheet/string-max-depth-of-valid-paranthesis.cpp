//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        
        int count=0;
        int maxCount=INT_MIN;
        
        for(char c: s){
            if(c=='('){
                count++;
            }
            else if(c==')'){
                count--;
            }
            
            
        if(count<0) return -1;
        maxCount=max(maxCount,count);
        }
        
    return maxCount;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends