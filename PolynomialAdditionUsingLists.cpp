#include <iostream>
#include <conio.h>
using namespace std;
// 1. Node Template
class PNode
{
public:
	int coeff;
	int exp;
	PNode *next;
};

// 2. List Template
class PList
{
	PNode *head;

public:
	PList()
	{
		head = NULL;
	}
	void Insert(int c, int e);
	void Display();
	void Add(PList x, PList y);
	void Sub(PList x, PList y);
};

// 3. Functions
void PList::Insert(int c, int e)
{

	// a. Make a new node
	PNode *t = new PNode;
	t->coeff = c;
	t->exp = e;
	t->next = NULL;
	// 1st node insertion
	if (head == NULL)
	{
		head = t;
		return;
	}
	PNode *tmp = head;
	PNode *prev = NULL;
	while (tmp != NULL && tmp->exp > t->exp)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == head) // head node insertion
	{
		t->next = head;
		head = t;
	}
	else if (tmp == NULL) // tail node insertion
	{
		prev->next = t;
	}
	else // any other node insertion
	{
		prev->next = t;
		t->next = tmp;
	}
} // end of insert

void PList::Display()
{
	PNode *tmp = head;
	while (tmp)
	{
		if (tmp->coeff > 0)
		{
			cout << "+";
		}
		cout << tmp->coeff << "x^" << tmp->exp;
		tmp = tmp->next;
	}
} // End of Display

void PList::Add(PList x, PList y)
{
	head = NULL;
	PNode *P = x.head;
	PNode *Q = y.head;
	int c, e;
	while (P != NULL && Q != NULL)
	{
		if (P->exp == Q->exp)
		{
			c = P->coeff + Q->coeff;
			if (c != 0)
			{
				e = P->exp; // can be Q->exp also
				Insert(c, e);
			}
			P = P->next;
			Q = Q->next;
		} // When both values are same ||end of P==Q
		else if (P->exp > Q->exp)
		{
			c = P->coeff;
			e = P->exp;
			Insert(c, e);
			P = P->next;
		}	 // end of p>q
		else // p->exp <q->exp
		{
			c = Q->coeff;
			e = Q->exp;
			Insert(c, e);
			Q = Q->next;
		} // end of p<q
	}	  // P&&Q
	while (P != NULL)
	{
		c = P->coeff;
		e = P->exp;
		Insert(c, e);
		P = P->next;
	}
	while (Q != NULL)
	{
		c = Q->coeff;
		e = Q->exp;
		Insert(c, e);
		Q = Q->next;
	}
} // end of addition

void PList::Sub(PList x, PList y)
{
	head = NULL;
	PNode *P = x.head;
	PNode *Q = y.head;
	int c, e;
	while (P != NULL && Q != NULL)
	{
		if (P->exp == Q->exp)
		{
			c = P->coeff - Q->coeff;
			if (c != 0)
			{
				e = P->exp; // can be Q->exp also
				Insert(c, e);
			}
			P = P->next;
			Q = Q->next;
		} // When both values are same ||end of P==Q
		else if (P->exp > Q->exp)
		{
			c = P->coeff;
			e = P->exp;
			Insert(c, e);
			P = P->next;
		}	 // end of p>q
		else // p->exp <q->exp
		{
			c = Q->coeff;
			e = Q->exp;
			Insert(c, e);
			Q = Q->next;
		} // end of p<q
	}	  // P&&Q
	while (P != NULL)
	{
		c = P->coeff;
		e = P->exp;
		Insert(c, e);
		P = P->next;
	}
	while (Q != NULL)
	{
		c = Q->coeff;
		e = Q->exp;
		Insert(c, e);
		Q = Q->next;
	}
} // end of subtraction

// 4. Menu
int main()
{
	int choice;
	PList p1, p2, p3, p4;
	int co, ex;
	
	while (1)
	{
		system("cls");
		cout << "****OPERATIONS IN POLYNOMIALS****\n\n";
		cout << "1. Create 1st polynomial\n";
		cout << "2. Create 2nd polynomial\n";
		cout << "3. Display the 1st polynomial\n";
		cout << "4. Display the 2nd polynomial\n";
		cout << "5. Add the polynomial\n";
		cout << "6. Subtract the polynomial\n";
		cout << "7. Exit\n\n";
		
		cout << "Enter Your Choice: ";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			cout << "Enter the coefficient: ";
			cin >> co;
			cout << "Enter the exponent: ";
			cin >> ex;
			p1.Insert(co, ex);
			getch();
			break;

		case 2:
			cout << "Enter the coefficient: ";
			cin >> co;
			cout << "Enter the exponent: ";
			cin >> ex;
			p2.Insert(co, ex);
			getch();
			break;

		case 3:
			p1.Display();
			getch();
			break;

		case 4:
			p2.Display();
			getch();
			break;

		case 5:
			p3.Add(p1, p2);
			cout << "Sum of two polynomials is : ";
			p3.Display();
			getch();
			break;

		case 6:
			p4.Sub(p1, p2);
			cout << "Subtraction of two polynomials is: ";
			p4.Display();
			getch();
			break;

		case 7:
			exit(1);

		default:
			cout << "Incorrect Choice!";
			getch();
			
		} // end of switch
	}	  // end of while
} // end of main



