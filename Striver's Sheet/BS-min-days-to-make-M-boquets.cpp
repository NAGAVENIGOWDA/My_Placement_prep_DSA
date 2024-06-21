//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
 bool isPossible(int day,vector<int> &bloomDay,int M,int K){
      int cnt=0;
      int bcnt=0;
      
      for(int i=0;i<bloomDay.size();i++){
          if(bloomDay[i]<=day){
              cnt++;
          }
          
          else{
              bcnt+=cnt/K;
              cnt=0;
          }
      }
      
      
    //last 
    bcnt+=cnt/K;
    
    return (bcnt>=M);
  }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      
      int low;
      int high;
      int ans=-1;
      
      for(int i=0;i<bloomDay.size();i++){
          low=min(bloomDay[i],low);
          high=max(bloomDay[i],high);
      }
      
      while(low<=high){
          int mid=(low+high)/2;
          
          if(isPossible(mid,bloomDay,M,K)){
              ans=mid;
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends