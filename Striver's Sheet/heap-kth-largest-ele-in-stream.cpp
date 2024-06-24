//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            
            if(pq.size() < k){
                pq.push(arr[i]);
            }
            
            else{
                if(arr[i] > pq.top()){
                    
                    //chances of the top ele being the kth largest is low
                    
                    //as it is higher push
                    
                    //if arr[i] < pq.top() -cant be in top k -just ignore it 
                    pq.push(arr[i]);
                    pq.pop();
                }
            }
            
            
            if(pq.size() < k){
                ans.push_back(-1);
            }
            else{
                ans.push_back(pq.top());
            }
        }
        
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends