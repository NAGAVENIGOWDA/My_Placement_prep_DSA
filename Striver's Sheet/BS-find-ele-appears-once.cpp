//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //code
	    
	    //Binary Search
	    
	    if(N==1) return A[0];
	    
	    if(A[0]!=A[1]){
	        return A[0];
	    }
	    else if(A[N-1] !=A[N-2]){
	        return A[N-1];
	    }
	    
	    else{
	        int low=1;
	        int high=N-2;
	        
	        while(low<=high){
	            int mid=(low+high)/2;
	            
	            if(A[mid]!=A[mid-1] && A[mid]!=A[mid+1]){
	                return A[mid];
	            }
	            else {
	                //left or right??
	                if((mid %2 ==0 && A[mid]==A[mid+1] )  ||  mid%2==1 && A[mid]==A[mid-1]){
	                    //we are on the left
	                    low=mid+1;
	                }
	                else{
	                    //we are on the right
	                    high=mid-1;
	                }
	            }
	        }
	    }
	    
	    return -1;
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends