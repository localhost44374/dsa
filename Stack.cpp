#include<iostream>
#include<conio.h>

#define SIZE 5

using namespace std;

// 1. Node template is not required as it is array-based

// 2. Array-Based Template

class AStack
{
	int A[SIZE];
	int tos;
	
	public:
			AStack()
			{
				tos = -1;
			}
			
			void push(int x);
			void pop();
			void peek();
			void display();
			bool full();
			bool empty();
};

void AStack::push(int x)
{
	if(full())
	{
		cout << "Stack Overflow!";
		return;
	}
	
	// inserting the element in the stack
	tos++;
	A[tos] = x;
}

void AStack::pop()
{
	if(empty())
	{
		cout << "Stack Underflow";
		return;
	}
	
	int tmp = A[tos];
	tos--;
	cout << "Element popped is : " << tmp;
}

void AStack::peek()
{
	if(empty())
	{
		cout << "Stack Underflow!";
		return;	
	}
	
	cout << "Element at the TOS is : " << A[tos];
	
}

void AStack::display()
{
	if(empty())
	{
		cout << "Stack Underflow!";
		return;	
	}
	
	int i;
	for(i = tos;  i >= 0; i--)
	{
		cout << A[i] << " ";
	}
		
}

bool AStack::full()
{
	if(tos == SIZE -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool AStack::empty()
{
	if(tos == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{	
	AStack s;
	int num, ch;
	
	while(1)
	{
		
		system("cls");
		
		cout << "*** Array-Based Stack ***\n\n";
		
		cout << "1. Push an element on the stack\n";
		cout << "2. Pop an element from the stack\n";
		cout << "3. Peek at the stack\n";
		cout << "4. Display the stack\n";
		cout << "5. Exit\n";
		
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

