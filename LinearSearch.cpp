
#include<iostream>
using namespace std;

int main()
{
	int num[20], key, i;
	int size;
	int flag = 0;
	
	
	cout << "*** Linear Search ***" << endl << endl;
	cout << "Enter the size of the array : ";
	cin >> size;
	cout << "Enter " << size << " elements " << endl << endl;
	
	for(i = 0; i < size; i++)
	{
		cout << "Enter value of index " << i << " : ";
		cin >> num[i];
	}
	cout << endl;
	
	cout << "Enter the key to search : ";
	cin >> key;
	
	// Linear Search
	
	for(i = 0; i < size; i++)
	{
		if(num[i] == key)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)
	{
		// key found 
		cout << "Key found at the index : " << i;
	} else 
	{
		// key not found
		cout << "Key is not present in the array";	
	}
	
	return 0;
}// End of main

