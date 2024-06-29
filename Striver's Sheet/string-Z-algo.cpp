//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<int> Z_func(string s){
        int N=s.length();
        vector<int>Z(N,0);
        
        int l=0;
        int r=0;
        for(int i=1;i<N;i++){
            if(i<r){
                //if i is withing the boundary 
                //reuse the values
                Z[i]=Z[i-l];
                
                if(i+Z[i] > r){
                    //going out of boundary -should restrict within the boundary
                    Z[i]=r-i;
                }
            }
            
            //check if the chars out of bound also matching -increase z[i] accordingly
            
            while(i+Z[i] < N && s[Z[i]]==s[i+Z[i]]){
                
                Z[i]++;
                
            }
            
            //adjust l and r 
            
            if(i+Z[i] > r){
                l=i;
                r=i+Z[i];
            }
        }
        
        
    return Z;
    }
    
    
        vector <int> search(string pat, string txt)
        {
            string patTxt=pat+'$'+txt;
            vector<int>Z=Z_func(patTxt);
            
            int m=pat.size();
            
            vector<int>ans;
            
             for(int i=m+1;i<patTxt.size();i++){
                 if(Z[i]==m){
                     ans.push_back(i-m);
                 }
             }
             
        return ans;
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends