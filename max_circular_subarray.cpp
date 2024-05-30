#include<iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
 
 
int main(){
 
int max_circular_subarray_sum;
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
 
//total sum of the array
int total_sum=0;
for(int i=0;i<n;i++){
    total_sum+=a[i];
     a[i]=-a[i]; //changing sign
}


//to apply kadens 
int sum=0;
int mx=INT_MIN;

for(int i=0;i<n;i++){
    sum+=a[i];
    if(sum<0){
        sum=0;
    }
    mx=max(mx,sum);
}

mx=-mx;
max_circular_subarray_sum=total_sum-mx;

cout<<max_circular_subarray_sum;
 
 
return 0 ;
}