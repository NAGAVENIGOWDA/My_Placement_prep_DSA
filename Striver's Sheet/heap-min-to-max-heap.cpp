//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
    
    //heapify
    
    for(int i=(N/2)-1 ;i>=0;i--){
        
        heapify(i,N,arr);
    }
    }
    
    
    void heapify(int i,int n,vector<int> &arr){
        
        int largest=i;
        
        int l=2*i+1;
        int r=2*i+2;
        
        
            
            if(l < n && arr[l] > arr[largest]){
                largest=l;
            }
            
            if(r<n && arr[r] > arr[largest] ){
                largest=r;
            }
            
            if(i!=largest){
                swap(arr[i],arr[largest]);
                heapify(largest,n,arr);
            }
        
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends