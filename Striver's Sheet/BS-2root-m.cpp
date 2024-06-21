//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        

        
        //BS
        
        int low=1;
        int high=x;
        
        while(low<=high){
            long long int  mid=(low+high)/2;
            
            long long int val=mid * mid;
            
            if(val==(long long int)(x)) return mid;
            
            if(val <(long long int)(x)){
                low=mid+1;
            }
            
            else{
                
                high=mid-1;
                
            }
        }
        
        return high; //need to return the floor of a number if sqroot not possible
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends