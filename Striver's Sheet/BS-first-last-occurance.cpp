//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        //O(LogN)
        
        //Binary Search
        
        long long f=first(v,x);
        long long l=last(v,x);
        
        pair<long long,long long>p;
        p.first=f;
        p.second=l;
        return p;
    }
    
    
    
    long long first(vector<long long> v, long long x){
        
        int low=0;
        int high=v.size()-1;
        long long ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(v[mid]==x){
                ans=mid;
                high=mid-1;
            }
            
            if(x > v[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
        
    }
    
    
    long long last(vector<long long> v, long long x){
        
        int low=0;
        int high=v.size()-1;
        long long ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(v[mid]==x ){
               ans= mid;
               low=mid+1;
            }
            
            if(x < v[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
    
    
    
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends