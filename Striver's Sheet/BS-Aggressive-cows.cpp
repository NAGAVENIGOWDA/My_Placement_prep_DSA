//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

bool isPossibleToPlaceCows(int dist,int cows,vector<int>&a,int n){
    //initially 
    int cowsCnt=1;
    int lastPlaced=a[0];
    
    for(int i=1;i<n;i++){
        if(a[i]-lastPlaced >=dist){
            //possible to place
            
            cowsCnt++;
            lastPlaced=a[i];
        }
        
        if(cowsCnt >=cows){
            return true;
        }
        

    }
    
    
    return false;
}
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        //compulsorily -K>=2  --max distance (1-cow  at ind-0  and 2nd cow-last ind)
        //min distance c1 at ind 0 and C2 at ind 1
        
        //sort
        
        sort(stalls.begin(),stalls.end());
        
        int low=1;
        int ans=-1;
        int high=stalls[n-1]-stalls[0];
        
        //[1,dis(last-first)]
        
        while(low<=high){
            int mid=(low+high)/2;
            //mid -distance bw cows
            
            if(isPossibleToPlaceCows(mid,k,stalls,n)){
                //possible ans
                ans=mid;
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        //low > high --high will be at the previously obtained distnace
        
        //not possible return previously obtained dist
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends