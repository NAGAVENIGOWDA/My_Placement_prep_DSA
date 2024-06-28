//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n=S.size();
        if(n<=1){
            return S;
        }
        
        string max_str= "";  
        
        for(int i=0;i<n;i++){
            //odd
        string oddExpand = expansion_from_center(S,i,i);
 
        //Even
        string evenExpand = expansion_from_center(S,i,i+1);
        if(max_str.size() < oddExpand.size()) max_str = oddExpand;
        if(max_str.size() < evenExpand.size()) max_str = evenExpand;

    
      } 
        
        
    return max_str;
    }
    
    string expansion_from_center(string &s,int i,int j){
    
        while(i>=0 && j<s.size() && s[i] ==s[j]){
            i--;
            j++;
        }
        
        //now i and j is pointing to non-matching char
        
        return s.substr(i+1,j-i-1);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends