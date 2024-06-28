//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans = 0;
        int i = 0;
        int l = s.length();
        int f = 1;

        if(s[0] == '-') {
            f = -1;
            i++; // Start conversion from the next character
        }

        while(i < l) {
            if(s[i] < '0' || s[i] > '9') {
                return -1; // Return -1 for non-numeric characters
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return ans * f;
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
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends