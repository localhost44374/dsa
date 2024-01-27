#include<iostream>
#include<conio.h>

using namespace std;

class SNode
{
	public:
		int data;
		SNode *next;	
};

class LStack
{
	SNode *tos;
	public:
		LStack()
		{
			tos = NULL;	
		}	
		
		void push(int x);
		void pop();
		void peek();
		void display();
		bool empty();
};


// 3. Functions
void LStack::display()
{
	SNode *node = tos;
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;	
	}
}

bool LStack::empty()
{
	if(tos == NULL)
	{
		cout << "Stack Underflow!";
		return true;
	}
	else
	{
		return false;
	}
}

void LStack::peek()
{
	if(empty())
	{
		cout << "Stack Underflow";
		return;
	}
	
	cout << "Peek : " << tos->data;
}

void LStack::pop()
{
	if(tos == NULL)
	{
		cout << "Stack Underflow!";
		return;
	}
	
	SNode *tmp = tos;	// tmp pointer at TOS
	tos = tos->next;	// shift TOS to the next element
	cout << "Element popped is : " << tmp->data;
	delete tmp;
}

void LStack::push(int x)
{
	// 1. Make a new node
	SNode *t = new SNode;
	t->data = x;
	t->next = NULL;
	
	// First node in the Stack
	
	if(tos == NULL)
	{
		tos = t;
		return;
	}
	
	//Insert 't' at the head of the list
	t->next = tos;
	tos = t;	
}


// 4. Menu



int main()
{
	LStack s;
	int num, ch;
		
	while(1)
	{
		
		system("cls");
		
		cout << "*** List-Based Stack ***\n\n";
		
		cout << "1. Push an element on the stack\n";
		cout << "2. Pop an element from the stack\n";
		cout << "3. Peek at the stack\n";
		cout << "4. Display the stack\n";
		cout << "5. Exit\n";
		
		cout << "Enter choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an element : ";
				cin >> num;
				s.push(num);
				getch();
				break;
				
			case 2:
				s.pop();
				getch();
				break;
				
			case 3:
				s.peek();
				getch();
				break;
			
			case 4:
				s.display();
				getch();
				break;
			
			case 5:
				exit(1);
				getch();
				break;
				
			default:
				cout << "Invalid choice";		
		}			
	}
	return 0;
}


