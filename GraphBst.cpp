
#include <iostream>
#include <conio.h>
#define MAX 10
using namespace std;
// Queue Template
class Queue
{
	int a[MAX];
	int front, rear;

public:
	Queue()
	{
		front = rear = -1;
	}
	void Enqueue(int x);
	int Dequeue();
	int Empty();
};
int Queue::Empty()
{
	if (front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} // end of empty
void Queue::Enqueue(int x)
{
	rear++;
	a[rear] = x;
	if (front == -1)
	{
		front++;
	}
} // End of enqueue
int Queue ::Dequeue()
{
	if (Empty())
	{
		cout << "Queue Is empty!!";
		return -1;
	}
	int tmp = a[front];
	if (front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front++;
	}
	return tmp;
}
// 1.Node template -NOT REQUIRED(ARRAY USED)
// 2.Array Based Template for Graph
class Graph
{
	int adj[MAX][MAX];
	int visited[MAX];

	int n, e;

public:
	Graph()
	{
		int i, j;
		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				adj[i][j] = 0;
			}
			n = 0;
			e = 0;
		}
	}
	void CreateGraph();
	void Display();
	void BFT(int x);
}; // end of class graph
// 3.Functions
void Graph ::CreateGraph()
{
	cout << "Enter the Number Of Vertices: ";
	cin >> n; // n declared in the Graph Class
	cout << "Enter the Number Of Edges: ";
	cin >> e; // e declared in the graph class
	int source, dest;
	int ne = 1;
	while (ne <= e)
	{
		cout << "Enter Edge " << ne << endl;
		cout << "Enter source vertex: ";
		cin >> source;
		cout << "Enter Destination vertex: ";
		cin >> dest;
		adj[source][dest] = 1;
		adj[dest][source] = 1;
		ne++;
	}
} // end of creategraph
void Graph::Display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
} // end of display
void Graph::BFT(int x)
{
	Queue q;
	int i;
	for (i = 0; i < MAX; i++)
	{
		visited[i] = 0;
	}
	// Update the starting vertex
	visited[x] = 1;
	q.Enqueue(x);
	cout << "Order Of Traversal: ";
	while (!q.Empty())
	{
		x = q.Dequeue();
		cout << x << " ";
		for (i = 0; i < n; i++)
		{
			if (adj[x][i] == 1 && visited[i] == 0) // neighbour And visited status
			{
				visited[i] = 1;
				q.Enqueue(i);
			}
		}
	}
} // end of BFT
// 4.Menu
int main()
{
	int ch, num;
	Graph g;
	while (1)
	{
		system("cls");
		cout << "***Graph-Adjacency matrix && Breadth First Traversal ***\n\n ";
		cout << "1.Create A Graph\n";
		cout << "2.Display the Graph\n";
		cout << "3.Breadth First Traversal\n";
		cout << "4.Exit\n\n";
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			g.CreateGraph();
			getch();
			break;
		case 2:
			g.Display();
			getch();
			break;
		case 3:
			cout << "Enter the starting vertex: ";
			cin >> num;
			g.BFT(num);
			getch();
			break;
		case 4:
			exit(1);
		default:
			cout << "Incorrect Choice!!!";
			getch();
		}
	}
}

