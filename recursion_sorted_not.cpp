#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
bool sort(int arr[],int n){
    if(n==1){
        return true;
    }
    else{
        bool restarray=sort(arr+1,n-1);
        return (arr[0]<arr[1] && restarray );
    }
}
int main(){

int array[10]={1,2,3,4,5,6,7,8,9,10};

cout<<sort(array,10);
 
 
 
 
return 0 ;
}