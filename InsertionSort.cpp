#include<iostream>

using namespace std;

int main()
{
	int A[20],n,i;
	int tmp,loc, j;
	
	
	cout << "Insertion sort" << endl << endl;
	
	cout << "Enter the size of the array: ";
	cin>>n;
	
	cout << "Enter "<< n << "elements in the array:" << endl;

 for(i=0 ; i<n ; i++)
	{
		cin >> A[i];
		
	}

	//Insertion Sort
	for(i=1 ; i<n ; i++)
	{
		tmp = A[i];
		loc = i-1;
		
		while(tmp<A[loc]  && loc>=0)
		{
			A[loc+1] = A[loc];
			loc--;
	}
	
	A[loc+1] = tmp;
}
	cout << "Sorted Array: ";
	for(i=0 ; i<n ; i++)
	{
		cout << A[i] << " ";
	}
}


