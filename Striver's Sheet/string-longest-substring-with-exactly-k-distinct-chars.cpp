//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int l=0;
    int r=0;
    int ans=-1;
    int distinctCount=0;
    vector<int>charfreq(26,0);
    
    while(r<s.size()){
        
        charfreq[s[r]-'a']++;
        
        if(charfreq[s[r]-'a']==1){
            //distict char
            distinctCount++;
        }
        
        while(distinctCount>k){
            charfreq[s[l]-'a']--;
            
            if(charfreq[s[l]-'a']==0){
                //1 distinct got reduced
                distinctCount--;
            }
            l++;
        }
        
    if(distinctCount==k)ans=max(ans,r-l+1);
    r++;
    
    
        
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends