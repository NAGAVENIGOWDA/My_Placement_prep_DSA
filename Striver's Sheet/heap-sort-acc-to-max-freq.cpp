#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    /*
    Given an array A[] of integers, sort the array according to frequency of elements. 
    That is elements that have higher frequency come first. If frequencies of two elements are same,
     then smaller number comes first.*/
    int t;
    cin>>t;
    while(t--){
    int n ;
    cin>>n;
    int nums[n];
    
    map<int,int> mp;
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
 
    
    
    for(int i =0;i<n;i++){
        mp[nums[i]]++;
    }
    
    priority_queue<pair<int,int>> pq;
    
    for(auto x : mp){
        pq.push({x.second,-1*x.first});
    }
    
    while(pq.size()){
        for(int i=0;i<pq.top().first;i++){
        cout<<pq.top().second*-1<<" ";
        }
        pq.pop();
    }
    cout<<endl;
        
    }
    
return 0;
}