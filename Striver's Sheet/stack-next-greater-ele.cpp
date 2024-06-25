//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<long long> st;
        vector<long long> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack while the stack is not empty and
            // the top element is less than or equal to the current element
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            // If the stack is empty, there is no greater element on the right
            if (st.empty()) {
                ans[i] = -1;
            } else {
                // The top element of the stack is the next greater element
                ans[i] = st.top();
            }
            
            // Push the current element onto the stack
            st.push(arr[i]);
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends