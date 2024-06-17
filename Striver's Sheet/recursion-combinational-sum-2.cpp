//unique subsets



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(A.begin(),A.end());
        f(0,B,A,ans,ds);
        return ans;
    }
    
    void f(int ind,int T,vector<int>A,vector<vector<int>>&ans,vector<int>&ds){
        
        
        
        //need to remove duplicates also
        
        if(T==0){
            ans.push_back(ds);
            return;
            
        }
        for(int i=ind;i<A.size();i++){
            
            if((i!=ind && A[i]==A[i-1])) continue;
            if(A[i]<=T  ){
                ds.push_back(A[i]);
                f(i,T-A[i],A,ans,ds);
                ds.pop_back();
                
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends



//each number used once


/*

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates,ans,ds);
        return ans;
    }


    void f(int ind,int T,vector<int>A,vector<vector<int>>&ans,vector<int>ds){

        if(T==0){
            ans.push_back(ds);
            return;

        }
        for(int i=ind ;i<A.size();i++){
            //skip duplicates

            if(i!=ind && A[i]==A[i-1]){
                continue;
            }

        //pick /notPick
        if(A[i]<=T){
            ds.push_back(A[i]);
            f(i+1,T-A[i],A,ans,ds);  //each number used once 
            ds.pop_back();
        }
        }
    }
};


 */