//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *evenStart=NULL;
        Node *evenEnd=NULL;
        Node *oddStart=NULL;
        Node *oddEnd=NULL;
        
        Node *cur=head;
        while(cur!=NULL){
            if(cur->data % 2 ==0){
                if(evenStart==NULL){
                    evenStart=cur;
                    evenEnd=cur;
                }
                
                else{
                    evenEnd->next=cur;
                    evenEnd=cur;
                }
            }
            
            else{
                if(oddStart==NULL){
                    oddStart=cur;
                    oddEnd=cur;
                }
                
                else{
                    oddEnd->next=cur;
                    oddEnd=cur;
                }
            }
            
            cur=cur->next;
        }
        
        if(oddStart==NULL || evenStart==NULL){
            return head;
        }
     
        
        evenEnd->next=oddStart;
        oddEnd->next=NULL;
        head=evenStart;
        
        return head;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends