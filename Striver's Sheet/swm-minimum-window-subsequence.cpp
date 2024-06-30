//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here
        int j=0;
        int start=-1;
        int minwindow=INT_MAX;
        for(int i=0;i<s.size();i++){
            
            if(s[i]==t[j]){
                j++;
            }
            
            if(j==t.size()){
                
                j--;
                int end=i;
                while(j>=0){
                    if(s[i] ==t[j]){
                        j--;
                    }
                    i--;
                }
                
            i++;
            j++;
            
            if(end-i+1 < minwindow){
                
                minwindow=end-i+1;
                start=i;
                
            }
                
                
            }
        }
        
    return minwindow==INT_MAX ? "":s.substr(start,minwindow);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends