#include<iostream>
#include<conio.h>

#define MAX 10
#define INF 999

using namespace std;

/* 1. Node Template - NOT REQUIRED */

/* 2. Array-Based Graph Template */
class Graph
{
	int mat[MAX][MAX];
	int parent[MAX];
	int n,e;
	
	public:
			Graph()
			{
				int i,j;
				
				for(i=0; i<MAX ; i++)
				{
					for(j=0 ; j<MAX ; j++)
					{
						mat[i][j] = INF;
					}
				}
				
				for(i=0 ; i<MAX ; i++)
				{
					parent[i] = -1;
				}
				
				n=0;
				e=0;
			}
			
			void CreateGraph();
			void Display();
			void Kruskal();
			int Find(int i);
			int Union(int i,int j);
};

/* 3. Function */
void Graph::CreateGraph()
{
	int i,source,dest,weight;
	
	cout<<"Enter the number of vertices: ";
	cin >> n; //n is declared in the Graph class.
	
	cout<<"Enter the number of edges: ";
	cin >> e; //e is declared in the Graph class.
	
	for(i=1 ; i<=e ; i++)
	{
		cout<<"Enter edge : " <<i<<endl;
		cout<<"Enter source vertex: ";
		cin >> source;
		cout<<"Enter destination vertex: ";
		cin >> dest;
		cout << "Enter weight: ";
		cin >> weight;
		
		
		mat[source][dest] = weight;
		mat[dest][source] = weight;
	}
}//end of create graph

void Graph::Display()
{
	int i,j;
	
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			cout<< mat[i][j]<<"   ";
		}//end of j
		cout<<endl;
	}//end of i
}//end of display

void Graph::Kruskal()
{
	int minimum, i, j, ne=1;
	int a,b,u,v;
	int mincost = 0;
	
	while(ne<n)
	{
		for(i=0,minimum=999 ; i<n ;i++)
		{
			for(j=0 ; j<n ;j++)
			{
				if(mat[i][j] < minimum)
				{
					minimum = mat[i][j];
					a = u = i;
					b = v = j;
				}//end of if
			}//end of for j
		}//end of for i
		
		u = Find(u);
		v = Find(v);
		
		if(Union(u,v))
		{
			cout << "Edge: " << ne++ <<" (" << a << "," << b << ") = "<<mat[a][b]<<"\n"; 
			mincost += minimum; 
		}//end of if
		
		mat[a][b] = mat[b][a] = INF;
	}//end of while
	
	cout<<"MST Minimum Cost: "<<mincost;
	
}//end of kruskal

int Graph::Find(int i)
{
	while(parent[i]!=-1)
	{
		i = parent[i];
	}
	return i;
}//end of find

int Graph::Union(int i, int j)
{
	if(i!=j)
	{
		parent[j] = i;
		return 1;
	}
}//end of union

/* 4. Menu */
int main()
{
	Graph g;
	int ch;
	
	while(1)
	{
		system("cls");
		
		cout<<"*** Graphs - MST ***\n\n";
		
		cout<<"1. Create a graph\n";
		cout<<"2. Display the graph\n";
		cout<<"3. MST using Kruskal's Algorithm\n";
		cout<<"4. Exit\n\n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
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
				g.Kruskal();
				getch();
				break;
				
			case 4:
				exit(1);
				
			default:
				cout<<"Invalid Choice!";
				getch();
		}//end of switch
	}//end of while
}//end of main


