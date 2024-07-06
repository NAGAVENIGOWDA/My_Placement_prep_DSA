//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
     TNode* sortedListToBST(LNode *&head, int n) {
        if (n <= 0) return NULL;
        
        // Recursively construct the left subtree
        TNode* left = sortedListToBST(head, n / 2);
        
        // head now points to the middle node of the sorted list
        TNode* root = new TNode(head->data);
        root->left = left;
        
        // Move to the next element
        head = head->next;
        
        // Recursively construct the right subtree with the remaining nodes
        root->right = sortedListToBST(head, n - n / 2 - 1);
        
        return root;
    }
    
    int countNodes(LNode *head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    TNode* sortedListToBST(LNode *head) {
        int n = countNodes(head);
        return sortedListToBST(head, n);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends