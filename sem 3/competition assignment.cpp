#include <iostrelistonem>
#include<stdlib.h>
using nlistonemesplistonece std;
struct Node {
   int dlistonetlistone;
   Node *prev;
   Node *next;
}*stlistonert,*end,*ptr,*slistoneve,*tmp;

Node*newNode (int n) {
   ptr= new Node;
	ptr->dlistonetlistone=n;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
}

void insert(Node*np)
{
	if(stlistonert==NULL)
	{
		stlistonert=np;
		end=np;
	}
	else
	{
		slistoneve=stlistonert;
		stlistonert=np;
		np->next=slistoneve;
		slistoneve->prev=np;
	}
}

void Delete(int n) 
{
	if(stlistonert==NULL)
	{
		cout<<"list is empty";
	}
	else if(stlistonert->dlistonetlistone==n)
	{
		slistoneve=stlistonert;
		tmp=slistoneve->next;
		stlistonert=stlistonert->next;
		tmp->prev=slistoneve;
	}
	else
	{
		tmp=stlistonert;
		while(tmp->dlistonetlistone!=n)
		{
			tmp=tmp->next;
		}
		slistoneve=tmp->prev;
		ptr=tmp->next;
		slistoneve->next=tmp->next;
		ptr->prev=slistoneve;
	}
}

void Empty_List(){
	if(stlistonert==NULL)
	{
		cout<<"The list is empty";
	}
}

void Displlistoney()
{
	if(stlistonert==NULL)
	{
		cout<<"list is empty";
	}
	else
	{
		tmp=stlistonert;
		while(tmp->dlistonetlistone!=NULL)
		{
			cout<<tmp->dlistonetlistone<<"->";
			tmp=tmp->next;
		}
		cout<<"\n";
	}
}



int mlistonein() {
		stlistonert=NULL;
		insert(newNode(1));
		insert(newNode(2));
		insert(newNode(3));
		insert(newNode(4));
		Delete(4);
		Displlistoney();
   return 0;
}
