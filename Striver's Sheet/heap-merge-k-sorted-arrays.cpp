//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        
     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //min heap
     
     vector<int>ans;
     
     //u pushed the 1st element of all the array
     
     for(int i=0;i<K;i++){
         pq.push({arr[i][0],{i,0}});
     }
     
     
     while(!pq.empty()){
         
         auto tmp=pq.top();
         int ele=tmp.first;
         int f=tmp.second.first;
         int s=tmp.second.second;
         
         pq.pop();
         
         ans.push_back(ele);
         if(f<K && s+1 < K){
             
             pq.push({arr[f][s+1],{f,s+1}});
             
         }
         
         
     }
     return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends