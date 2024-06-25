//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        
        int len=post_exp.size();
        stack<string>st;
        for(int i=0;i<len;i++){
            char c=post_exp[i];
             if(isalnum(c)){
                 st.push(string(1,c));
             }
             else{
                 string s1=st.top(); st.pop();
                 string s2=st.top();st.pop();
                 
                 st.push(c+s2+s1);
             }
            
            
        }
        
    return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends