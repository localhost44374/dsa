#include <iostream>
#include <conio.h>

#define MAX 20

using namespace std;

// Node Template - NOT REQUIRED

// Array Based Template for Min Heap

class Heap
{
	int arr[MAX];
	int n;

public:
	Heap()
	{
		int i;
		for (i = 0; i < MAX; i++)
		{
			arr[i] = 0;
		}
		n = 0;
	}

	void CreateHeap();
	void BuildHeap();
	void InsertHeap(int x);
	void DeleteHeap();
	void Display();
	void reheapUp(int i);
	void reheapDown(int pos);
};

// Functions
void Heap ::CreateHeap()
{
	int i;

	cout << "Enter the number of elements in the heap: ";
	cin >> n; // n declared in Heap class

	cout << "Enter the elements:\n";

	for (i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	BuildHeap();
}

void Heap ::BuildHeap()
{
	int i;

	for (i = (n / 2) - 1; i >= 0; i--)
	{
		reheapDown(i);
	}
}

void Heap ::reheapDown(int pos)
{
	int i, val;
	val = arr[pos]; // Element to be floated down

	while (pos <= (n / 2) - 1) // Till last leaf position
	{
		i = (2 * pos) + 1; // Left child index

		// Find the smaller of left and right child
		if (arr[i] > arr[i + 1] && arr[i + 1] != 0)
		{
			i++; // maintain smaller child in i
		}

		// Compare val with smaller child
		if (val < arr[i])
		{
			break; // Nothing to be done
		}

		arr[pos] = arr[i]; // Shift smaller child upwards

		// Repeat the same steps on the ith index
		pos = i;
	} // end of while

	// Copy val to its correct location
	arr[pos] = val;
}

void Heap ::Display()
{
	if (n == 0)
	{
		cout << "Heap is Empty!";
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void Heap ::DeleteHeap()
{
	// Empty Heap
	if (n == 0)
	{
		cout << "Heap is Empty!";
		return;
	}

	int tmp = arr[0]; // Copy the root element to tmp

	arr[0] = arr[n - 1]; // Copy last element to root;
	// arr[n - 1] = 0;		 // Update last element to NIL
	n--; // Decrement total number of elements

	reheapDown(0); // reheapDown on your root;

	cout << "Element Deleted: " << tmp << endl;
}

void Heap ::InsertHeap(int x)
{
	arr[n] = x; // Insert x at the nth position
	n++;		// Increment total number of elements

	reheapUp(n - 1);
}

void Heap ::reheapUp(int i)
{
	int val = arr[i]; // Copy element to be floated up in val

	while (i > 0 && arr[(i - 1) / 2] > val)
	{
		arr[i] = arr[(i - 1) / 2];
		i = (i - 1) / 2; // Repeat the same steps on the parent index
	}					 // end of while

	arr[i] = val; // Copy val to its final position
}

// Menu
int main()
{
	int ch, num;
	Heap h;

	while (1)
	{
		system("cls");
		cout << "*** Min - Heap ***\n\n";
		cout << "1. Create Heap\n";
		cout << "2. Insert an element in the Heap\n";
		cout << "3. Delete Heap\n";
		cout << "4. Display the Heap\n";
		cout << "5. Exit\n\n";

		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			h.CreateHeap();
			getch();
			break;
		case 2:
			cout << "Insert an element in the heap: ";
			cin >> num;
			h.InsertHeap(num);
			getch();
			break;
		case 3:
			h.DeleteHeap();
			getch();
			break;
		case 4:
			h.Display();
			getch();
			break;
		case 5:
			exit(1);
		default:
			cout << "Incorrect Choice!";
			getch();
		}
	}
}

