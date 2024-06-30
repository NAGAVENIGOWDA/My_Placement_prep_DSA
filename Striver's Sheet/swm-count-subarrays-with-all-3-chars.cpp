//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        
       int arr[3]={-1,-1,-1};
        
        int count=0;
        
        for(int i=0;i<s.size();i++){
            
            arr[s[i]-'a']=i;
            
            if(arr[0] !=-1 && arr[1]!=-1 && arr[2]!=-1){
                
                
                count += 1 + min(arr[0],min(arr[1],arr[2]));
            }
        }
        
    return count;
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends