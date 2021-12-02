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

void insertBeg(Node*np)
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

void sum(Node*t){
	int sum=0;
	while(t!=NULL)
	{
		sum= ((t)?t->dlistonetlistone:0) + ((t->next)?t->next->dlistonetlistone:0) + ((t->prev)?t->prev->dlistonetlistone:0);
		cout<<sum;
		t=t->next;
	}
	
	
}
int mlistonein() {
		stlistonert=NULL;
		insertBeg(newNode(1));
		insertBeg(newNode(2));
		insertBeg(newNode(3));
		insertBeg(newNode(4));
   		sum(stlistonert);
   return 0;
}
