#include<iostream>
#include<conio.h>

#define MAX 10

using namespace std;

/* 1. Node Template - NOT REQUIRED */

/* 2. Array-Based Graph Template */
class Graph
{
	int mat[MAX][MAX];
	int n,e;
	
	public:
			Graph()
			{
				for(int i=0; i<MAX ; i++)
				{
					for(int j=0 ; j<MAX ; j++)
					{
						mat[i][j] = 0;
					}
				}
				n=0;
				e=0;
			}
			
			void CreateGraph();
			void Display();
};

/* 3. Function */
void Graph::CreateGraph()
{
	int i,source,dest;
	
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
		
		
		mat[source][dest] = 1;
		mat[dest][source] = 1;
	}
}//end of create graph

void Graph::Display()
{
	int i,j;
	
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			cout<< mat[i][j]<<" ";
		}//end of j
		cout<<endl;
	}//end of i
}//end of display
/* 4. Menu */
int main()
{
	Graph g;
	int ch;
	
	while(1)
	{
		system("cls");
		
		cout<<"*** Graphs ***\n\n";
		
		cout<<"1. Create a graph\n";
		cout<<"2. Display the graph\n";
		cout<<"3. Exit\n\n";
		
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
				exit(1);
				
			default:
				cout<<"Invalid Choice!";
				getch();
		}//end of switch
	}//end of while
}//end of main

