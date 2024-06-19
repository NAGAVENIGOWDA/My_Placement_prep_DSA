//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/**
 * 
Input:
4
Output:
[2 4 1 3 ] [3 1 4 2 ]
Explaination:
These are the 2 possible solutions.


 */
class Solution{
public:
    bool isValid(int row,int col,vector<vector<int>>board,int n)
    {
        int duprow = row;
        int dupcol = col;
        
        // For LeftUpper Most
        
        while(duprow>=0 && dupcol>=0)
        {
            if(board[duprow][dupcol] != 0)
            {
                return false;
            }
            
            duprow--;
            dupcol--;
        }
        
        
        duprow = row;
        dupcol = col;
        
        // left
        while(dupcol>=0)
        {
            if(board[duprow][dupcol] != 0)
            {
                return false;
            }
            dupcol--;
        }
        
        duprow = row;
        dupcol = col;
        
        
        // down left
        while(dupcol >=0 && duprow<n)
        {
            if(board[duprow][dupcol] !=0)
            {
                return false;
                
            }
            duprow++;
            dupcol--;
        }
            
        return true;  
        
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        
        
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        solve(0,n,board,ans);
        
        return ans;
    }
    
    void solve(int col,int n,vector<vector<int>>&board,vector<vector<int>>&ans){
        vector<int>tmp;
        if(col==n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[j][i]){
                      tmp.push_back(j+1);
                        
                    }
                }
            }
            
            ans.push_back(tmp);
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,n,board,ans);
                //backtracking
                board[row][col]=0;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends