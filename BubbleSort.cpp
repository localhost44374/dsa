#include<iostream>

using namespace std;

int main()
{
	int A[20],n;
	int i,j,tmp;
	
	cout << "****Bubble Sort****" <<endl << endl;
	cout << "Enter the size of the array:";
	cin >> n;
	
	cout << "Enter " << n << " elements in the array: " << endl;
	for(i=0 ; i<n; i++)
	{
		cin >> A[i];
	}
	
	//Bubble Sort
	for(i=0; i<n-1 ; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(A[i] > A[j])
			{
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}//end of for j loop
	}//end of for i loop
	
	cout << "Sorted Array: ";
	for(i=0 ; i<n ; i++)
	{
		cout << A[i] << " ";
	}
	
}//end of main

