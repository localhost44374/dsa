#include <iostream>
using namespace std;
int main()
{
    int num[10], i;
    int first, last, mid;
    int target;
    int flag = 0, size;
    cout << "***Binary Search***" << endl;
    cout << "Enter the size of the array:";
    cin >> size;
    cout << "Enter " << size << " elements:" << endl;
    for (i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    cout << "Enter the Target Value:";
    cin >> target;
    // Binary Search
    first = 0;
    last = size - 1;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (target == num[mid]) // target element found at mid
        {
            flag = 1;
            break;
        }
        if (target < num[mid])
        {
            last = mid - 1;
        }
        else // control reaches here only if target > num[mid]
        {
            first = mid + 1;
        }
    } // end of while loop
    if (flag == 0)
    {
        cout << target << " is not found";
    }
    else
    {
        cout << target << " is found at index" << mid;
    }
} // End of main

