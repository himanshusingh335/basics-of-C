#include<iostream>

using namespace std;

struct Node{
	int data;
	Node*next;
}*start,*ptr,*save,*tmp;

Node*newNode(int n)
{
	ptr= new Node;
	ptr->data=n;
	ptr->next=NULL;
	return ptr;
}
void insertBeg(Node*np)
{
	if(start==NULL)
	{
		start=np;
	}
	else
	{
		save=start;
		start=np;
		np->next=save;
	}
}

void getcount(Node*t){
	int counteven=0, countodd=0, sumeven=0, sumodd=0;
	while(t!=NULL){
		if(t->data%2==0){
		counteven++;
		sumeven=sumeven + t->data;
		}
		else
		{
			countodd++;
			sumodd=sumodd + t->data;
			}	
		t=t->next;
	}
	cout<<"number of odd numbers is: "<<countodd<<"\n";
	cout<<"number of even numbers is: "<<counteven<<"\n";
	cout<<"sum of even numbers is: "<<sumeven<<"\n";
	cout<<"sum of odd numbers is: "<<sumodd<<"\n";

}

int main()
{
		start=NULL;
		insertBeg(newNode(1));
		insertBeg(newNode(2));
		insertBeg(newNode(3));
		insertBeg(newNode(4));
		getcount(start);
}
