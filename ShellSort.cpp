#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int A[20] , n;
	int i , gap, extractItem, pos;
	
	cout << "*** shell sort***\n\n";
	cout << "Enter the size of array: ";
	cin >> n;
	
	cout << "Enter " << n << "elements in the array: " << endl;
	for(i=0 ; i<n ; i++)
	{
		cin >> A[i];
	}
	
	//shell sort
	gap = floor(n/2);
	
	while (gap>0)
	{
		for(i=0 ; i<n-gap ; i++)
		{
			extractItem = A[i+gap];
			pos =i+gap;
			
			while((pos-gap)>=0 && extractItem <A[pos-gap])
			{
				A[pos] = A[pos-gap];
				pos = pos - gap;
			}
			
			A[pos] = extractItem;
		}//end of for i
		gap = floor(gap/2);
	}//end of while gap
	cout << "sorted array: ";
	for(i=0 ;i<n; i++)
	{
		cout << A[i]<<" ";
	}
	
}//end of main

