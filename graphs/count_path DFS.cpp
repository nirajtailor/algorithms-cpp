#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


// make sure there is no cycle exist in graph
// that makes infinite number of path which will create a problem
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
	// graph[dest].push_back(make_pair(src, weight));
}

void DFS_Path(int curr, vector<pair < int , int> > graph[], int dest, int &count, std::vector<int> path, int &index){

	if(curr == dest) {
		count++;
		for (int i = 0; i < index; ++i)
		{
			cout<<path[i]<<" ";
		}
		cout<<" count"<<count<<endl;
	}
	else {
		for (int i = 0; i < graph[curr].size(); ++i)
		{
			int v = graph[curr][i].first;
			path[index] = v;
			index++;
			DFS_Path(v, graph, dest, count, path, index);
			index--;
			// or
			// DFS_Path(v, graph, dest, count, path, index+1);
		}
	}

}

void count_path(vector<pair < int , int> > graph[], int V){
	int count = 0;
	int src=0, dest=4;
	std::vector<int > path(V,-1);
	int index = 0;
	path[index++] = src;
	DFS_Path(src, graph, dest, count, path, index);
	cout<<" index="<<index<<endl;
	cout<<"count Path="<<count<<endl;
}

int main(int argc, char const *argv[])
{
	int V = 5;
	std::vector<pair < int , int> > graph[V];
	int w = 0;

// directed graph
	addEdge(graph, 0, 1, w); 
    addEdge(graph, 0, 2, w); 
    addEdge(graph, 0, 3, w); 
    addEdge(graph, 1, 3, w); 
    addEdge(graph, 1, 4, w); 
    addEdge(graph, 2, 3, w);
    addEdge(graph, 2, 4, w);
    addEdge(graph, 3, 4, w);

    print(graph, V);

// make sure there is no cycle exist in graph
    count_path(graph, V);

	return 0;
}