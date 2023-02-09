#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// https://www.geeksforgeeks.org/graph-coloring-applications/

// this program is used to color an undirected graph
// it also can be used to find max number of colors  to color a graph
// to find bipartit property of a graph
// Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. 

// or
// 1. Color first vertex with first color. 
// 2. Do following for remaining V-1 vertices. 
//  . a) Consider the currently picked vertex and color it with the 
// 		lowest numbered color that has not been used on any previously 
// 		colored vertices adjacent to it. If all previously used colors 
//		appear on vertices adjacent to v, assign a new color to it.


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

int max(int x, int y){
	return x>y ? x : y;
}

// color all vertex by same color then check safe color condition

bool m_coloring(vector<pair < int , int> > graph[], int V, int m){
	int src=0;
	std::vector<int > color(V,1);
	std::vector<bool > visited(V,false);
	int max_color = 1;
	queue < int > q;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i].first;
			if (color[u] == color[v])
			{
				color[v]++;			// increament
			}

			max_color = max(max_color , max(color[u] , color[v]));

			// cout<<max_color<<endl;
			if( max_color > m) return false;

			if (!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
	for (int i = 0; i < V; ++i)
	{
		cout<<color[i]<<" ";
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int V = 5;
	std::vector<pair < int , int> > graph[V];
	int w = 0;

	int m = 3;

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
    
    // for connected graph
    if(m_coloring(graph, V, m)){
    	cout<<"\nit is possible !!!";
    }

	return 0;
}