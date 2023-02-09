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

void createMatrix(std::vector< vector<int> > &matrix, vector<pair < int , int> > graph[] , int V){
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			int u = graph[i][j].first;
			matrix[i][u] = 1;
			matrix[u][i] = 1;
		}
		cout<<endl;
	}

	// 
	cout<<"print matrix"<<endl;
	for (int i = 0; i < V; ++i)
	{
		for( int j =0; j<V; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n\n";
}

void removeEdge(vector<pair < int , int> > graph[], int u, int v){
	for (int i = 0; i < graph[u].size(); ++i)
	{
		if(v == graph[u][i].first){
			graph[u].erase(graph[u].begin() + i);
			break;
		}
	}
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if(u == graph[v][i].first){
			graph[v].erase(graph[v].begin() + i);
			break;
		}
	}
}

void DFS_EulerPath(int curr, std::vector< vector<int> > &matrix, int V, std::vector<int> path, int index, int &edgeCount){
	// cout<<"curr "<<curr<<endl;

	path[index] = curr;
	if (index==10)	// number of edges
	{
		for (int i = 0; i <= index; ++i)
		{
			cout<<path[i]<<" ";
		}
		edgeCount++;
		cout<<"--> "<<edgeCount<<endl;
	}

	for (int i = 0; i < V; ++i)
	{
		if (matrix[curr][i])
		{
		// removeEdge(graph, curr,v);
		// cout<<"removed "<<curr<<" "<<i<<endl;
		matrix[curr][i] = 0;
		matrix[i][curr] = 0;
		DFS_EulerPath(i, matrix, V, path, index+1,edgeCount);
		// addEdge(graph,curr, v , 0);
		matrix[curr][i] = 1;
		matrix[i][curr] = 1;
		// cout<<"added "<<i<<" "<<curr<<endl;
		}
	}
}

void euler(vector<pair < int , int> > graph[], int V){

	int src=0;
	std::vector<int > path(50,-1);
	std::vector<bool > visited(V,false);
	int index = 0;
	std::vector< vector<int> > matrix(V, std::vector<int> (V,0));
    createMatrix(matrix, graph,V);
    int edgeCount = 0;
	DFS_EulerPath(src, matrix, V, path, index,edgeCount);
}

int main(int argc, char const *argv[])
{
	int V = 6;
	std::vector<pair < int , int> > graph[V];
	int w = 0;

// directed graph
	addEdge(graph, 0, 1, w); 
    addEdge(graph, 0, 5, w); 
    addEdge(graph, 1, 2, w);
    addEdge(graph, 1, 4, w); 
    addEdge(graph, 1, 5, w); 
    addEdge(graph, 2, 3, w);
    addEdge(graph, 2, 4, w);
    addEdge(graph, 2, 5, w);
    addEdge(graph, 3, 4, w); 
    addEdge(graph, 4, 5, w);  // remove this line and check there is not any hamiltonion cycle

    print(graph, V);

// make sure there is no cycle exist in graph
    cout<<"all euler circuits \n\n important point to note\n\n\n use matrix instead of adjecency list\n\n"<<endl;
    euler(graph, V);
	return 0;
}