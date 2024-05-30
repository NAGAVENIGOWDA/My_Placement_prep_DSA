#include<iostream>
using namespace std;
 
int isPrime(int i,int div){
     while(div<i){
        if(i%div==0){
            break;
        }
        else{
            div=div+1;
        }

     }
     return div;
}

int main(){
 
 int m,n;
 cin>>m>>n;

 for(int i=m;i<=n;i++){
    int div=2;
    div=isPrime(i,div);
     if(div==i){
        cout<<i<<endl;
     }
 }
 
 
 
return 0 ;
}