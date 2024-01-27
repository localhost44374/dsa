#include <iostream>
#include <conio.h>
#define MAX 10
#define EMPTY -1
using namespace std;
// 1. Node TEmplate-Not Required
// 2. Array BasedTemplate for Hash Table
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
// 3. Functions
void Hash::Insert(int key)
{
    // HASH FUNCTION
    int addr = key % MAX; // modulo division Hash fuction
    int oaddr = addr;
    if (h[addr] == EMPTY) // check Address is available???
    {
        h[addr] = key;
        cout << "Key is inserted at address: " << addr << endl;
    }
    else
    {
        // Collision
        do
        {
            addr = (addr + 1) % MAX;
            if (addr == oaddr)
            {
                cout << "Table is full!!!!!!!";
                return;
            }
        } while (h[addr] != EMPTY);
        h[addr] = key;
        cout << key << " is inserted at address " << addr << endl;
    }
} // end of insert
void Hash::Display()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        cout << "h[" << i << "] = ";
        if (h[i] == EMPTY)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << h[i] << endl;
        }
    }
} // end of display
void Hash::Search(int skey)
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
            cout << "Key " << skey << " is not found " << endl;
        }
    }
}
// 4. Menu
int main()
{
    int ch, num;
    Hash h;
    while (1)
    {
        system("cls");
        cout << "***Modulo division- Hashing***\n\n";
        cout << "1. Insert A Key\n";
        cout << "2. Display\n";
        cout << "3. Search For A Key\n";
        cout << "4. Exit\n\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter a key: ";
            cin >> num;
            h.Insert(num);
            getch();
            break;
        case 2:
            h.Display();
            getch();
            break;
        case 3:
            cout << "Enter a value to search: ";
            cin >> num;
            h.Search(num);
            getch();
            break;
        case 4:
            exit(1);
        default:
            cout << "Incorrect choice!!!";
            getch();
        }
    }
}


