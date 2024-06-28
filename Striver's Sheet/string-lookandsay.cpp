//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        
        if(n==1) return "1";
        if(n==2) return "11";
        
        string s="11";
        for(int i=3;i<=n;i++){
            //need to generate nth lookandsay
            
            string temp="";
            s=s+'$';
            int freq=1;
            for(int j=1;j<s.length();j++){
                if(s[j]!=s[j-1]){
                    temp=temp+to_string(freq);
                    temp=temp+s[j-1];
                    freq=1;
                }
                else{
                    freq++;
                }
                
            }
            
        s=temp;
        }
    return s;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends