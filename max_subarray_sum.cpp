#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
 
int main(){

int n;

cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}

int mx=INT_MIN;


/*
for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum=sum+a[j];
        mx=max(mx,sum);
    }
    
}
*/

//above code O(N^2)

//KADENE'S ALGORITHM
//O(N)

int sum=0;
for(int i=0;i<n;i++){
    sum+=a[i];
    if(sum<0){
        sum=0;
    }
    mx=max(mx,sum);
}
 
cout<<mx;

return 0 ;
}