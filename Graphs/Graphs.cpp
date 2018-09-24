#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <cstdlib>

using namespace std;


unordered_map<int, char> V;
bool E [8][8];
unordered_map<int, list<pair<int, int>>> M;

void ConstructGraph();
void BFS(int s);
void DFS(int s);
void DFS_Util(int v, bool visted[]);


int main()
{
	ConstructGraph();
	DFS(2);
	system("pause");
}

void ConstructGraph()
{
	for(int i = 0; i < 8;i++)
	{
		V.insert(pair<int, char>(i, (char)i + 65));
	} 
	
	int n;
	for(int i = 0; i < 8;i++)
	{
		for(int ii = 0; ii < 8;ii++)
		{	
			E[i][ii] = ((rand() % 10)%2) ? 1 : 0;
			cout << E[i][ii] << " ";
		} cout << endl;
	} cout << endl;
}

void BFS(int s)
{
	bool* visited = new bool[8];
	for(int i = 0; i < 8; i++)
		visited[i] = false;

	queue<int> TraversalQueue;
	TraversalQueue.push(s);
	visited[s] = true;

	while(!TraversalQueue.empty()){
		s = TraversalQueue.front();
		cout << V[s] << " ";
		TraversalQueue.pop();

		for(int i = 0; i < 8;i++){
			if(E[s][i] && !visited[i])
			{
				visited[i] = 1;
				TraversalQueue.push(i);
			}
		}

	}
}

void DFS(int s)
{
	bool* visited = new bool[8];
	for(int i = 0; i < 8; i++)
		visited[i] = false;

	DFS_Util(s, visited);


}

void DFS_Util(int v,bool visited[])
{	
	cout << V[v] << " ";
	visited[v] = true;

	for(int i = 0; i < 8; i++)
	{
		if(!visited[i] && E[v][i])
		{	

			DFS_Util(i, visited);
		}
	}
}


