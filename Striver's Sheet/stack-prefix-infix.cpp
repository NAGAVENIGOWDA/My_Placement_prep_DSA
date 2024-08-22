//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //in- +a+bc
    //out-  (a+(b+c))
    string preToInfix(string pre_exp) {
        // Stack to store intermediate results
        stack<string> st;
        int len = pre_exp.size();
        
        // Traverse the prefix expression in reverse order
        for (int i = len - 1; i >= 0; i--) {
            char c = pre_exp[i];
            
            // If the character is an operand (letter or digit)
            if (isalnum(c)) {
                st.push(string(1, c));
            }
            // If the character is an operator
            else {
                // Pop two operands from the stack
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                // Form a new string "(op1 operator op2)"
                string res = '(' + op1 + c + op2 + ')';
                
                // Push the result back to the stack
                st.push(res);
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends