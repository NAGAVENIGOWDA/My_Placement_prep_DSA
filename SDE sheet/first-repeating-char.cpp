//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{map<char,int>m;
   
   for(int i=0;i<s.size();i++)
   {
       m[s[i]]++;
       
       if(m[s[i]]==2) return string(1, s[i]);
   }
   return "-1";
  

}