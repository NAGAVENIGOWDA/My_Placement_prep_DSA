//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
    
    
    //min heap
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    unordered_map<int,int>mp;
    int rank=1;
     vector<int>ans;
    
    
    //push all the elements into minheap to sort
    for(int i=0;i<N;i++){
        pq.push(arr[i]);
    }
    
    while(!pq.empty()){
        
        int top=pq.top();
        if(mp.find(top)==mp.end()){//not there
        
        mp[top]=rank;
        rank++;
            
        }
        pq.pop();
    }
    
    
    
    //answer array
    
   
    
    for(int i=0;i<N;i++){
        
        arr[i]=mp[arr[i]];
    }


return arr;

    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends