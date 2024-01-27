#include<iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;

#define SIZE 20

class Stack
{
	float A[SIZE];
	int tos;
	
	public :
		Stack()
		{
			tos = -1;
		}
		
		void push(float x);
		float pop();
		bool full();
		bool empty();
};

void Stack::push(float x)
{
	if(full())
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	
	tos++;
	A[tos] = x;
}

float Stack::pop()
{
	if(empty())
	{
		cout << "Stack Underflow" << endl;
		return -1;
	}
	
	float tmp = A[tos];
	tos--;
	return tmp;
}

bool Stack::full()
{
	return(tos == SIZE - 1? true : false);
}

bool Stack::empty()
{
	return(tos == -1 ? true : false);
}


