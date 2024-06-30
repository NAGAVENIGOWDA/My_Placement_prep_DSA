//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  /*There are several cards arranged in a row, and each has an associated number of points.
   The points are given in the integer array cardPoints of size N.
In one step, you can take one card from beginning or from the end of the row. You have to take exactly
 k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints, and its size N and the integer k, return the maximum score
 you can obtain.*/



    long long maxScore(vector<int> &cp, int N, int k) {
        // code here
        
        //first k cards from front 
        
       
        long long sum=0;
        
        long long  lsum=0, rsum=0;
        for(int i=0;i<k;i++){
            
            lsum+=cp[i];
        }
        
       
       int last=N-1;
        long long ans=lsum;
        
        for(int i=k-1 ;i>=0;i--){
            
            lsum=lsum-cp[i];
            rsum=rsum+cp[last];
            last--;
            
            sum=lsum+rsum;
            
            ans=max(ans,sum);
            
        }
        
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends