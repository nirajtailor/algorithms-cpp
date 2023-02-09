#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

void print(vector < pair<int , int > >  v[], int V){
	for (int i = 0; i < V; ++i)
	{
		cout<<i<<" adj vertices";
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout<<"{ "<<v[i][j].first<<", "<<v[i][j].second<<" } ";
		}
		cout<<endl;
	}
}

void addEdge(vector<pair < int , int> > graph[] , int src , int dest, int weight){

	graph[src].push_back(make_pair(dest, weight));
	// for undirected graph
	graph[dest].push_back(make_pair(src, weight));
}

bool cycleUtilUndirected(int src, int V, vector<pair < int , int> > graph[], std::vector<bool> &visited){
	std::vector<int> parent(V,-1);
	queue<int > q;
	visited[src] = true;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i].first;
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				parent[v] = u;
			}
			else if (v!= parent[u])
				return true;
		}
	}
	return false;
}

bool cycleUtilDirected(int curr, std::vector<bool> &recStack, vector<pair < int , int> > graph[], std::vector<bool> &visited){
	visited[curr] = true;
	recStack[curr] = true;
	cout<<curr<<" "<<endl;
	for (int i = 0; i < graph[curr].size(); ++i)
	{
		int v = graph[curr][i].first;

		if(!visited[v] && cycleUtilDirected(v, recStack, graph, visited)){
			return true;
		}
		else if(recStack[v]) return true;
	}
	recStack[curr] = false;
	return false;

}

void isCycle(vector<pair < int , int> > graph[], int V){

	std::vector<bool> visited(V,false);
	

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i] && cycleUtilUndirected(i, V, graph, visited)){
			cout<<"cyclefound !!!"<<endl;
			return;
		}
	}

	std::vector<bool> recStack(V,false);
	// for (int i = 0; i < V; ++i)
	// {
	// 	if (!visited[i] && cycleUtilDirected(i, recStack, graph, visited)){
	// 		cout<<"cyclefound !!!"<<endl;
	// 		return;
	// 	}
	// }
}

int main(int argc, char const *argv[])
{
	int V = 5;
	std::vector<pair < int , int> > graph[V];
	int w = 0;

// undirected graph
	addEdge(graph, 1, 0, w); 
    addEdge(graph, 0, 2, w); 
    addEdge(graph, 2, 1, w); 
    addEdge(graph, 0, 3, w); 
    addEdge(graph, 3, 4, w); 

// directed graph
	// addEdge(graph, 0, 1, w); 
 //    addEdge(graph, 0, 2, w); 
 //    addEdge(graph, 1, 2, w); 
 //    addEdge(graph, 2, 0, w); 
 //    addEdge(graph, 2, 3, w);
 //    addEdge(graph, 3, 3, w);

    print(graph, V);
    isCycle(graph, V);

	return 0;
}