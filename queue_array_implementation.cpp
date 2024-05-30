#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 100

struct Queue
{
       int arr[n];
       int front;
       int back;
};

void enqueue(Queue *ptr, int data)
{
       if (ptr->back == n - 1)
       {
              cout << "queue is overflow" << endl;
              return;
       }
       ptr->back++;
       ptr->arr[ptr->back] = data;
       if (ptr->front == -1)
       {
              ptr->front++;
       }
}

void dequeue(Queue *ptr)
{
       if (ptr->front == -1 || ptr->front > ptr->back)
       {
              cout << "queue is underflow" << endl;
              return;
       }
       cout << "deleted element is:" << ptr->front << endl;
       ptr->front++;
}

void peek(Queue *ptr)
{
       if (ptr->front == -1 || ptr->front > ptr->back)
       {
              cout << "queue is empty" << endl;
              return;
       }
       cout << "the peek element is :" << ptr->arr[ptr->front ]<< endl;
}

void empty(Queue *ptr)
{
       if (ptr->front == -1 || ptr->front > ptr->back)
       {
              cout << "the queue is empty" << endl;
       }
       else
       {
              cout << "the queue is not empty" << endl;
       }
}

void display(Queue *ptr)
{
       for (int i = ptr->front; i <= ptr->back; i++)
       {
              cout << ptr->arr[i] << " " ;
       }
       cout<<endl;
}

int main()
{

       Queue *ptr = NULL, q;
       q.front = -1;
       q.back = -1;
       ptr = &q;

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
                     enqueue(ptr, x);
                     break;
              case 2:
                     dequeue(ptr);
                     break;
              case 3:
                     peek(ptr);
                     break;
              case 4:
                     empty(ptr);
                     break;
              case 5:
                     display(ptr);
                     break;
              case 6:
                     exit(0);
                     break;
              }
       }

       return 0;
}