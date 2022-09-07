#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
} * ptr, *temp;

Node *top = NULL;

void push(int d)
{
    ptr = new Node;
    ptr->data = d;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack underflow";
    }
    else
    {
        cout << top->data << endl;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    peek();
    pop();
    peek();
    return 0;
}