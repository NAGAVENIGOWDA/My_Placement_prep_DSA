//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}



// } Driver Code Ends


int longestSubstrDistinctChars (string str)
{
    // your code here
     unordered_set<int>s;
    int l=0,maxi=INT_MIN;
    
    for(int r=0;r<str.size();r++)
    {
      
       while(s.find(str[r])!=s.end())
       {
            s.erase(str[l]);
            l++;
       }
        s.insert(str[r]);  
        
        maxi=max(maxi,r-l+1);
       
    }
    return maxi;  
    
}