#include <iostream>
#include <conio.h>
#define MAX 20
using namespace std;
// 1. Node Template-Not Required
// 2. Array Based Template for max-heap
class heap
{
	int arr[MAX];
	int n;

public:
	heap()
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
	void ReHeapUp(int i);
	void ReHeapDown(int pos);
};
// 3. Functions
void heap::CreateHeap()
{
	int i;
	cout << "Enter The number of elements in the heap: ";
	cin >> n; // n declared in heap class
	cout << "Enter The Elements: \n";
	for (i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
	}
	BuildHeap();
} // end of create heap
void heap::BuildHeap()
{
	int i;
	for (i = (n / 2) - 1; i >= 0; i--)
	{
		ReHeapDown(i);
	}
} // end of build heap
void heap::ReHeapDown(int pos)
{
	int i, val;
	val = arr[pos];			   // element to be floated down
	while (pos <= (n / 2) - 1) // Till last non-leaf position
	{
		i = (2 * pos) + 1; // left child position
		// Find the greater of left and right child
		if (arr[i] < arr[i + 1])
		{
			i++; // Maintain larger child in i
		}
		// Compare val with larger child
		if (val > arr[i])
		{
			break; // Nothing to be done
		}
		arr[pos] = arr[i]; // shift larger child upward
		// Repeat the same steps on the ith index
		pos = i;
	} // end of while
	// copy val to its correct position
	arr[pos] = val;
} // end of reheapdown
void heap::Display()
{
	if (n == 0)
	{
		cout << "Heap Empty!!!";
		return;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
} // end of display
void heap::DeleteHeap()
{
	// Empty??
	if (n == 0)
	{
		cout << "Empty Heap!!";
		return;
	}
	int tmp = arr[0];	 // copy the root of element
	arr[0] = arr[n - 1]; // copy last element to root
	arr[n - 1] = 0;		 // Update last element to NIL
	n--;				 // Decrement total number of elements
	ReHeapDown(0);
	cout << "Element Deleted is " << tmp << endl;
} // end of delete heap
void heap::InsertHeap(int x)
{
	arr[n] = x; // Insert x at the nth position
	n++;		// Decrement total number of elements
	ReHeapUp(n - 1);
} // end of insert
void heap::ReHeapUp(int i)
{
	int val = arr[i];						 // copy element to be floated in val
	while (i > 0 && arr[(i - 1) / 2] <= val) // arr[] represents parent node
	{
		arr[i] = arr[(i - 1) / 2];
		i = (i - 1) / 2; // rrepear the same steps on parent index
	}
	arr[i] = val;
} // end of reheapup
// 4. Menu Template
int main()
{
	int ch, num;
	heap h;
	while (1)
	{
		system("cls");
		cout << "***Max-Heap***\n\n";
		cout << "1. Create a Heap\n";
		cout << "2. Insert An Element\n";
		cout << "3. Delete An Element\n";
		cout << "4. Display the Heap\n";
		cout << "5. Exit\n\n";
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			h.CreateHeap();
			getch();
			break;
		case 2:
			cout << "Enter a value to insert: ";
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
			cout << "Incorrect choice";
			getch();
		}
	}
}


