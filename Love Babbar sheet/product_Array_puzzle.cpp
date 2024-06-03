//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
    int countZero = 0;
    long long int product = 1;
    
    // Calculate product of all non-zero elements and count zeros
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            product *= nums[i];
        } else {
            countZero++;
        }
    }
    
    vector<long long int> p(n, 0); // Initialize the result array with zeros
    
    // If more than one zero, all elements in p are already zero
    if (countZero > 1) {
        return p;
    }
    
    // If exactly one zero, set the product only at the position of the zero
    if (countZero == 1) {
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                p[i] = product;
                break;
            }
        }
        return p;
    }
    
    // If no zeros, set the product except self for each position
    for (int i = 0; i < n; ++i) {
        p[i] = product / nums[i];
    }
    
    return p;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends