//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    //Given an array of N elements, where each element is at most K away from its 
    //target position, devise an algorithm that sorts in O(N log K) time.

    
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        
        //declare a min heap -increasing order
        
        
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vector<int>ans;
        
        for(int i=0;i<num;i++) {
            
            if(pq.size() > K){
                
                ans.push_back(pq.top()) ; //top has lesser ele
                pq.pop();
                
            }
            pq.push(arr[i]);
        }
        
        
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends