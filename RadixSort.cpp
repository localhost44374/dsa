	
#include <iostream>
using namespace std;
int main()
{
    int a[20], n, max, r, k, j, i;
    int passes = 0, pass_no, divisor = 1, b_count[10];
    int bucket[10][20];
    cout << "***Radix Sort***\n\n";
    cout << "Enter the size of Array:";
    cin >> n;
    cout << "Enter " << n << " elements in the Array\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    } // index increment
    // Radix Sort
    // 1. Identify the maximum number in the array
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    // 2. Count Digits in max
    while (max > 0)
    {
        passes++;
        max = max / 10;
    }
    // 3. Radix Sort Process
    for (pass_no = 1; pass_no <= passes; pass_no++)
    {
        for (k = 0; k < 10; k++)
        {
            b_count[k] = 0; // Initialize is_count to 0 to indicate that the bucket is empty
        }
        for (i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][b_count[r]] = a[i];
            b_count[r]++;
        }
        // collect bins
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < b_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor = divisor * 10;
    } // End of pass_no loop
    cout << "Sorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
} // end of main




