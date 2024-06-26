//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

//Given a binary matrix M of size n X m. 
//Find the maximum area of a rectangle formed only of 1s in the given matrix.
/*
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.

*/
class Solution{
  public:
  
   int largestHisto(vector<int>&M){
       
       int n=M.size();
       
       stack<int>st;
       int ans=INT_MIN;
       
       for(int i=0;i<=n;i++){
           
           while(!st.empty() && (i==n || M[i] <=M[st.top()])){
               
               int height=M[st.top()];
               st.pop();
               int width;
               if(st.empty()){
                   width=i;//right max
                   
               }
               
               else{
                   width=i-st.top()-1;
               }
               
               
               ans=max(ans,width*height);
           }
           
         st.push(i);
           
           
       }
       
     return ans;
   }
   
   
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        
        int maxArea=INT_MIN;
        
        vector<int>row(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1) row[j]++;
                else row[j]=0;
            }
            
            int area=largestHisto(row);
            maxArea=max(area,maxArea);
        }
        
    return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends