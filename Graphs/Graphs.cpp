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
unordered_map<int, list<int>> adj;
bool MST[4] = {0, 0, 0, 0};
const int COUNT = 4;

void ConstructGraph();
void BFS(int s);
void DFS(int s);
void DFS_Util(int v, bool visted[]);
void TopologicalSort(int src);
void TopologicalSort_Util(int v, bool visited[], stack<int>& stack);
bool IsCyclic();
bool IsCyclicUtil(int v, bool visited[], bool rec[]);
void AddEdge(int u, int v, int dist);
void Dijkstra(int src);
void BFS_Reach(int src);
int Prim(int src);


int main()
{
	AddEdge(0,1,1);
	AddEdge(0,2,4);
	AddEdge(1,2,1);
	AddEdge(2,3,2);
	AddEdge(0, 3, 7);
	BFS_Reach(0);
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

void TopologicalSort(int src)
{	

	stack<int> stack;

	bool* visited = new bool[8];
	for(int i = 0; i < 8; i++)
		visited[i] = false;

	for(int i = 0; i < 8;i++)
		if(!visited[i])
			TopologicalSort_Util(src, visited);

	while(!stack.empty())
	{
		cout << stack.top()<<" ";
		stack.pop();
	}
}

void TopologicalSort_Util(int v,bool visited[],stack<int>& stack)
{
	visited[v] = true;

	for(int child : adj[v])
	{
		if(!visited[child])
			TopologicalSort_Util(child, visited, stack);
	}

	stack.push(v);
}

bool IsCyclic()
{
	bool* visited = new bool[4];
	bool* rec = new bool[4];

	for(int i = 0; i < 4; i++)
	{	
		rec[i] = false;
		visited[i] = false;
	}

	for(int i = 0; i < 4; i++)
		 if(IsCyclicUtil(i,)
		
}

bool IsCyclicUtil(int v,bool visited[],bool rec[])
{
	visited[v] = true;
	rec[v] = true;

	for(auto child : adj[v])
	{
		if(!visited[child])
		{
			return IsCyclicUtil(child,visited,rec);
		}
		else if(rec[child])
		{
			return true;
		}
	}

	rec[v] = false;
	return false;
}

void AddEdge(int u, int v, int dist)
{
	M[u].push_back(pair<int, int>(v, dist));
	adj[u].push_back(v);
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

pair<int,int> GetMin(unordered_map<int,int> map)
{
	pair<int, int> trav = make_pair(INT_MAX, INT_MAX);
	unordered_map<int, int>::iterator i = map.begin();

	for(i; i != map.end();i++)
	{
		if(!MST[i->first] && trav.second > i->second)
			trav = *(i);
	} return trav;
}

int Prim(int src)
{	
	int MST_COUNT = 0;
	unordered_map <int, int> map;
	map[src] = 0;

	for(int i = 1; i < 4; i++)
	{
		map[i] = INT_MAX;
		MST[i] = false;
	}
		
	while(MST_COUNT < 4)
	{
		auto current = GetMin(map);
		int node = current.first;
		int key = current.second;
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

	int sum (0);
	for(auto obj : map)
		sum += obj.second;

	return sum;
}

void BFS_Reach(int src)
{
	int dist[COUNT] = {-1, -1, -1, -1};
	dist[src] = 0;
	
	queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		auto current = q.front();
		q.pop();

		for(auto child:adj[current])
		{	
			//Checking if the node was not visited before
			if(dist[child] == -1)
			{
				q.push(child);
				dist[child] = dist[current] + 1;
			}
		}
	}

	for(int i = 0; i < 4; i++)
		cout << "distance between " << src << " and " << i << " is " << dist[i] << endl;
}