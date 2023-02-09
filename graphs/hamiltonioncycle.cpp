#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// cycle does exist
// each vertex visied once
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

bool firstToLastEdge(vector<pair < int , int> > graph[], int src, int dest){
	for (int i = 0; i < graph[dest].size(); ++i)
	{
		if(src == graph[dest][i].first){
			return true;
		}
	}
	return false;
}

void DFS_Path(int curr, vector<pair < int , int> > graph[], int V, std::vector<bool> visited, std::vector<int> path, int index){
	visited[curr] = true;
	if(index == V) {
		if (firstToLastEdge(graph, path[0], curr))
		{
			for (int i = 0; i < index; ++i)
			{
				cout<<path[i]<<" ";
			}
			cout<<path[0]<<endl;
		}
		
	}
	else {
		for (int i = 0; i < graph[curr].size(); ++i)
		{
			int v = graph[curr][i].first;
			if (!visited[v])
			{
				path[index] = v;
				DFS_Path(v, graph, V, visited, path, index+1);
			}
		}
	}

}

void hamiltonion_path(vector<pair < int , int> > graph[], int V){

	int src=1;
	std::vector<int > path(V,-1);
	std::vector<bool > visited(V,false);
	int index = 0;
	path[index++] = src;
	visited[src] = true;
	DFS_Path(src, graph, V, visited, path, index);
}

int main(int argc, char const *argv[])
{
	int V = 5;
	std::vector<pair < int , int> > graph[V];
	int w = 0;

// directed graph
	addEdge(graph, 0, 1, w); 
    addEdge(graph, 0, 3, w); 
    addEdge(graph, 1, 2, w);
    addEdge(graph, 1, 3, w); 
    addEdge(graph, 1, 4, w); 
    addEdge(graph, 2, 4, w);
    addEdge(graph, 3, 4, w);   // remove this line and check there is not any hamiltonion cycle

    print(graph, V);

// make sure there is no cycle exist in graph
    cout<<"all hamiltonion paths"<<endl;
    hamiltonion_path(graph, V);

	return 0;
}