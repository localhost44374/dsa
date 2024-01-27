#include <iostream>
#include<conio.h>

using namespace std;

// 1. Node Template
class Node
{
	public:
		int data;
		Node *next;
};

// 2. List template
class List
{
	Node *head;
	
	public:
		List()
		{
			head = NULL;
		}
		
		void Insert(int x);
		void Del(int x);
		void Search(int x);
		void Length();
		void Display();
		
};

// 3. Functions 
void List :: Insert(int x)
{
	Node *t = new Node;
	t->data = x;
	t->next = NULL;
	
	// First node in the SLL
	
	if(head == NULL)
	{
		head = t;
	}
	else
	{
		// Traverse till last node and attach t
		Node *tmp = head;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		
		// tmp is at the last node, attach t after tmp
		tmp->next = t;
	}
}// end of Insert


void List :: Display(){     
	Node *tmp = head;
	while(tmp != NULL)
	{
		cout << tmp->data << "->";
	 	tmp = tmp->next;
	}
	 
	 cout << "NULL";
}

void List :: Length(){
	int counter;
	Node *tmp = head;
	while(tmp != NULL)
	{
		counter++;
	 	tmp = tmp->next;
	}
	 
	 cout << "LENGTH = " << counter;
}

void List :: Search(int x){
	bool found = false;
	
	Node *tmp = head;
	while(tmp != NULL)
	{
		if(tmp->data == x)
		{
			found = true;
		}
		
	 	tmp = tmp->next;
	}
	
	if(found == true)
	{
		cout << x << " is present";
	}
	else
	{
		cout << x << " is not present";
	}
}

void List :: Del(int x)
{
	// 1. Empty List - RETURN CONTROL
	if(head == NULL)
	{
		cout << "Empty SLL";
		return;
	}
	
	
	// 2. Search for 'x' (head is not NULL)
	Node *tmp = head;
	Node *prev = NULL;
	int flag  = 0;
	
	while(tmp != NULL)
	{
		if(tmp->data == x)
		{
			flag = 1;
			break;
		}
		prev  = tmp;
		tmp = tmp->next;
	}	
	
	// 3. Unsuccessful Search - RETURN CONTROL
	if(flag == 0)
	{
		cout << x << " not found";
		return;
	}
	
	// 4. Successful Search
	if(tmp == head && tmp->next == NULL)
	{
		head = NULL;
	}
	else if(tmp == head)
	{
		head = head->next;
	}
	else if(tmp->next == NULL)
	{
		prev->next = NULL;
	}
	else
	{
		prev->next = tmp->next;
	}
	
	cout << x << " deleted from the list" << endl;
	// 5. Delete memory occupied by 'x'
	delete tmp;
}// end of Del function



// 4. Main Menu
int main()
{
	List s;
	int ch, num;
	
	while(1)
	{
		system("cls");
		cout << " *** Singly Liniked List Menu ***\n\n";
		cout << "1. Insert an element in the SLL\n";
		cout << "2. Delete an element from the SLL\n";
		cout << "3. Search an element in the SLL\n";
		cout << "4. Length of the SLL\n";
		cout << "5. Display the SLL\n";
		cout << "6.Exit\n";
		
		cout << "Enter your choice : ";
		cin >> ch;		
		
		switch(ch)
		{
			case 1:
					cout << "Enter an element: ";
					cin >> num;
					s.Insert(num);
					getch();
				
				break;
				
			case 2:
					cout << "Enter an element : ";
					cin >> num;
					s.Del(num);
					getch();
				
				break;
				
			case 3:
					int element;
					cout << "Enter element to search : ";
					cin >> element;
					s.Search(element);
					getch();
				
				break;
				
			case 4:
					s.Length();
					getch();
				
				break;
				
			case 5:
					s.Display();                  
					getch();
				
				break;
							
			case 6:
					exit(1);		
				break;
				
			default:
					cout << "Incorrect choice!";
				
		}// end of switch
	} // end of while-loop
} // end of main


