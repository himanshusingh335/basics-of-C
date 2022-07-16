#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node*next;
}*ptr,*temp;

struct node*head=NULL;

Node*createNode(int newData)
{
	ptr = new Node; //or ptr=malloc(sizeof(Node));
	ptr->data=NewData;
	ptr->next=null;
}

void insertatBegNode(Node*newptr)
{
	if (head==null)
	{
		head=newptr;
	}
	else
	{
		newptr->next=head;
		head=newptr;
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
	}
}

void insertInMiddle(Node*newptr, int insertafter)
{
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
		newptr->next=temp->next;
		temp->next=newptr;
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
		temp->next=null;
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
		temp=head;
		head=temp->next;
		free(temp);
	}
}

int main()
{
	return 0;
}
