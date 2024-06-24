//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        
        //min heap 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
        
        for(const auto &x : mp){
            pair<int,int>p=make_pair(x.second,x.first);  
            
            if(pq.size() < k){
                pq.push(p);
            }
            else  if(p.first>pq.top().first)    //maintaining a priority queue of max size k
             {
                    pq.push(p);                  

                    pq.pop();
                 
             }
             else if(p.first==pq.top().first && p.second>pq.top().second) {
                   pq.push(p);              
                    pq.pop();
             }
               
            
            
        }
        
        
        vector<int>ans;
           while(!pq.empty()){
               ans.push_back(pq.top().second);
               pq.pop();
           }
            
        
          reverse(ans.begin(),ans.end());
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends