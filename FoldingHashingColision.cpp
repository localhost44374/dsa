#include <iostream>
#include <conio.h>

#define MAX 10
#define EMPTY -1

using namespace std;

// Node Template - NOT REQUIRED

// Array Based Template for Hash Table
class Hash
{
	int h[MAX];

public:
	Hash()
	{
		int i;
		for (i = 0; i < MAX; i++)
		{
			h[i] = EMPTY;
		}
	}

	void Insert(int key);
	void Display();
	void Search(int skey);
};

// Functions

// reverse function
int revNum(int num)
{
	int rev = 0;
	if (num < 10)
	{
		rev = num * 10;
		return rev;
	}
	while (num != 0)
	{
		int digit = num % 10;
		rev = rev * 10 + digit;
		num /= 10;
	}
	return rev;
}

void Hash ::Insert(int key)
{
	//	Hash Function
	int addr = (revNum((key / 10000) % 100) + ((key / 100) % 100) + revNum(key % 100)) % 100;

	int oaddr = addr;

	if (h[addr] == EMPTY) // addr is available
	{
		h[addr] = key;
		cout << key << " is inserted at address " << addr << endl;
	}
	else
	{
		//		Collision!!
		do
		{
			addr = (addr + 1) % MAX;
			if (addr == oaddr)
			{
				cout << "Hash Table is Full!";
				return;
			}
		} while (h[addr] != EMPTY);

		h[addr] = key;
		cout << key << " is inserted at address " << addr << endl;
	}
}

void Hash ::Display()
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		cout << "h[" << i << "] = ";
		if (h[i] == EMPTY)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << h[i] << endl;
		}
	}
}

void Hash ::Search(int skey)
{
	int saddr = skey % MAX;
	int oaddr = saddr;

	if (h[saddr] == skey)
	{
		cout << "Key " << skey << " is found at address " << saddr << endl;
	}
	else
	{
		do
		{
			saddr = (saddr + 1) % MAX;
			if (saddr == oaddr)
			{
				break;
			}
		} while (h[saddr] != skey);

		if (h[saddr] == skey)
		{
			cout << "Key " << skey << " is found at address " << saddr << endl;
		}
		else
		{
			cout << "Key " << skey << " is not found!" << endl;
		}
	}
}

// Menu
int main()
{
	int ch, num;
	Hash h;

	while (1)
	{
		system("cls");

		cout << "*** Hashing with Fold Boundary & Linear Probe ***\n\n";

		cout << "1. Insert a value in the Hash Table\n";
		cout << "2. Display the Hash Table\n";
		cout << "3. Search for a key in the Hash Table\n";
		cout << "4. Exit\n\n";

		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter key: ";
			cin >> num;
			h.Insert(num);
			getch();
			break;
		case 2:
			h.Display();
			getch();
			break;
		case 3:
			cout << "Enter key to Search: ";
			cin >> num;
			h.Search(num);
			getch();
			break;
		case 4:
			exit(1);
		default:
			cout << "Incorrect Choice!";
			getch();
		} // end of switch
	}	  // end of while
} // end of main


