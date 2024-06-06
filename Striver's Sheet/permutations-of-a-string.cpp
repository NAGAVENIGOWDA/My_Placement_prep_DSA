//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Endsclass Solution

class Solution {
public:
    vector<string> find_permutation(string S) {
        vector<string> ans;
        permutations(S, 0, ans);
        sort(ans.begin(),ans.end());
            //remove unique permutations
            
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }

private:
    void permutations(string& s, int l, vector<string>& ans) {
        if (l >= s.size()) {
            ans.push_back(s);
            return;
        }

        for (int i = l; i < s.size(); i++) {
            swap(s[l], s[i]);
            permutations(s, l + 1, ans);
            swap(s[l], s[i]); // Backtrack
        }
    }
};	
		





//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends