//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        
        
        //pre insert p's chars in map
        
        int l = 0, r=0;
        int n = s.size(), m = t.size();
        int cnt = 0, minLen = 1e7;
        int startInd = -1;
        
        
       int mp[256]={0};
        
        for(int i=0;i<m;i++) mp[t[i]]++;

        while(r<n){
            if(mp[s[r]]>0) cnt++;
            
            mp[s[r]]--;


            while(cnt==m){
                if(r-l+1 < minLen){
                    minLen = (r-l+1);
                    startInd = l;
                }

                mp[s[l]]++;
                if(mp[s[l]]  > 0 ){
                    cnt--;
                }
                
                l++;
            }
            
            r++;
        }
        return startInd == -1 ? "-1" : s.substr(startInd,minLen);
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends