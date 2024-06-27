//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        //use hashmap
        if(a.size()!=b.size()) return false;
        
        unordered_map<char,int>frq;
        
        for(int i=0;i<a.size();i++){
            frq[a[i]]++;
        }
        
        for(int i=0;i<b.size();i++){
            
            if(frq.find(b[i])!=frq.end()){
                //if present
                frq[b[i]]--;
            }
            else{
                return false;
            }
        }
        
    //if all the count==0 then true else false
    
    for( auto it : frq){
        if(it.second !=0) return false;
    }
        
        
    return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends