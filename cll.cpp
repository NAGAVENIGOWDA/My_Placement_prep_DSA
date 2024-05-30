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
        newNode->next=head;
    }
    else{
       while(temp->next!=head){
         temp=temp->next;
       }
    temp->next=newNode;
    newNode->next=head;
    }
  
}
void insertionatFront(node* &head,int data){
    node* newNode=createnode(data);
    if(head==NULL){
        head=newNode;
        newNode->next=head;
    }
    
    node * temp=head;
    newNode->next=head;
    while(temp->next!=head){
         temp=temp->next;
       }
    temp->next=newNode;
    head=newNode;

}
bool search(node * head, int key) {
    node * temp = head;
   
    while (temp != head) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;  // Update the pointer to move through the list
    }
    return false;
}

void display(node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deletionfront(node* &head){
    node * temp=head;
    node *toDelelte=head;
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
    }
   while(temp->next!=head){
         temp=temp->next;
       }
    temp->next=head->next;
    head=toDelelte->next;
    delete toDelelte;
}
void deletionrear(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        return;
    }
    node* prev=NULL;
    node* cur=head;
    while(cur->next!=head){
        prev=cur;
        cur=cur->next;
    }
    prev->next=head;
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

void reverse(node*& head) {
    if (head == NULL || head->next == head) {
        return;
    }
    node * temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* prev = temp;
    node* cur = head;
    node* nxt;
    do {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    } while (cur != head);
    head = prev;
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

    
    }

}


 
 
 
 
return 0 ;
}