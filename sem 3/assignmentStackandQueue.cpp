#include<iostream>

using namespace std;

struct QNode { 
    char phoneNo[10];
    char name[10];
    char date[10];
    char time[10];
    QNode* next=NULL; 
}*front,*rear,*temp;

  
 
void enterDetails()
{
 	cout<<"Enter name: ";
 	cin>>temp->name;
 	cout<<"Enter phone no: ";
 	cin>>temp->phoneNo;
 	cout<<"time of call (format: hh:mm): ";
 	cin>>temp->time;
 	cout<<"Enter date(format: dd:mm:yy) ";
 	cin>>temp->date;	
}

void displayList()
{
	temp=front;
	while(temp!=NULL)
	{
		cout<<temp->name<<" "<<temp->phoneNo<<" "<<temp->time<<" "<<temp->date<<"\n";
		temp=temp->next;
	}
}

int countDetails()
{
	int count=0;
	temp=front;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
  
    void enQueue()
    { 
  
        // Create a new LL node 
        temp = new QNode; 
		enterDetails();
        // If queue is empty, then 
        // new node is front and rear both 
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
  
        // Add the new node at 
        // the end of queue and change rear 
        rear->next = temp; 
        rear = temp; 
    } 
  
    void deQueue() 
    { 
        // If queue is empty, return NULL. 
        if (front == NULL) 
            return; 
  
        // Store previous front and 
        // move front one node ahead 
        temp = front; 
        front = front->next; 
  
        // If front becomes NULL, then 
        // change rear also as NULL 
        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    } 

int main()
{
	int n;
	while(n!=3)
	{
		cout<<"\n\n";
		cout<<"1) add item to call log"<<"\n";
		cout<<"2) view call log"<<"\n";
		cout<<"3)exit"<<"\n";
		cout<<"Choose an option: ";
		cin>>n;
		cout<<"\n\n";
	
		switch(n)
		{
			case 1:
				enQueue();
				break;
			
			case 2:
				while(countDetails()>3)
				{
					deQueue();
				}
				displayList();
				break;
		}
	}

	return 0;
}
