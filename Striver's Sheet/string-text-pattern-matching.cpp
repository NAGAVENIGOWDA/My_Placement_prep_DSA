//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  /*
  Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 

Return -1 if pattern doesn't exist as a substring in text.

*/
    int findMatching(string text, string pat) {
        // Code here
        int n=text.size()-pat.size();
        
        if(pat.size() > text.size()) return -1;
       
       
        for(int i=0;i<=n;i++){
            for(int j=0;j<pat.size();j++){
                
                if(text[i+j]!=pat[j]){
                    break;
                }
                if(j==pat.size()-1){
                    //matched
                    return i;
                }
            }
        }
        
    return -1;
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends