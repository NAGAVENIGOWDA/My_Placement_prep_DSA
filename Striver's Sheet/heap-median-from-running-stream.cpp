//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    
    //need 2 heaps
    //max heap -to store ele < median
    //min heap- to store ele > median
    
    priority_queue<int,vector<int>> s;
    priority_queue<int,vector<int>,greater<int>> t;
    
   
    
    void insertHeap(int &x)
    {
        //by default insert into maxheap
        
        
         if(s.empty() && t.empty()){
             s.push(x);
         }
         
         else if(s.size() > t.size()){
              if(x < s.top()){
                  
                  t.push(s.top());
                  s.pop();
                  s.push(x);
              }
              else{
                  t.push(x);
              }
              
              
         }
         
         else if (s.size()==t.size()) {
             
             if(x < s.top()){
                 s.push(x);
             }
        
             else{
                 t.push(x);
             }
         }
         
         else{
             
             if(x > t.top()){
                 s.push(t.top());
                 t.pop();
                 t.push(x);
                 
             }
             else{
                 s.push(x);
             }
         }
        
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        
        if(s.size()==t.size()){
            return (s.top() + t.top())/2.0;
        }
        
        else if(s.size() > t.size()){
            return (s.top());
        }
        
        else{
            return ( t.top());
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends