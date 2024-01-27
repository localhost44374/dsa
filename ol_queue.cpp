#include<iostream>
#include<conio.h>
using namespace std;

#define SIZE 4

// 1. Node Template - NOT required
// 2. Array based template

class OQueue
{
	int A[SIZE];
	int front;
	int rear;
	
	public:
		OQueue()
		{
			front = -1;
			rear = -1;
		}
		
		void enqueue(int x);
		void dequeue();
		void peekFront();
		void peekRear();
		void display();
		bool full();
		bool empty();
};

// 3. Functions

bool OQueue::full()
{
	if(rear == SIZE -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void OQueue::enqueue(int x)
{
	if(full())
	{
		cout << "\nQueue Overflow\n";
		return;
	}
	
	rear++;
	A[rear] = x;
	
	// special case : first element in the queue
	if(front == -1)
	{
		front++;
	}
}// end of enqueue

void OQueue::dequeue()
{
	int tmp;
	if(empty())
	{
		cout << "Queue Underflow" << endl;
		return;
	}
	
	tmp = A[front];
	if(front == rear)
	{
		// single element deletion
		front = -1;
		rear = -1;
	}
	else
	{
		front++;	
	}
	
	cout << "Element dequeued is " << tmp << endl;
	
	
	
}// end of dequeue

void OQueue::peekFront()
{
	if(empty())
	{
		cout << "Queue Empty" << endl;
		return;
	}
	cout << "Element at the front : " << A[front] <<endl;
}

void OQueue::peekRear()
{
	if(empty())
	{
		cout << "Queue Empty" << endl;
		return;
	}
	cout << "Element at the rear : " << A[rear] <<endl;
}

void OQueue::display()
{
	if(empty())
	{
		cout << "Queue Empty" << endl;
		return;
	}
	
	int i;
	for(i = front; i <= rear; i++)
	{
		cout << A[i] << " | ";
	}
}



bool OQueue::empty()
{
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// 4. Menu

int main()
{
	int choice,num;
	OQueue q;
	
	while(1)
	{
		system("cls");
		cout << "*** Ordinary Queue ***\n\n";
		cout << "1.Enqueue an element" << endl;
		cout << "2.Dequeue an element" << endl;
		cout << "3.Peek front" << endl;
		cout << "4.Peek rear" << endl;
		cout << "5.Display elements" << endl;
		cout << "6.Exit"<< endl;
		
		cout << "Enter your choice : ";
		cin >> choice;
		
		
		switch(choice)
		{
			case 1:
				cout << "Enter element : ";
				cin >> num;
				q.enqueue(num);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.peekFront();
				getch();
				break;
			case 4:
				q.peekFront();
				getch();
				break;
			case 5:
				q.display();
				getch();
				break;
			case 6:
				exit(1);
			default:
				cout << "Invalid";
		}// end of switch
	}// end of while-loop
	
	return 0;
}


