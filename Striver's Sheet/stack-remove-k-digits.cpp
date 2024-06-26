//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function

/*

Given a number k and string num of digits (0 to 9) denoting a positive integer. 
Find a string denoting the lowest integer number possible by removing k digits from num, 
without changing their order.
Note: num will not contain any leading zero.

*/
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>st;
    
    
    st.push(num[0]);
    
    
    for(int i=1;i<num.size();i++){
        
        while(!st.empty() && k>0 && num[i] < st.top()){
            
            k--;
            st.pop();
            
             
        }
        
        st.push(num[i]);
        
    }
    
    //cases when k>0
    
    //like monotonically increasing
    //pop the last ele
    
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
        
        
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
    reverse(ans.begin(),ans.end());
    
    while(ans[0]=='0' && ans.size()!=1){
        
        ans=ans.substr(1);
    }
    
    return ans;
        
        
    }
