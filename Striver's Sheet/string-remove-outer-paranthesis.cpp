//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        
        int inner=0;
        int outer=0;
        
        int start=0;
        string res="";
        
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                inner++;
            }
            else if(c==')'){
                outer++;
            }
            
            if(inner==outer){
                
                res+=s.substr(start+1,i-start-1);
                start=i+1;
                
                
            }
        }
        
    return res;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends