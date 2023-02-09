#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


// make sure there is no cycle exist in graph  DAG directed acyclic graph
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


void toposortUtilDFS(int curr, vector<pair < int , int> > graph[], std::vector<bool> &visited, stack< int > &result){

	visited[curr] = true;

	for (int i = 0; i < graph[curr].size(); ++i)
	{
		int v = graph[curr][i].first;
		if (!visited[v])
		{
			toposortUtilDFS(v, graph, visited, result);
		}
	}
	result.push(curr);
}

void toposort(vector<pair < int , int> > graph[], int V){
	
	std::vector<bool > visited(V,false);

	stack < int > result;

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
		{
			toposortUtilDFS(i, graph, visited, result);
		}
		
	}
	cout<<endl;
	while(!result.empty())
	{
		cout<<result.top()<<" ";
		result.pop();
	}
	
}

void calInDegree(vector<pair < int , int> > graph[], int V,  std::vector<int> &inDegree){

	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			int v = graph[i][j].first;
			inDegree[v]++;
		}
	}
}

void toposortUtilAllPath(vector<pair < int , int> > graph[], int V, 
	std::vector<bool> &visited, vector< int > &result, std::vector<int> &inDegree){

	
	bool flag = false;

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i]  && inDegree[i] == 0)
		{

			for (int j = 0; j < graph[i].size(); ++j)
			{
				int v = graph[i][j].first;
				inDegree[v]--;
			}
			result.push_back(i);
			visited[i] = true;

			toposortUtilAllPath(graph,V, visited, result, inDegree);

			visited[i] = false;
			
			result.erase(result.end()-1);
			for (int j = 0; j < graph[i].size(); ++j)
			{
				int v = graph[i][j].first;
				inDegree[v]++;
			}
			flag = true;
		}
	}

	if (!flag)
	{
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" , ";
		}
		cout<<"\n\n";
	}
}

void toposortAllPath(vector<pair < int , int> > graph[], int V){
	
	std::vector<bool > visited(V,false);
	std::vector<int > inDegree(V,0);
	calInDegree(graph, V, inDegree);

	cout<<"\ninDegree of each vertices\n";
	for (int i = 0; i < V; ++i)
	{
		cout<<"{ "<<i<<" , "<<inDegree[i]<<" } ";
	}
	cout<<" \n all path \n";
	std::vector<int> result;

	toposortUtilAllPath(graph, V, visited, result, inDegree);
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
    //count_path(graph, V);

    cout<<"\nsingle toposort using recursive function\n";
    toposort(graph, V);
    cout<<"\n all possible topo path\n";
    toposortAllPath(graph, V);

	return 0;
}