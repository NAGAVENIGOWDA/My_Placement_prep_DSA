#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
int n;
cin>>n;
cin.ignore();
char arr[n+1];
cin.getline(arr,n+1);

int i=0;
int max_length=INT_MIN;
int curr_length=0;
int s=0,e=0;
while(1){
    if(arr[i]==' ' || arr[i]=='\0'){
         if(max_length<curr_length){
            max_length=curr_length;
            e=s;

         }
         curr_length=0;
         s=i+1;
    }
    else{
        curr_length++;
    }
    if(arr[i]=='\0'){
        break;
    }
    
    i++;
}
 

cout<<max_length;
 
 for(int i=0;i<max_length;i++){
    cout<<arr[i+e];
 }
 
return 0 ;
}