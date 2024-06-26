//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    bool knows(int a, int b,vector<vector<int> >& M) { return M[a][b]; }
    
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        //Elimination technique
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            
            int f=st.top();
            st.pop();
            int s=st.top();
            st.pop();
            
            if(knows(f,s,M)){
                st.push(s);
                //means f cant be a celeb 
            }
            else{
                st.push(f);
            }
        }
        
       // Potential candidate?
        int C = st.top();
        st.pop();

    // Check if C is actually
    // a celebrity or not
        for (int i = 0; i < n; i++) {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C) && (knows(C, i,M) || !knows(i, C,M)))
            return -1;
    }

    return C;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends