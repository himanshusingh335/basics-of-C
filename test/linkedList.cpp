#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * ptr, *temp;

struct Node *head = NULL;

Node *createNode(int newData)
{
    ptr = new Node; // or ptr=malloc(sizeof(Node));
    ptr->data = newData;
    ptr->next = NULL;
    return ptr;
}

void insertatBegNode(Node *newptr)
{
    if (head == NULL)
    {
        head = newptr;
    }
    else
    {
        newptr->next = head;
        head = newptr;
    }
}

void insertatEndNode(Node *newptr)
{
    if (head == NULL)
    {
        head = newptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newptr;
    }
}

void insertInMiddle(Node *newptr, int insertafter)
{
    if (head == NULL)
    {
        head = newptr;
    }
    else
    {
        temp = head;
        while (temp->data != insertafter)
        {
            temp = temp->next;
        }
        newptr->next = temp->next;
        temp->next = newptr;
    }
}

void deleteatEnd()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
    }
}

void deleteMiddle(int notobedeleted)
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        temp = head;
        while (temp->data != notobedeleted)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

void deleteinBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
}

int main()
{
    Node *n = createNode(1);
    Node *o = createNode(2);
    insertatEndNode(n);
    insertatEndNode(o);
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    return 0;
}
