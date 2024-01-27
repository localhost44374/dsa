#include<iostream>
#include<conio.h>

using namespace std;

// 1. Node Template
class CNode
{
	public:
		int data;
		CNode *next;
};

// 2. List Template
class CList
{
	CNode *first;
	CNode *last;
	
	public:
		CList()
		{
			first = last = NULL;	
		}	
		
		void Insert(int x);
		void Del(int x);
		void Search(int x);
		void Length();
		void Display();
};

// 3. Function
void CList :: Insert(int x)
{
	// 
	CNode  *tmp =  new CNode;
	tmp->data = x;
	tmp->next = NULL;
	
	// check for 1st node in the CLL
	if(first == NULL)
	{
		first = tmp;
		last = tmp;
		last->next = first;
	}
	else
	{
		last->next = tmp;		// attach 'tmp' at the end of the list
		last = tmp;		// update last node
		last->next = first;		// Circularity	
	}
}//end of Insert()

void CList::Display()
{
	if(first == NULL)
	{
		cout << "Empty CLL";
		return;
	}
	
	CNode *tmp = first;
	
	do
	{
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	while(tmp != first);
	
	cout << "Back to first";
}

void CList :: Length()
{
	if(first == NULL)
	{
		cout << "Empty CLL";
		return;
	}
	
	CNode *tmp = first;
	int counter = 0;
	do
	{
		counter++;
		tmp = tmp->next;
	}
	while(tmp != first);
	
	cout << "Length of the CLL is " << counter;
}

void CList::Search(int x)
{
	if(first == NULL)
	{
		cout << "Empty CLL";
		return;
	}
	
	CNode *tmp = first;
	bool found = false;
	
	do
	{
		if(tmp->data == x)
		{
			found = true;
			break;
		}
		tmp = tmp->next;
	}
	while(tmp != first);
	
	if(found == true)
	{
		cout << "Element present in the list" << endl;
	}
	else
	{
		cout << "Element not present in the list" << endl;
	}
	
}

void CList :: Del(int x)
{
	
	// 1. is list empty?
	if(first == NULL)
	{
		cout << "CLL is empty!";	
		return;
	}
	
	// 2. search for the 'x'
	CNode *tmp = first;
	CNode *prev = NULL;
	
	bool found = false;
	
	do
	{
		if(tmp->data  == x)
		{
			found = true;
			break;
		}
		
		prev = tmp;
		tmp = tmp->next;
	}
	while(tmp != first);
	
	if(found == true)
	{
		cout << "Element present in the CLL" << endl;
	}
	else
	{
		cout << "Element is not present in the CLL" << endl;
	}
	
	// 3. unsuccessful search = RETURN CONTROL
	if(found == false)
	{
		cout << x << " is not present in the CLL";
		return;
	}
	
	// 4. successful search
	
	// 4a. Single Node Deletion
	if(tmp == first && tmp==last)
	{
		first = NULL;
		last = NULL;	
	}
	else if(tmp == first)	// 4b. First Node Deletion
	{
		first = first->next;
		last->next = first;		// updating the last node with the new first node
	}
	else if(tmp == last)	// 4c Last Node Deletion
	{
		last  = prev;
		last->next = first;		// Re-establishing circularity
	}
	else	// 4d. Any other not (Not first and Not last)
	{
		prev->next = tmp->next;		
	}
	// 5. Delete tmp
	
	cout << tmp->data << " deleted from the list" << endl;
	delete tmp;
}


// 4. Menu
int main()
{
	CList c;
	int num,ch;
	
	while(1)
	{
		system("cls");
		cout << "*** Circular Linked List ***\n\n";
		cout << "1. Insert a node in the CLL\n";
		cout << "2. Delete a node in the CLL\n";
		cout << "3. Search for a node in the CLL\n";
		cout << "4. Length of the CLL\n";
		cout << "5. Display the CLL\n";
		cout << "6. Exit\n";
		
		cout << "Enter your choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an element : ";
				cin >> num;
				c.Insert(num);
				getch();
				break;
			case 2:
				cout << "Enter an element : ";
				cin >> num;
				c.Del(num);
				getch();
				break;
			case 3:
				cout << "Enter the number : ";
				cin >> num;
				c.Search(num);
				getch();
				break;
			case 4:
				c.Length();
				getch();
				break;
			case 5:
				c.Display();
				getch();
				break;
			case 6:
				exit(1);
				getch();
				break;
			default:
				cout << "Invalid choice";
				getch();			
		}
	}
	
	return 0;
}

