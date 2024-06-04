/*
A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example 1

Input:
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1
Explanation: 1 is the minimum element in the array.

*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
    int ans=INT_MAX;
    if(n==1) return arr[0];
    if(arr[0] <arr[n-1]) return arr[0];
    
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid] >=arr[s]) {
            ans=min(ans,arr[s]);
            s=mid+1;
        }
        
        else{
            ans=min(arr[mid],ans);
            e=mid-1;
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
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends