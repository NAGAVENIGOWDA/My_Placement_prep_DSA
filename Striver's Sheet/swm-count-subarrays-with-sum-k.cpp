//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
   int subarraysWithAtmostK(vector<int>& a, int N, int t){
       
       int l=0;
       int r=0;
       int count=0;
       int sum=0;
       while(r<N){
           
           sum=sum+a[r];
           
           while(sum>t){
               sum=sum-a[l];
               l++;
           }
           
           if(sum<=t){
               count+=(r-l+1);
           }
           
           
          r++;
          
           
           
       }
       
     return count;
   }
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        
        //number of subrrays atmost k -number of subarrays atmost k-1
        
        
    return  subarraysWithAtmostK(arr,N,target)-subarraysWithAtmostK(arr,N,target-1);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends