//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        
        string str='(' + s +')';
        stack<char>st;
        string ans="";
        
        map<char,int>mp;
        mp['(']=0;
        mp['*']=2;
        mp['/']=2;
        mp['+']=1;
        mp['-']=1;
        mp['^']=3;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(str[i]);
                
            }
            
            else if(str[i] >='a' && str[i] <='z'  || str[i]>='A' && str[i] <='Z' 
             || str[i]>='0' && str[i]<='9')
             
             
            {
                ans+=str[i];
            }

            
            else if(str[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                while(mp[str[i]] <= mp[st.top()]){
                    
                    ans+=st.top();
                    st.pop();
                    
                }
                st.push(str[i]);
            }
        }
        
        
    return ans;
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends