#include <iostream>
using namespace std;
int main()
{
    int a[20], n;
    int i, j, loc, tmp;
    int min;
    cout << "*** Selection Sort***" << endl
         << endl;
    cout << "Enter the Size Of The Array: ";
    cin >> n;
    cout << "Enter " << n << " values in the array: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Selection Sort
    for (i = 0; i < n; i++)
    {
        min = a[i]; // assume min value is first value in array
        loc = i;
        for (j = i + 1; j < n; j++) // check through array for a smaller value than min
        {
            if (a[j] < min)
            {
                min = a[j];
                loc = j;
            }
        } // end of for j loop
        // For this iteration, you have identified the min and its loc
        tmp = a[i];
        a[i] = a[loc];
        a[loc] = tmp;
    } // end of for i loop
    cout << "Sorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
} // End of Main

