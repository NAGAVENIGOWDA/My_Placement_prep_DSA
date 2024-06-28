//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        
        /*
        int l=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='.'){
                reverse(s.begin()+l , s.begin()+i);
                l=i+1;
            }
            
            
        }
        
        //last word
        reverse(s.begin()+l,s.end());
    return s;
    
    */
    
    
    stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+='.';
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends