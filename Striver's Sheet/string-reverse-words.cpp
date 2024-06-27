//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    {   
        
     int left=0;
     string ans="";
     string tmp="";
     while(left <s.size()){
         
         if(s[left]=='.'){
             
             if(ans!="") ans=tmp+'.'+ans;
             else ans=  tmp;
             tmp="";
             
         }
         else{
             tmp+=s[left];
         }
         
        left++;
     }
     
     
    //last word
    if(tmp!=""){
        if(ans!=""){
            
            ans=tmp +'.'+ ans;
            
        }
        else ans=tmp;//case only one word
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends