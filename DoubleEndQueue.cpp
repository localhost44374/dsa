#include<iostream>
#include<conio.h>
using namespace std;

class DQNode
{
	public:
		int data;
		DQNode *right;
		DQNode *left;
};


class DQueue
{
	DQNode *front;
	DQNode *rear;
	
	public:
		DQueue()
		{
			front = NULL;
			rear = NULL;
		}
		
		void EnqueueFront(int x);
		void EnqueueRear(int x);
		void DqueueFront();
		void DqueueRear();
		void PeekFront();
		void PeekRear();
		void Display();
};

void DQueue:: EnqueueFront(int x)\
{
	DQNode *t = new DQNode;
	t->data  = x;
	t->right = NULL;
	t->left = NULL;
	
	if(front == NULL)
	{
		front = t;
		rear = t;
	}
	else
	{
		t->right = front;
		front->left = t;
		front = t;
	}
}

void DQueue::EnqueueRear(int x)
{
	DQNode *t = new DQNode;
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	
	if(front == NULL)
	{
		front = t;
		rear = t;
	}
	else
	{
		rear->right = t;
		t->left = rear;
		rear = t;
	}
}
void DQueue::DqueueFront()
{
	if(front == NULL)
	{
		cout << "Queue Underflow!" << endl;
		return;
	}
	
	DQNode *tmp = front;
	
	if(front == rear)
	{
		front == NULL;
		rear = NULL;
	}
	else
	{
		front = front->right;
		front ->left = NULL;
	}	
}

void DQueue::DqueueRear()
{
	if(front == NULL)
	{
		cout << "Queue Underflow" << endl;\
		return;
	}
	
	DQNode *tmp = rear;
	
	if(front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		rear = rear->left;
		rear->right = NULL;
	}
	
	cout << "Element removed : " << tmp->data <<endl;
	delete tmp;
}

void DQueue::PeekFront(){
}
void DQueue::PeekRear(){
}

void DQueue::Display()
{
	if(front==NULL)
	{
		cout << "Queue Underflow!" << endl;
		return;	
	} 	
	
	DQNode *tmp = front;
	
	while(tmp != NULL)
	{
		cout << "Data: " << tmp->data << endl;
		tmp = tmp->right;
}
}
int main()
{
 	int ch,num,pr;
 	DQueue q;
 	
 	while(1)
 	{
 		system("cls");
 		cout<<"*** Double Ended Queue Menu ***\n\n";
 		cout<<"1.Enqueue front element\n";
 		cout<<"2.Enqueue rear element\n";
		cout<<"3.Dequeue front element\n";
 		cout<<"4.Dequeue rear element\n";
 		cout<<"5.Peak front\n";
 		cout<<"6.Peak rear\n";
 		cout<<"7.Display the queue\n";
 		cout<<"8.Exit\n\n";
 		
 		cout<< "Enter your choice: ";
 		cin>>ch;
 		
 		switch(ch)
 		{
 			case 1:
 				cout<<"Enter front element : ";
 				cin>>num;
 				q.EnqueueFront(num);
 				getch();
 				break;
 				
 			case 2:
			 	cout<<"Enter rear element : ";
 				cin>>num;
 				q.EnqueueRear(num);
			 	getch();
			 	break;
			 	
			case 3:
 				q.DqueueFront();
 				getch();
 				break;
 				
 			case 4:
 				q.DqueueRear();
			 	getch();
			 	break;
			
			case 5:
				q.PeekFront();
				getch();
				break;
				
			case 6:
				q.PeekRear();
				
				getch();
				break;
				
			case 7:
				q.Display();
				getch();
				break;
				
			case 8:
				exit(1);
			
			default:
				cout<<"Invalid";			 	
		}
	}
}


