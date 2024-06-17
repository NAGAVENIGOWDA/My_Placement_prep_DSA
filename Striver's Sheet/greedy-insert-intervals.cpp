//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        
        vector<vector<int>>ans;
        int i=0;
        //left portion
        
        while(i<n && intervals[i][1] < newEvent[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        
        //overlapping portion
        
        while(i<n && intervals[i][0] <= newEvent[1]){
            newEvent[0]=min(newEvent[0],intervals[i][0]);
           newEvent[1]=max(newEvent[1],intervals[i][1]);
           i++;
        }
        
        ans.push_back(newEvent);
        
        //right portion
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends