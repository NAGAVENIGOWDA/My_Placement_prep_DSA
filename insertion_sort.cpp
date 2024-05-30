#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
 int n;
 int arr[100];
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 //insertion sort
 for(int i=1;i<n;i++){
    int current=arr[i];
    int j=i-1;
    while(arr[j]>current && j>=0){
        arr[j+1]=arr[j];
        j--;

    }
    arr[j+1]=current;
 }
 //print
 for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
 
 
 
return 0 ;
}