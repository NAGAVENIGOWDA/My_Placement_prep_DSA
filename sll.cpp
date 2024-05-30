#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int data;
    node * next;
};

node* createnode(int data){
    node * temp=new node;
    if(temp!=NULL){
        temp->data=data;
        temp->next=NULL;

    }
return temp;
}
 
void insertatrear(node* &head,int data){
    node * newNode=createnode(data);
    node * temp=head;

    if(head==NULL){
        head=newNode;
    }
    else{
       while(temp->next!=NULL){
         temp=temp->next;
       }
    temp->next=newNode;
    }
  
}
void insertionatFront(node* &head,int data){
    node* newNode=createnode(data);
    newNode->next=head;
    head=newNode;

}
bool search(node * head, int key) {
    node * temp = head;
   
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;  // Update the pointer to move through the list
    }
    return false;
}

void display(node * head){
 node * temp=head;
 while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
 }
 cout<<endl;
}

void deletionfront(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
    }
    node * temp=head;
    head=temp->next;
    delete temp;
}
void deletionrear(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    node* prev=NULL;
    node* cur=head;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    delete cur;



}
void deletionmid(node* &head,int data){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    node* prev=NULL;
    node* cur=head;
    while(cur->data!=data){
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    delete cur;
}

void reverse(node* &head){
    node* prev=NULL;
    node*cur=head;
    node*nxt;
    while(cur!=NULL){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
       
    }
    head=prev;
    

}

void evenafterodd(node* &head){
    node* odd=head;
    node*even=head->next;
    node*evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;


    }
    odd->next=evenstart;
}
int main(){
 
node * head=NULL;
int data,key;
int choice;
bool ans;
for(;;){
    cout<<"1.insert at front\n2.insert at end\n 3.deletion at front \n 4.deletion at end\n 5.search \n 6.display \n 7.exit \n 8.deletion at middle\n 9.reverse "<<endl;
    cout<<"enter a choice"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
    cout<<"enter a value"<<endl;
    cin>>data;
    insertionatFront(head,data);
        break;
    case 2:
    cout<<"enter a value"<<endl;
    cin>>data;
    insertatrear(head,data);
        break;
    case 3:
    deletionfront(head);
    break;
    case 4:
    deletionrear(head);
    break;

    case 5:
    cout<<"enter a key"<<endl;
    cin>>key;
     if(search(head,key)){
        cout<<"key found"<<endl;
     }
     else{
        cout<<"key not found"<<endl;
     }
    
      break;
    case 6:
     display(head);
     break;
     
     case 7:
      exit(0);
      break;
      case 8:
       cout<<"enter a value to delete"<<endl;
    cin>>data;
       deletionmid(head,data);
       break;
       case 9:
        reverse(head);
        break;
       case 10:
        evenafterodd(head);
        break;
    
    }

}


 
 
 
 
return 0 ;
}