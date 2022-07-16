#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node*next;
	struct Node*prev;
}*ptr,*temp;

struct node*head=null;

Node*createNode(int newData)
{
	ptr = new Node; //or ptr=malloc(sizeof(Node));
	ptr->data=NewData;
	ptr->next=null;
	ptr->prev=null;
}

void insertatBegNode(Node*newptr)
{
	if (head==null)
	{
		head=newptr;
	}
	else
	{
		temp=newptr;
		temp->next=head;
		temp->prev=null;
		head->prev=temp;
		head=temp;
	}
}

void insertatEndNode(Node*newptr)
{
	if(head==null)
	{
		head=newptr;
	}
	else
	{
		temp=head;
		while(temp->next != null)
		{
			temp=temp->next;
		}
		temp->next=newptr;
		newptr->prev=temp;
	}
}

void insertInMiddle(Node*newptr, int insertafter)
{
	struct Node*temp2;
	if(head==null)
	{
		head=newptr;
	}
	else
	{
		temp=head;
		while(temp->data != insertafter)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		newptr->next=temp->next;
		temp->next=newptr;
		newptr->prev=temp;
		temp2->prev=newptr;
	}
}

void deleteatEnd()
{
	if(head==null)
	{
		cout<<"List is empty";
	}
	else
	{
		temp=head;
		while(temp->next != null)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=null;
		free(temp);
	}
}

void deleteMiddle(int notobedeleted)
{
		if(head==null)
	{
		cout<<"List is empty";
	}
	else
	{
		temp=head;
		while(temp->data != notobedeleted)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;
		free(temp);
	}
}

void deleteinBeginning()
{
	if(head==null)
	{
		cout<<"List is empty";
	}
	else
	{
		temp2=head->next;
		temp=head;
		head=temp->next;
		temp2->prev=head;
		temp=null;
	}
}

int main()
{
	return 0;
}
