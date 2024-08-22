//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    /*in=abc++
    out:  (a+(b+c))*/
  public:
    string postToInfix(string expr) {
     // Stack to store intermediate results
        stack<string> st;
        int len = expr.size();
        
        // Traverse the postfix expression in order
        for (int i = 0; i < len; i++) {
            char c = expr[i];
            
            // If the character is an operand (letter or digit)
            if (isalnum(c)) {
                st.push(string(1, c));
            }
            // If the character is an operator
            else {
                // Pop two operands from the stack
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                
               
            
                
                // Push the result back to the stack
                st.push( '(' + op1 + c + op2 + ')');
            }
        }
        
        // The final result is in the top of the stack
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
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends