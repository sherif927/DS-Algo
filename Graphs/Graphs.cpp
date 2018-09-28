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
void AddEdge(int u, int v, int dist);
void Dijkstra(int src);
int Prim(int src);


int main()
{
	AddEdge(0,1,1);
	AddEdge(0,2,4);
	AddEdge(1,2,1);
	AddEdge(2,3,2);
	AddEdge(0, 3, 7);
	cout << Prim(0) << endl;
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

void AddEdge(int u, int v, int dist)
{
	M[u].push_back(pair<int, int>(v, dist));
}

void Dijkstra(int src)
{
	unordered_map<int, int> dist;

	//Initializing the distances to Infinity
	for(auto j : M)
		dist[j.first] = INT_MAX;

	set<pair<int, int>> s;

	dist[src] = 0;

	s.insert(pair<int, int>(0, src));

	while(!s.empty())
	{
		auto current = *(s.begin());
		
		//The vertex
		int node = current.second;
		//It's Distance from src
		int nodeD = current.first;

		s.erase(s.begin());

		for(auto child : M[node])
		{
			if((nodeD + child.second) < dist[child.first])
			{
				auto n =s.find(make_pair(dist[child.first], child.first));
				if(n != s.end())
					s.erase(n);
				dist[child.first] = nodeD + child.second;
				s.insert(make_pair(dist[child.first], child.first));
			}
		}
	}

	for(auto obj : dist)
	{
		cout << V[obj.second] << " is " << obj.first << " units away from " << V[src] << endl;
	}
}

pair<int,int> GetMin(unordered_map<int,int> map,bool MST[])
{
	pair<int, int> trav = make_pair(INT_MAX, INT_MAX);
	unordered_map<int, int>::iterator i = map.begin();

	for(i; i != map.end();i++)
	{
		if(!MST[i->first] && trav.second < i->second)
			trav = *(i);
	} return trav;
}


int Prim(int src)
{	
	//Flags
	bool MST[8];
	int MST_COUNT = 0;
	unordered_map <int, int> map;
	map[src] = 0;

	for(int i = 1; i < 8; i++)
		map[i] = INT_MAX;
	

	while(MST_COUNT < 8)
	{
		auto current = GetMin(map,MST);
		int node = current.second;
		int key = current.first;
		MST[node] = true;
		MST_COUNT++;

		for(auto child : M[node])
		{
			if(child.second < map[child.first])
			{
				map[child.first] = child.second;

			}
		}
	}

	int sum = 0;
	for(auto obj : map)
		sum += obj.second;

	return sum;
}