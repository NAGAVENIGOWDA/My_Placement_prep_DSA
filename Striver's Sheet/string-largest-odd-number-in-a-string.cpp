//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
     string s1="";
        for(int i=0;i<s.length();i++){
            
            if(s[i]%2!=0){
                
                 s1=s.substr(0,i+1);
                 
            }
        }
        
        
    return s1;
   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends