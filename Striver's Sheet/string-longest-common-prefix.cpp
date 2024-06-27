//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        
    string res=arr[0];
    int len =res.length();
    
    for(int i=1;i<N;i++){
        while(arr[i].find(res)!=0) //not at the first pos or may not be found
        
        {
            res=res.substr(0,len-1);
            len--;
            
           if(res=="") return "-1";
        }
    }
    
    
    return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends