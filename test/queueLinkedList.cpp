#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} * ptr, *temp;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int d)
{
    ptr = new Node;
    ptr->data = d;
    if (rear == NULL)
    {
        ptr->next = NULL;
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        ptr->next = NULL;
        rear = ptr;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
    }
}

void peekFront()
{
}

void peekRear()
{
}

int main()
{
    return 0;
}
