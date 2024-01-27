#include <iostream>
#include <conio.h>
using namespace std;
// 1. Node Template
class BNode
{
public:
    int data;
    BNode *left;
    BNode *right;
};
// 2.List Template
class BST
{
    BNode *root;
    int cnt;

public:
    BST()
    {
        root = NULL;
        cnt = 0;
    }
    void Insert(int x);
    void Search(int x);
    void Display();
    void Inorder(BNode *p);
    void Preorder(BNode *p);
    void Postorder(BNode *p);
    void Count();
    void FindMin();
    void FindMax();
};

// 3.Functions
void BST::Insert(int x)
{
    BNode *t = new BNode;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    if (root == NULL)
    {
        root = t;
        cnt++;
        return;
    }
    BNode *tmp = root;
    BNode *prev = NULL;
    while (tmp != NULL)
    {
        prev = tmp;
        if (t->data < tmp->data)
        {
            tmp = tmp->left;
        }
        else if (t->data > tmp->data)
        {
            tmp = tmp->right;
        }
        else
        {
            cout << "Duplicate Values Are Not Allowed!!";
            getch();
            return;
        }
    }
    if (t->data < prev->data)
    {
        prev->left = t;
    }
    else
    {
        prev->right = t;
    }
    cnt++;
} // end of insert

void BST::Display()
{
    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;
} // end of display

void BST::Inorder(BNode *p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
} // end of inorder

void BST::Preorder(BNode *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
} // end of preorder

void BST::Postorder(BNode *p)
{
    if (p != NULL)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}

void BST::Search(int x)
{
    BNode *tmp = root;
    int flag = 0;
    while (tmp != NULL)
    {
        if (x < tmp->data)
        {
            tmp = tmp->left;
        }
        else if (x > tmp->data)
        {
            tmp = tmp->right;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Element " << x << " found";
    }
    else
    {
        cout << "Element " << x << " not found";
    }
} // end of search

void BST::Count()
{
    cout << "There are " << cnt << " nodes in the tree"; // cnt is declared in BST class
} // end of count

void BST::FindMax()
{
    BNode *tmp = root;
    while (tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    cout << "Maximum Value in BST is: " << tmp->data;
}

void BST::FindMin()
{
    BNode *tmp = root;
    while (tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    cout << "Minimum Value in BST is: " << tmp->data;
}
// 4. Menu
int main()
{
    BST B;
    int ch, num;
    while (1)
    {
        system("cls");
        cout << "***BST***\n\n";
        cout << "1. Insert An Element\n";
        cout << "2. Search An Element\n";
        cout << "3. Display\n";
        cout << "4. Count\n";
        cout << "5. Find Minimum\n";
        cout << "6. Find Maximum\n";
        cout << "7. Exit\n\n";
        cout << "Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Values To Enter: ";
            cin >> num;
            B.Insert(num);
            getch();
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> num;
            B.Search(num);
            getch();
            break;
        case 3:
            B.Display();
            getch();
            break;
        case 4:
            B.Count();
            getch();
            break;
        case 5:
            B.FindMin();
            getch();
            break;
        case 6:
            B.FindMax();
            getch();
            break;
        case 7:
            exit(1);
        default:
            cout << "Incorrect Choice!";
            getch();
        }
    }
}


