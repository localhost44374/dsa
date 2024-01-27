#include <iostream>
#define SIZE 20
using namespace std;
// 1. Create the stack
class Stack
{
    char A[SIZE];
    int tos;

public:
    Stack()
    {
        tos = -1;
    }
    void Push(char x);
    char Pop();
    int Full();
    int Empty();
};
// 2. Functions
void Stack ::Push(char x)
{
    if (Full())
    {
        cout << "Stack Overflow!";
        return;
    }
    tos++;
    A[tos] = x;
}
char Stack::Pop()
{
    if (Empty())
    {
        cout << "Stack UnderFlow";
        return -1;
    }
    char tmp = A[tos];
    tos--;
    return tmp;
}
int Stack::Full()
{
    if (tos == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::Empty()
{
    if (tos == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char expr[20];
    char tmp;
    int i = 0, flag = 0;
    Stack s;
    cout << "***Balancing of Parenthesis Using A Stack***\n\n";
    cout << "Enter an expression: ";
    cin >> expr;
    while (expr[i] != '\0') //\0 is by default initialised when expression is created(it denotes end of string array)
    {
        if (expr[i] == '[' || expr[i] == '(' || expr[i] == '{')
        {
            s.Push(expr[i]);
        }
        if (expr[i] == ']' || expr[i] == ')' || expr[i] == '}')
        {
            if (s.Empty()) // when there is extra closed bracket
            {
                flag = 1;
                break;
            }
            tmp = s.Pop();
            if ((tmp == '[' && expr[i] == ']') ||
                (tmp == '(' && expr[i] == ')') ||
                (tmp == '{' && expr[i] == '}'))
            {
                i++;
                continue; // used to skip
            }             // end of matching bracketss
            else
            {
                flag = 1;
                break;
            } // brackets do not match
        }     // end of if close bracket
        i++;
    } // end of while
    if (s.Empty() && flag == 0)
    {
        cout << "Expression is Balanced!!";
    }
    else
    {
        cout << "Expression is not Balanced!";
    }
} // end of main

