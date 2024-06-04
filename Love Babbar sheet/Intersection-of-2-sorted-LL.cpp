//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    if (n)
        while (n)
        {
            cout << n->data << " ";
            n = n->next;
        }
    else
        cout << " ";
}

// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        // code goes here.

        if (head1 == NULL || head2 == NULL)
            return NULL;

        Node *head3 = NULL;

        Node *tmp1 = head1;
        Node *tmp2 = head2;
        while (tmp1 != NULL && tmp2 != NULL)
        {
            if (tmp1->data == tmp2->data)
            {
                Node *tmp3 = new Node(tmp1->data);
                if (head3 == NULL)
                    head3 = tmp3;
                else
                {
                    Node *cur = head3;
                    while (cur->next != NULL)
                    {
                        cur = cur->next;
                    }
                    cur->next = tmp3;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            else if (tmp1->data < tmp2->data)
            {
                tmp1 = tmp1->next;
            }

            else
                tmp2 = tmp2->next;
        }

        return head3;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Solution ob;
        Node *result = ob.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends