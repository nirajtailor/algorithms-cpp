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
// adjecency matrix used 
// seems wrong output
/**
 * important point to note
 * removed edge doesn't work correctly in adj list
 * this program is giving wrong output
 * please refer another program
*/
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
	// cout<<"removed "<<u<<" "<<v<<endl;
	print(graph,6);
}

void DFS_EulerPath(int curr, vector<pair < int , int> > graph[], int V, std::vector<int> path, int &index, int &cycleCount){
	// cout<<"curr "<<curr<<endl;
	if (index==11)
	{
		for (int i = 0; i < index; ++i)
		{
			cout<<path[i]<<" ";
		}
		cycleCount++;
		cout<<" ---> "<<cycleCount<<endl;
	}

	else
	for (int i = 0; i < graph[curr].size(); ++i)
	{
		int v = graph[curr][i].first;
		path[index] = v;
		index++;
		removeEdge(graph, curr,v);
		cout<<"removed "<<curr<<" "<<v<<endl;
		DFS_EulerPath(v, graph, V, path, index,cycleCount);
		index--;
		addEdge(graph,curr, v , 0);
		cout<<"added "<<v<<" "<<curr<<endl;
	}
}

void euler(vector<pair < int , int> > graph[], int V){

	int src=0;
	std::vector<int > path(50,-1);
	std::vector<bool > visited(V,false);
	int index = 0;
	int cycleCount = 0;
	path[index] = src;
	index++;
	DFS_EulerPath(src, graph, V, path, index,cycleCount);
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
    cout<<"all euler circuits"<<endl;
    euler(graph, V);
	return 0;
}