#include<iostream>
#include<conio.h>

using namespace std;

//Node template
class DNode
{
	public:
		int data;
		DNode *right;
		DNode *left;	
};

//2. List Template
class DList
{
	DNode *head;
	DNode *tail;

	public:
		DList()
		{
			head = tail = NULL;
		}
		
		void Insert(int x);
		void Del(int x);
		void Search(int x);
		void Length();
		void Display();
};

//3. Functions
void DList::Insert(int x)
{
	// 1. Making a new node
	DNode *t = new DNode;
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	// 2. First node in DLL
	if(head == NULL)
	{
		head = t;
		tail = t;
	}
	else	// 3. Attach 't' to the tail of the DLL
	{
		tail->right = t;
		t->left = tail;
		tail = t;
	}
	
}	// end of Insert(x)


void DList::Del(int x)
{
	// 1. Check for empty DLL
	if(head == NULL)
	{
		cout << "Empty DLL" << endl;
		return;
	} 	
	
	// 2. search for the 'x'
	DNode *tmp = head;
	DNode *prev = NULL;
	
	bool found = false;
	
	cout << "DLL in forward\n";
	
	while(tmp != NULL)
	{
		if(tmp->data == x){
			found = true;
			break;
		}
		prev = tmp;
		tmp = tmp->right;
	}
	
	// 3. Unsuccessful search - RETURN CONTROL
	if(found == false)
	{
		cout << x << " is not found" << endl;
		return;
	}
	
	// 4. Successful Search
	
	// 4a. Single node deletion
	if(tmp == head && tmp == tail)
	{
		// here tail node = tail node
		head = tail = NULL;
	}
	// 4b. Head node deletion
	else if(tmp == head)
	{
		head = head->right;
		head->left = NULL;
	}
	// 4c. Tail node deletion
	else if(tmp == tail)
	{
		tail = prev;
		tail->right = NULL;
	}
	// 4d. Any other node deletion (NOT head and NOT tail)
	else
	{
		prev->right = tmp->right;
		(tmp->right)->left = prev->right;
	}
	delete tmp;
}	// end of Del(x) 


void DList::Search(int x)
{
	bool found = false;
	
	DNode *tmp = head;
	
	cout << "DLL in forward\n";
	while(tmp != NULL)
	{
		if(tmp->data == x){
			found = true;
			break;
		}
		
		tmp = tmp->right;
	}
	
	if(found == true)
	{
		cout << "Element is present in the DLL" << endl;
	}
	else 
	{
		cout << "Element is not present in the DLL" << endl;
	}
	
}	// end of Search(x)


void DList::Length()
{
	int length = 0;
	
	if(head == NULL)
	{
		cout << "DLL is empty" << endl;	
		return;
	} 
	
	DNode *tmp = head;
	
	cout << "DLL in forward\n";
	while(tmp != NULL)
	{
		length = length + 1;
		tmp = tmp->right;
	}
	
	cout << "Length => " << length << endl;	
}	// end of Length()

void DList::Display()
{
	DNode *tmp = head;
	
	cout << "\n[DLL in forward]\n";
	while(tmp != NULL)
	{
		cout << tmp->data << "<->";
		tmp = tmp->right;
	}
	cout << "NULL";


	cout << "\n[DLL in backward]\n";
	tmp = tail;
	while(tmp != NULL)
	{
		cout << tmp->data << "<->";
		tmp = tmp->left;
	}
	cout << "NULL";
} // end of Display()

//4. Menu
int main()
{
	DList d;
	int num,ch;
	
	while(1)
	{
		system("cls");
		cout << "*** Doubly Linked List ***\n\n";
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
				d.Insert(num);
				getch();
				break;
			case 2:
				cout << "Enter an element : ";
				cin >> num;
				d.Del(num);
				getch();
				break;
			case 3:
				cout << "Enter the number : ";
				cin >> num;
				d.Search(num);
				getch();
				break;
			case 4:
				d.Length();
				getch();
				break;
			case 5:
				d.Display();
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
	} // end of while-loop
	
	return 0;
}	// end of main()

