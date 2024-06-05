//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
        vector<int>va(26,0);
        vector<int>vb(26,0);
        string ans;
        for(int i=0;i<A.size();i++){
            va[A[i]-'a'] =1;
        }
        for(int i=0;i<B.size() ;i++){
            vb[B[i]-'a']=1;
        }
        
        for(int i=0;i<26;i++){
            if(va[i]==0 && vb[i]==1) {
                char c=i+'a';
                ans.push_back(c);
                
            }
            if(va[i] > 0 && vb[i]==0){
                ans.push_back(i+'a');
            }
        }
        
        if(ans.length()==0) return "-1";
            
            
        return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends