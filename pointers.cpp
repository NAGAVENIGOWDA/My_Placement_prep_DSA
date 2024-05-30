#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

void swap(int *a ,int *b){
    cout<<"the value of *a is:"<<*a<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;

    
}
 
void increment(int *a){
    cout<<"the value of *a is:"<<*a<<endl;
    ++*a;
}
int main(){

int a=10;
int b=20;
int *ptr=&a;
cout<<*ptr<<endl;//10
cout<<ptr<<endl;//0x3f3fbff7a4
cout<<&ptr<<endl;//0x3f3fbff798
cout<<a<<endl;//10
cout<<&a<<endl;//0x3f3fbff7a4
int **q=&ptr;
cout<<**q<<endl; //10
cout<<*q<<endl; //0x3f3fbff7a4
cout<<q<<endl;//0x3f3fbff798
 
int *aptr=&a;
int *bptr=&b;


//pass by reference
swap(&a,&b);
//swap(aptr,bptr);
cout<<a<<' '<<b<<endl;
 
increment(&a);
cout<<a<<endl;
 
return 0 ;
}