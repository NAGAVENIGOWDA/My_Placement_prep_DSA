//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        
        if(str1.size()!=str2.size()) return false;
        
        map<char,char>mp;
        
        for(int i=0;i<str1.size();i++){
            
            //check if char is already present
            if(mp.find(str1[i])!=mp.end()){
                //if present already -match them
                if(mp[str1[i]]!=str2[i]) return false;
            }
            
            else{
                //not present
                //the char is gonna get used should not be used before
                
                for(const auto&it:mp){
                    if(it.second==str2[i]) return false;
                }
                mp[str1[i]]=str2[i];
            }
        }
        
    
    return true;
        
    }
    
    
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends