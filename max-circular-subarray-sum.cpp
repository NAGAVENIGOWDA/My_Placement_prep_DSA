//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    
    int circularSubarraySum(int arr[], int num){
      
       
    int maxKadane = kadane(arr, num);

    // Step 2: Find the total sum of the array
    int totalSum = 0;
    for (int i = 0; i < num; i++) {
        totalSum += arr[i];
    }

    // Step 3: Invert the elements of the array
    for (int i = 0; i < num; i++) {
        arr[i] = -arr[i];
    }

    // Step 4: Find the maximum subarray sum of the inverted array using Kadane's algorithm
    int maxInvertedKadane = kadane(arr, num);

    // Step 5: The maximum circular subarray sum
    int maxCircular = totalSum + maxInvertedKadane;

    // Step 6: Handle edge case where all elements are negative
    if (maxCircular == 0) {
        return maxKadane;
    }

    // Return the maximum of the two cases
    return max(maxKadane, maxCircular);

        
    }
    
    
    
    
    int kadane(int arr[], int num) 
    
    
    {
        
        
        int maxSum = INT_MIN, currSum = 0;
        for (int i = 0; i < num; i++) 
        {
        currSum += arr[i];
        if (currSum > maxSum) {
            maxSum = currSum;
        }
        if (currSum < 0) {
            currSum = 0;
        }
    }
    
    
    return maxSum;
}


};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends