//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

    /*
    You are visiting a farm that has a single row of fruit trees arranged from left to right. 
    The trees are represented by an integer array fruits of size N, where fruits[i]  is the type of 
    fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must 
follow :

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree 
(including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        
        map<int,int>mp;
        
        int l=0;
        int r=0;
        int ans=0;
        
        while(r<N){
            
            mp[fruits[r]]++;
            
            if(mp.size() > 2){ //optimised while---if --O(2N)--O(N)
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            
        if(mp.size() <=2){
            ans=max(ans,r-l+1);
        }
        
        r++;
        }
        
    return  ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends