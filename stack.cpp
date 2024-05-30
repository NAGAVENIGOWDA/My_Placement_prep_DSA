#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 100
 
struct Stack{
    int stack[n];
    int top;
};

void push(Stack *ptr,int ele){
    if(ptr->top==n-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    ptr->top++;
    ptr->stack[ptr->top]=ele;

}

int pop(Stack *ptr){
    int x;
    if(ptr->top==-1){
        return 9999;
    }
    x=ptr->stack[ptr->top];
    ptr->top--;
    return x;


}

void display(Stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        cout<<ptr->stack[i]<<" ";
    }
    cout<<endl;
}

void Top(Stack * ptr){
    if(ptr->top==-1){
        cout<<"No elements in the stack";
    }
    else{
        cout<<ptr->stack[ptr->top]<<endl;
    }
}
 

int main(){
 
Stack *ptr=NULL,s;
ptr=&s;
s.top=-1;
int ele,x,choice;
	while(1)
	{
		cout<<("1.Push\n 2.pop\n 3.display\n 4.peep\n")<<endl;
		cout<<("enter your choice\n")<<endl;
		cin>>(choice);
		switch(choice)
		{
			case 1:cout<<("enter the element\n");
					cin>>(ele);
					push(ptr,ele);
					break;
			case 2:x=pop(ptr);
			if(x==9999)
				cout<<("underflow condition\n")<<endl;
			else
				cout<<"Deleted element is"<<x<<endl;
			break;
			case 3:display(ptr);
			break;
			case 4:Top(ptr);
			break;
		
		}
	}
 
 
 
return 0 ;
}