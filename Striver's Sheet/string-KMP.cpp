//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    // Function to compute the LPS array
    void computeLPS(string &pat, vector<int> &lps) {
        int m = pat.length();
        int length = 0; // Length of the previous longest prefix suffix
        lps[0] = 0; // LPS[0] is always 0
        int i = 1;
        
        // Loop to calculate lps[i] for i = 1 to m-1
        while (i < m) {
            if (pat[i] == pat[length]) {
                length++;
                lps[i] = length;
                i++;
            } else { // (pat[i] != pat[length])
                if (length != 0) {
                    length = lps[length - 1];
                } else { // if (length == 0)
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    // Function to search the pattern in the text using KMP algorithm
    vector<int> search(string pat, string txt) {
        int m = pat.length();
        int n = txt.length();
        
        vector<int> lps(m);
        computeLPS(pat, lps);
        
        vector<int> result;
        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while (i < n) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            
            if (j == m) {
                result.push_back(i - j+1);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) { // mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        if (result.empty()) {
            result.push_back(-1);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends