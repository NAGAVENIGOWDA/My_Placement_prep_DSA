//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        
        //using max heap and queue
        
        priority_queue<int>pq;
        
        queue<pair<int,int>>q;
        
        vector<int>arr(26,0);
        for(auto i : tasks){
            arr[i-'A']++;
        }
        
        for(auto i : arr){
            if(i>0){
                pq.push(i);
            }
        }
        
        int t=0;
        
        while(pq.size() > 0 || q.size()>0){
            
            t++;
            if(q.size() >0 && q.front().second==t){
                pq.push(q.front().first);
                q.pop();
            }
            
            if(pq.size() > 0){
                if(pq.top()-1 > 0){
                    q.push({pq.top()-1,t+K+1});
                    
                }
                
                pq.pop();
            }
        }
        
    return t;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends