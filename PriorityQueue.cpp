#include <iostream>
#include <conio.h>

using namespace std;

// 1.Node Template
class PNode
{
public:
    int data;
    int priority;
    PNode *next;
};

// 2.List based template for the queue
class PQueue
{
    PNode *front;
    PNode *rear;

public:
    PQueue()
    {
        front = rear = NULL;
    }
    void Enqueue(int x, int p);
    void Dequeue();
    void PeekFront();
    void PeekRear();
    void Display();
    int Empty();
};

// 3. Functions
int PQueue::Empty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PQueue::Enqueue(int x, int p)
{
    // 1. Make a new node(t)
    PNode *t = new PNode;
    t->data = x;
    t->priority = p;
    t->next = NULL;
    // 2. 1st node in the queue
    if (front == NULL)
    {
        front = t;
        rear = t;
        return;
    }
    // 3. Traverse
    PNode *tmp = front;
    PNode *prev = NULL;
    while (tmp != NULL && t->priority > tmp->priority)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    // 4. Attach
    if (tmp == NULL)
    {
        rear->next = t;
        rear = t;
    }
    else if (tmp == front)
    {
        t->next = front;
        front = t;
    }
    else
    {
        prev->next = t;
        t->next = tmp;
    }
} // end of enqueue

void PQueue::Dequeue()
{
    if (Empty())
    {
        cout << "Queue Is Empty!!";
        return;
    }
    PNode *tmp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    cout << "Element " << tmp->data << " with priority " << tmp->priority << " successfully dequeued" << endl;
    delete tmp;
} // end of dequeue

void PQueue::Display()
{
    if (Empty())
    {
        cout << "Queue Underflow!";
        return;
    }
    PNode *tmp = front;
    while (tmp != NULL)
    {
        cout << "Data: " << tmp->data << " Priority: " << tmp->priority << "\n";
        tmp = tmp->next;
    }
} // end of display

void PQueue::PeekFront()
{
    if (Empty())
    {
        cout << "Queue is EMPTY!";
        return;
    }
    else
    {
        cout << "DATA: " << front->data << " PRIORITY: " << front->priority;
        return;
    }
} // end of peekfront

void PQueue::PeekRear()
{
    if (Empty())
    {
        cout << "Queue is EMPTY!";
        return;
    }
    else
    {
        cout << "DATA: " << rear->data << " PRIORITY: " << rear->priority;
        return;
    }
} // end of peekrear
// 4. Menu Template

int main()
{
    PQueue P;
    int ch, num, pr;
    while (1)
    {
        system("cls");
        cout << "***Priority Queue***\n\n";
        cout << "1. Enqueue An Element\n";
        cout << "2. Dequeue An Element\n";
        cout << "3. Peek Front\n";
        cout << "4. Peek Rear\n";
        cout << "5. Display All Elements\n";
        cout << "6. Exit\n\n";
        cout << "Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Value to insert:";
            cin >> num;
            cout << "Priority: ";
            cin >> pr;
            P.Enqueue(num, pr);
            getch();
            break;
        case 2:
            P.Dequeue();
            getch();
            break;
        case 3:
            P.PeekFront();
            getch();
            break;
        case 4:
            P.PeekRear();
            getch();
            break;
        case 5:
            P.Display();
            getch();
            break;
        case 6:
            exit(1);
        default:
            cout << "Incorrect Choice!";
            getch();
        }
    }
}


