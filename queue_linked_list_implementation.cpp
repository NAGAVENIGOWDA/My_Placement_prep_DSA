#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Queue
{
    int data;
    Queue *next;

} node;

node *createNode(int x)
{
    node *temp = new node;
    if (temp != NULL)
    {
        temp->data = x;
        temp->next = NULL;
    }
    return temp;
}

void enqueue(node *&front, node *&back, int data)
{
    node *newNode = createNode(data);
    if (front == NULL)
    {
        back = newNode;
        front = newNode;
    }
    else
    {
        back->next = newNode;
        back = back->next;
    }
}

void dequeue(node *&front, node *&back)
{
    if (front == NULL)
    {
        cout << "queue is empty" << endl;
        return;
    }
    else
    {
        front = front->next;
    }
}

void peek(node *front, node *back)
{
    if (front == NULL)
    {
        cout << "queue is empty" << endl;
        return;
    }
    cout << "the peek element is : " << front->data << endl;
}

void empty(node *front, node *back)
{
    if (front == NULL)
    {
        cout << "the queue is empty" << endl;
        return;
    }
    cout << "the queue is not empty" << endl;
}

void display(node *front, node *back)
{

    if (front == NULL)
    {
        cout << "no element to display" << endl;
        return;
    }
    node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{

    node *front = NULL;
    node *back = NULL;

    int x, choice;
    for (;;)
    {
        cout << "1.enqueue()\n2.dequeue()\n 3.peek()\n 4.empty()?? \n 5.display()\n 6.exit()" << endl;
        cout << "enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter data" << endl;
            cin >> x;
            enqueue(front, back, x);
            break;
        case 2:
            dequeue(front, back);
            break;
        case 3:
            peek(front, back);
            break;
        case 4:
            empty(front, back);
            break;
        case 5:
            display(front, back);
            break;
        case 6:
            exit(0);
            break;
        }
    }

    return 0;
}