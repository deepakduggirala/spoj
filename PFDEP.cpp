/*
	Author: Deepak Duggirala
	Date:	15-08-2015
	Description:Implementation of adjacency list for graphs
*/
#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

class myCompare
{
	public:
	bool operator()(int &l,int &r)
	{
		return l > r;
	}
};

class Graph
{
	int V; //No:of vertices
	list<int> *adj; //Pointer to an array containing adjacency lists
	priority_queue<int, vector<int>, myCompare> source;
	int *indegree;
	public:
		Graph(int V);  //Constructor
    	void addEdge(int v, int w); //function to add an edge to graph
    	void topologicalSort(void);
};


//Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	indegree = new int [V];
	for(int j=0;j<V;j++)
	{
		indegree[j]=0;
	}
	
}

//Add an edge to the graph
void Graph::addEdge(int v,int e)
{
	adj[v].push_back(e); //add edge e to v's list
	indegree[e]++;
}


//Topological Sort
void Graph::topologicalSort(void)
{
	int s;
	for(int j=0;j<V;j++)
	{
		if(indegree[j]==0)
		{
			source.push(j);
		}
	}
	
	while(!source.empty())
	{
		s = source.top();
		cout<<s<<", ";
		source.pop();
		for(list<int>::iterator it=adj[s].begin(); it != adj[s].end(); it++)
		{
			indegree[*it]--;
			if(indegree[*it] == 0)
			{
				source.push(*it);
			}
		}
	}
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	
	Graph g(N);
	
	int a[105];
	int T,k;
	char c;
	c = getchar();
	for(int i=0;i<M;i++)
	{
		int j=0;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			ungetc(c, stdin);
			scanf("%d", &a[j++]);
		}
		T = a[0];
		k = a[1];
		for(int j=0;j<k;k++)
		{
			g.addEdge(a[j+2],T);
		}
	}
	
    g.topologicalSort();
}
