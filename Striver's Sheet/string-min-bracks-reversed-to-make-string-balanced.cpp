//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    
    if(s.size()%2!=0){ //size should be even to be balanced
        return -1;
    }
    
    int count=0;
    int res=0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            count++;
        }
        else{
            if(count==0){
                //need to be balanced here
                count++; //')' --> '(' so count++ ,and u reversed here so add it to ans
                res++;
            }
            else{
                count--;
            }
        }
        
        
        
    }
    
    if(count>0){
        //means still have opening bracks need to reversed
        res=res + (count/2);
    }
    
    return res;
}